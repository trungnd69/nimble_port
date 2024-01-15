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


#ifndef NIMBLE_HOST_BNS_CONFIG_H_
#define NIMBLE_HOST_BNS_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> Battery Service Configurations

// <o BLE_SVC_BAS_SYSINIT_STAGE> Sysinit stage for the battery level service.
// <i> Default: 303
// <i> Sysinit stage for the battery level service.
#define BLE_SVC_BAS_SYSINIT_STAGE    303


// <o BLE_SVC_BAS_BATTERY_LEVEL_READ_PERM> Permissions for reading "Battery Level"
// <i> Default: 0
// <i> Defines permissions for reading "Battery Level" characteristics. Can
// <i> be zero to allow read without extra permissions or combination of:
// <i>    BLE_GATT_CHR_F_READ_ENC
// <i>    BLE_GATT_CHR_F_READ_AUTHEN
// <i>    BLE_GATT_CHR_F_READ_AUTHOR
#define BLE_SVC_BAS_BATTERY_LEVEL_READ_PERM    0

// <o BLE_SVC_BAS_BATTERY_LEVEL_NOTIFY_ENABLE> Battery Notification
// <i> Default: 1
// <i> Set to 1 to support notification or 0 to disable it.
#define BLE_SVC_BAS_BATTERY_LEVEL_NOTIFY_ENABLE    1

// </h>

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
