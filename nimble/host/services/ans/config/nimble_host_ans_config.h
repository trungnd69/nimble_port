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


#ifndef NIMBLE_HOST_ANS_CONFIG_H_
#define NIMBLE_HOST_ANS_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> Alert Notification Service Server Configurations

// <o BLE_SVC_ANS_SYSINIT_STAGE> Sysinit stage for the alert notification service.
// <i> Default: 303
// <i> Sysinit stage for the alert notification service.
#define BLE_SVC_ANS_SYSINIT_STAGE    303


// <o BLE_SVC_ANS_NEW_ALERT_CAT> Initial supported new alert category bitmask.
// <i> Default: 0
// <i> Initial supported new alert category bitmask.
#define BLE_SVC_ANS_NEW_ALERT_CAT    0

// <o BLE_SVC_ANS_UNR_ALERT_CAT> Initial supported unread alert category bitmask.
// <i> Default: 0
// <i> Initial supported unread alert category bitmask.
#define BLE_SVC_ANS_UNR_ALERT_CAT    0

// </h>

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
