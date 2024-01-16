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


#ifndef NIMBLE_HOST_BLEUART_CONFIG_H_
#define NIMBLE_HOST_BLEUART_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> Alert Notification Service Server Configurations

// <o BLEUART_SYSINIT_STAGE> Sysinit stage for the BLE UART service.
// <i> Default: 500
// <i> Sysinit stage for the BLE UART service.
#define BLEUART_SYSINIT_STAGE    500


// <o BLEUART_MAX_INPUT> Number of lines that can be received over UART
// <i> Default: 120
// <i> The size of the largest line that can be received over the UART service.
#define BLEUART_MAX_INPUT    120

// </h>

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
