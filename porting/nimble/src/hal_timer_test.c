#include "os/os.h"
#include "em_timer.h"
#include "hal/hal_timer.h"
#include "os/os_trace_api.h"
#include "os/queue.h"
#include <stdbool.h>
#include "sl_malloc.h"
#include "em_cmu.h"
#include <string.h>

/* IRQ prototype */
typedef void (*hal_timer_irq_handler_t)(void);

#define TIMER_GET(num)  TIMER##num

typedef struct {
    TIMER_TypeDef *timer;
    bool enable;

    TAILQ_ENTRY(hw_timer_list_t) entries;
} hw_timer_list_t;

typedef hw_timer_list_t *hw_timer_list_p;

static TAILQ_HEAD(timer_head, hw_timer_list_t) hw_timer_list_head;

//***************************************************
//********************PROTOTYPES*********************
//***************************************************

void hal_timer_component_init(void) {
    TAILQ_INIT(&hw_timer_list_head);
}

/**
 * Initialize a HW timer.
 *
 * @param timer_num The number of the HW timer to initialize
 * @param cfg       Hardware specific timer configuration.  This is
 *                  passed from BSP directly to the MCU specific driver.
 */
int hal_timer_init(int timer_num, void *cfg) {
    // If the TIMER is in the list, it was once initialized
    hw_timer_list_p var;
    TAILQ_FOREACH(var, &hw_timer_list_head, entries) {
        if ((TIMER_TypeDef *) TIMER_GET(timer_num) == var->timer) {
            var->enable = true;

            return 0;
        } else {
            // Nothing here
        }
    }

    // If the TIMER was never initialized
    TIMER_Init_TypeDef default_timer_config;
    if ((TIMER_Init_Typedef *) cfg == NULL) {
        default_timer_config = TIMER_INIT_DEFAULT;
        default_timer_config.enable = false;
    } else {
        memcpy(&default_timer_config, (TIMER_Init_TypeDef *) cfg, sizeof(TIMER_Init_TypeDef));
    }
    
    TIMER_Init(TIMER_GET(timer_num), &default_timer_config);
    TIMER_IntClear(TIMER_GET(timer_num), 0xFFFFFFFFUL);

    hw_timer_list_p new_member = NULL;
    new_member = (hw_timer_list_p) sl_malloc(sizeof(hw_timer_list_t));
    new_member->timer = TIMER_GET(timer_num);
    new_member->enable = true;

    TAILQ_INSERT_TAIL(&hw_timer_list_head, new_member, entries);
    return 0;
}

/**
 * Un-initialize a HW timer.
 *
 * @param timer_num The number of the HW timer to un-initialize
 */
int hal_timer_deinit(int timer_num) {
    if (!TIMER_REF_VALID(GET_TIMER(timer_num))) {
        return 1;
    } else {

    }

    // Just simply set the enable member to false
    hw_timer_list_p var = NULL;
    TAILQ_FOREACH(var, &hw_timer_list_head, entries) {
        if (var->timer == (TIMER_TypeDef *) TIMER_GET(timer_num)) {
            var->enable = false;
            
            return 0;
        }
    }

    return 1; // ERROR, no timer with the corresponding number
}

/**
 * Config a HW timer at the given frequency and start it. If the exact
 * frequency is not obtainable the closest obtainable frequency is set.
 *
 * @param timer_num The number of the HW timer to configure
 * @param freq_hz   The frequency in Hz to configure the timer at
 *
 * @return 0 on success, non-zero error code on failure
 */
int hal_timer_config(int timer_num, uint32_t freq_hz) {
    // Get the current Frequency of the Clock
    uint32_t clockFreq = CMU_ClockFreqGet(cmuClock_HFPER);

    // Calculate the nearest PreScaler value to archive the desired freq
    uint16_t prescaler = (clockFreq / freq_hz) - 1;

    TIMER_Init_TypeDef new_config = TIMER_INIT_DEFAULT;
    new_config.prescale = prescaler;
    new_config.en = false;

    return hal_timer_init(timer_num, &new_config);
}

/**
 * Returns the resolution of the HW timer. NOTE: the frequency may not be
 * obtainable so the caller can use this to determine the resolution.
 * Returns resolution in nanoseconds. A return value of 0 indicates an invalid
 * timer was used.
 *
 * @param timer_num The number of the HW timer to get resolution for
 *
 * @return The resolution of the timer
 */
uint32_t hal_timer_get_resolution(int timer_num) {
    TIMER_TypeDef *timer = NULL;
    if (!TIMER_REF_VALID(TIMER_GET(timer_num))) {
        return 0;
    } else {
        timer = TIMER_GET(timer_num);
    }

    uint32_t timer_freq = CMU_ClockFreqGet(cmuClock_HFPER) / (((timer->CFG >> _TIMER_CFG_PRESC_SHIFT) & 0xFF) + 1);

    return 1000000000 / timer_freq;
}

/**
 * Returns the HW timer current tick value
 *
 * @param timer_num The HW timer to read the tick value from
 *
 * @return The current tick value
 */
uint32_t hal_timer_read(int timer_num) {
    if (!TIMER_REF_VALID(TIMER_GET(timer_num))) {
        return 0;
    } else {
        return TIMER_CounterGet(TIMER_GET(timer_num));
    }

    return 0;
}

/**
 * Perform a blocking delay for a number of ticks.
 *
 * @param timer_num The timer number to use for the blocking delay
 * @param ticks The number of ticks to delay for
 *
 * @return 0 on success, non-zero error code on failure
 * @return 1 if the TIMER number is not valid
 * @return 2 if the hardware timer not initialized
 */
int hal_timer_delay(int timer_num, uint32_t ticks) {
    hw_timer_list_p var = NULL;
    if (!TIMER_REF_VALID(TIMER_GET(timer_num))) {
        return 1;
    } else {
        TAILQ_FOREACH(var, &hw_timer_list_head, entries) {
            if (var->timer == TIMER_GET(timer_num)
                && var->enable == true) {
                break;
            } else {
                return 2;
            }
        }
    }

    TIMER_TypeDef *timer = TIMER_GET(timer_num);

    // Stop the timer (might not need to do this)
    timer->CMD |= 1 << 1;
    // Restart the counter reg
    timer->CNT = 0;
    // Start it again
    timer->CMD |= 1 << 0;

    while (timer->CNT < ticks) {
        // Just stay there till the CNT reaches the desired ticks
    }

    // Stop the timer
    timer->CMD |= 1 << 1;
    // Restart the counter reg
    timer->CNT = 0;

    return 0;
}

int hal_timer_set_cb(int timer_num, struct hal_timer *tmr, hal_timer_cb cb_func,
                     void *arg);

/**
 * Start a timer that will expire in 'ticks' ticks. Ticks cannot be 0
 *
 * @param tmr   The timer to start
 * @param ticks The number of ticks to expire the timer in
 *
 * @return 0 on success, non-zero error code on failure.
 */