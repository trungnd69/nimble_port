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


#ifndef NIMBLE_HOST_GAP_CONFIG_H_
#define NIMBLE_HOST_GAP_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> GAP Service Configurations

// <o BLE_SVC_GAP_SYSINIT_STAGE> Sysinit stage for the alert notification service.
// <i> Default: 301
// <i> Sysinit stage for the alert notification service.
#define BLE_SVC_GAP_SYSINIT_STAGE    301

// <o BLE_SVC_GAP_DEVICE_NAME> Default value for "Device Name" characteristics
// <i> Default: "nimble"
// <i> Default value for "Device Name" characteristics, unless overwritten by application.
#define BLE_SVC_GAP_DEVICE_NAME   "nimble"

// <o BLE_SVC_GAP_DEVICE_NAME_WRITE_PERM> Default permissions for writing "Device Name" characteristics
// <i> Default: -1
// <i> Defines default permissions for reading characteristics. Can be
// <i> zero to allow read without extra permissions or combination of:
// <i>    BLE_GATT_CHR_F_READ_ENC
// <i>    BLE_GATT_CHR_F_READ_AUTHEN
// <i>    BLE_GATT_CHR_F_READ_AUTHOR
// <i> Set to '-1' to remove this characteristic.
#define BLE_SVC_GAP_DEVICE_NAME_WRITE_PERM    -1

// <o BLE_SVC_GAP_DEVICE_NAME_MAX_LENGTH> Maximum length for "Device Name" characteristics
// <i> Default: 31
// <i> Maximum length for "Device Name" characteristics
#define BLE_SVC_GAP_DEVICE_NAME_MAX_LENGTH    31

// <o BLE_SVC_GAP_APPEARANCE> Device appearance
// <i> Default: 0
#define BLE_SVC_GAP_APPEARANCE    0

// <o BLE_SVC_GAP_APPEARANCE_WRITE_PERM> Default permissions for writing "Appearance" characteristics
// <i> Default: -1
// <i> Defines default permissions for reading characteristics. Can be
// <i> zero to allow read without extra permissions or combination of:
// <i>    BLE_GATT_CHR_F_READ_ENC
// <i>    BLE_GATT_CHR_F_READ_AUTHEN
// <i>    BLE_GATT_CHR_F_READ_AUTHOR
// <i> Set to '-1' to remove this characteristic.
#define BLE_SVC_GAP_APPEARANCE_WRITE_PERM    -1

// <o BLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL> Value of "minimum connection interval" of PPCP characteristic
// <i> Default: 0
// <i> Value of "minimum connection interval" of PPCP characteristic as
// <i> defined by Core specification 5.0, Vol 3, Part C, section 12.3.
#define BLE_SVC_GAP_PPCP_MIN_CONN_INTERVAL    0

// <o BLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL> Value of "maximum connection interval" of PPCP characteristic
// <i> Default: 0
// <i> Value of "maximum connection interval" of PPCP characteristic as
// <i> defined by Core specification 5.0, Vol 3, Part C, section 12.3.
#define BLE_SVC_GAP_PPCP_MAX_CONN_INTERVAL    0

// <o BLE_SVC_GAP_PPCP_SLAVE_LATENCY> Value of "slave latency" of PPCP characteristic
// <i> Default: 0
// <i> Value of "slave latency" of PPCP characteristic as
// <i> defined by Core specification 5.0, Vol 3, Part C, section 12.3.
#define BLE_SVC_GAP_PPCP_SLAVE_LATENCY    0

// <o BLE_SVC_GAP_PPCP_SUPERVISION_TMO> Value of "connection supervision timeout multiplier" of PPCP characteristic
// <i> Default: 0
// <i> Value of "connection supervision timeout multiplier" of PPCP characteristic as
// <i> defined by Core specification 5.0, Vol 3, Part C, section 12.3.
#define BLE_SVC_GAP_PPCP_SUPERVISION_TMO    0

// <o BLE_SVC_GAP_CENTRAL_ADDRESS_RESOLUTION> Value of "Central Address Resolution" of PPCP characteristic
// <i> Default: 0
// <i> Value of "Central Address Resolution" of PPCP characteristic as
// <i> defined by Core specification 5.0, Vol 3, Part C, section 12.3.
#define BLE_SVC_GAP_CENTRAL_ADDRESS_RESOLUTION    0

// </h>

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
