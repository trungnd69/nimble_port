/***************************************************************************//**
 * @brief NimBLE Port configuration header.
 *\n*******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/


#ifndef NIMBLE_TRANSPORT_CONFIG_H_
#define NIMBLE_TRANSPORT_CONFIG_H_


// <<< Use Configuration Wizard in Context Menu >>>

// <h> NimBLE Transport Debug Configurations
// <q BLE_TRANSPORT_ACL_COUNT> Number of ACL buffers available in transport
// <i> Default: 10
// <i> Number of ACL buffers available in transport. This determines
// <i> number of buffers used by host/controller for flow control.
// <i> Buffers pool is allocated for each non-native transport side
// <i> selected, unless overriden by BLE_TRANSPORT_ACL_FROM_[HS|LL]_COUNT.
#define BLE_TRANSPORT_ACL_COUNT    10

// <q BLE_TRANSPORT_ACL_SIZE> Size of each buffer in ACL pool.
// <i> Default: 251
// <i> Size of each buffer in ACL pool.
#define BLE_TRANSPORT_ACL_SIZE    251

// <q BLE_TRANSPORT_ISO_COUNT> Number of ISO buffers available in transport.
// <i> Default: 10
// <i> Number of ISO buffers available in transport. This determines
// <i> number of buffers used by host/controller for flow control.
// <i> Buffers pool is allocated for each non-native transport side
// <i> selected, unless overriden by BLE_TRANSPORT_ISO_FROM_[HS|LL]_COUNT.
#define BLE_TRANSPORT_ISO_COUNT    10

// <q BLE_TRANSPORT_ISO_SIZE> Size of each buffer in ISO pool.
// <i> Default: 300
// <i> Size of each buffer in ISO pool.
#define BLE_TRANSPORT_ISO_SIZE    300

// <q BLE_TRANSPORT_EVT_COUNT> Number of event buffers available in transport.
// <i> Default: 4
// <i> Number of event buffers available in transport.
#define BLE_TRANSPORT_EVT_COUNT    4

// <q BLE_TRANSPORT_EVT_DISCARDABLE_COUNT> Number of discardable event buffers available in transport
// <i> Default: 16
// <i> Number of discardable event buffers available in transport.
// <i> Discardable event buffers are used for events that can be safely
// <i> dropped by controller if there's no free buffer available, e.g.
// <i> advertising reports.
#define BLE_TRANSPORT_EVT_DISCARDABLE_COUNT    16

// <q BLE_TRANSPORT_EVT_SIZE> Size of each buffer in events pool.
// <i> Default: 70
// <i> Size of each buffer in events pool. This applies to both regular
// <i> and discardable buffers. Value is automatically adjusted if
// <i> extended advertising is enabled so in most cases it's better to
// <i> leave it at default settings.
#define BLE_TRANSPORT_EVT_SIZE    70

// <q BLE_TRANSPORT_ACL_FROM_HS_COUNT> Overrides BLE_TRANSPORT_ACL_COUNT on host side
// <i> Default: MYNEWT_VAL(BLE_TRANSPORT_ACL_COUNT)
// <i> Overrides BLE_TRANSPORT_ACL_COUNT on host side, i.e. number
// <i> of ACL buffers available for host.
#define BLE_TRANSPORT_ACL_FROM_HS_COUNT    MYNEWT_VAL(BLE_TRANSPORT_ACL_COUNT)

// <q BLE_TRANSPORT_ACL_FROM_LL_COUNT> Overrides BLE_TRANSPORT_ACL_COUNT on controller side
// <i> Default: MYNEWT_VAL(BLE_TRANSPORT_ACL_COUNT)
// <i> Overrides BLE_TRANSPORT_ACL_COUNT on controller side, i.e. number
// <i> of ACL buffers available for controller.
#define BLE_TRANSPORT_ACL_FROM_LL_COUNT    MYNEWT_VAL(BLE_TRANSPORT_ACL_COUNT)

// <q BLE_TRANSPORT_ISO_FROM_HS_COUNT> Overrides BLE_TRANSPORT_ISO_COUNT on host side
// <i> Default: MYNEWT_VAL(BLE_TRANSPORT_ISO_COUNT)
// <i> Overrides BLE_TRANSPORT_ISO_COUNT on host side, i.e. number
// <i> of ACL buffers available for host.
#define BLE_TRANSPORT_ISO_FROM_HS_COUNT    MYNEWT_VAL(BLE_TRANSPORT_ISO_COUNT)

// <q BLE_TRANSPORT_ISO_FROM_LL_COUNT> Overrides BLE_TRANSPORT_ISO_COUNT on controller side
// <i> Default: MYNEWT_VAL(BLE_TRANSPORT_ISO_COUNT)
// <i> Overrides BLE_TRANSPORT_ISO_COUNT on controller side, i.e. number
// <i> of ACL buffers available for controller.
#define BLE_TRANSPORT_ISO_FROM_LL_COUNT    MYNEWT_VAL(BLE_TRANSPORT_ISO_COUNT)
// </h>

// <h> SYSCFG MONITOR
// <q BLE_MONITOR_UART> Enables monitor interface over UART
// <i> Default: 0
// <i> Enables monitor interface over UART
#define BLE_MONITOR_UART    0

// <s BLE_MONITOR_UART_DEV> Monitor interface UART device
// <i> Default: "uart0"
// <i> Enables monitor interface over UART
#define BLE_MONITOR_UART_DEV    "uart0"

// <o BLE_MONITOR_UART_BAUDRATE> Baudrate for monitor interface UART
// <i> Default: 1000000
// <i> Enables monitor interface over UART
#define BLE_MONITOR_UART_BAUDRATE    1000000

// <o BLE_MONITOR_UART_BUFFER_SIZE> Monitor interface ringbuffer size for UART.
// <i> Default: 64
// <i> Monitor interface ringbuffer size for UART.
// <i> This value should be a power of 2.
#define BLE_MONITOR_UART_BUFFER_SIZE    64

// <q BLE_MONITOR_RTT> Enables monitor interface over RTT
// <i> Default: 0
// <i> Enables monitor interface over RTT
#define BLE_MONITOR_RTT    0

// <s BLE_MONITOR_RTT_BUFFER_NAME> Monitor interface upstream buffer name
// <i> Default: "btmonitor"
// <i> Monitor interface upstream buffer name
#define BLE_MONITOR_RTT_BUFFER_NAME    "btmonitor"

// <o BLE_MONITOR_RTT_BUFFER_SIZE> Monitor interface upstream buffer size
// <i> Default: 256
// <i> Enables monitor interface over UART
#define BLE_MONITOR_RTT_BUFFER_SIZE    256

// <o BLE_MONITOR_CONSOLE_BUFFER_SIZE> Size of internal buffer for console output
// <i> Default: 128
// <i> Size of internal buffer for console output. Any line exceeding this
// <i> length value will be split.
#define BLE_MONITOR_CONSOLE_BUFFER_SIZE    128

// <q BLE_MONITOR_RTT_BUFFERED> Enables buffering when using monitor interface over RTT
// <i> Default: 1
// <i> Enables buffering when using monitor interface over RTT. The data
// <i> are written to RTT once complete packet is created in intermediate
// <i> buffer. This allows to skip complete packet if there is not enough
// <i> space in RTT buffer (e.g. there is no reader connected). If disabled,
// <i> monitor will simply block waiting for RTT to free space in buffer.
#define BLE_MONITOR_RTT_BUFFERED    1
// </h>

// TODO: All of this configurations are not used in the source code
//       of the UART_LL components, It current use the configs from the UART
//       Considering modifying the source code if unable to build.
// <h> UART_LL Configs
// <o BLE_TRANSPORT_UART_LL_PORT> UART index to use for HCI interface
// <i> Default: 0
// <i> UART index to use for HCI interface
#define BLE_TRANSPORT_UART_LL_PORT    0

// <o BLE_TRANSPORT_UART_LL_BAUDRATE> Baudrate on UART
// <i> Default: 1000000
// <i> Baudrate on UART
#define BLE_TRANSPORT_UART_LL_BAUDRATE    1000000

// <o BLE_TRANSPORT_UART_LL_DATA_BITS> Number of data bits on UART
// <i> Default: 8
// <i> Number of data bits on UART
#define BLE_TRANSPORT_UART_LL_DATA_BITS    8

// <o BLE_TRANSPORT_UART_LL_STOP_BITS> Number of stop bits on UART
// <i> Default: 1
// <i> Number of stop bits on UART
#define BLE_TRANSPORT_UART_LL_STOP_BITS    1

// <o BLE_TRANSPORT_UART_LL_PARITY> Parity on UART
// <None=> 0
// <Even=> 1
// <Odd=> 2
// <i> Default: None
// <i> Parity on UART
#define BLE_TRANSPORT_UART_LL_PARITY    0

// <o BLE_TRANSPORT_UART_LL_FLOW_CONTROL> Flow control on UART
// <Off=> 0
// <RTS/CTS=> 1
// <i> Default: RTS/CTS
// <i> Flow control on UART
#define BLE_TRANSPORT_UART_LL_FLOW_CONTROL    0
// </h>

#if (BLE_TRANSPORT_UART_LL_PARITY == 0)
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__none 1
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__even 0
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__odd 0
#elif (BLE_TRANSPORT_UART_LL_PARITY == 1)
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__none 0
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__even 1
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__odd 0
#else
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__none 0
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__even 0
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_PARITY__odd 1
#endif

#if (BLE_TRANSPORT_UART_LL_FLOW_CONTROL == 0)
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_FLOW_CONTROL__off 1
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_FLOW_CONTROL__rtscts 0
#else
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_FLOW_CONTROL__off 0
#define MYNEWT_VAL_BLE_TRANSPORT_UART_LL_FLOW_CONTROL__rtscts 1
#endif

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
