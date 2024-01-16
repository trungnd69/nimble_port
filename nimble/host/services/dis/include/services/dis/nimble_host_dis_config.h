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


#ifndef NIMBLE_HOST_DIS_CONFIG_H_
#define NIMBLE_HOST_DIS_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> Device Information Service Implementation Configurations

// <o BLE_SVC_DIS_SYSINIT_STAGE> Sysinit stage for the device information BLE service.
// <i> Default: 303
// <i> Sysinit stage for the device information BLE service.
#define BLE_SVC_DIS_SYSINIT_STAGE    303


// <o BLE_SVC_DIS_DEFAULT_READ_PERM> Default permissions for reading characteristics
// <i> Default: -1
// <i> Defines default permissions for reading characteristics. Can be
// <i> zero to allow read without extra permissions or combination of:
// <i>    BLE_GATT_CHR_F_READ_ENC
// <i>    BLE_GATT_CHR_F_READ_AUTHEN
// <i>    BLE_GATT_CHR_F_READ_AUTHOR
// <i> Set to '-1' to remove this characteristic.
#define BLE_SVC_DIS_DEFAULT_READ_PERM    -1

// <o BLE_SVC_DIS_MODEL_NUMBER_READ_PERM> Defines permissions for reading "Model Number" characteristics
// <i> Default: 0
// <i> Defines permissions for reading "Model Number" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_MODEL_NUMBER_READ_PERM    0

// <o BLE_SVC_DIS_MODEL_NUMBER_DEFAULT> Default value for "Model number"
// <i> Default: "Apache Mynewt NimBLE"
// <i> Defines a default value for "Model number" if not set with
// <i> 'ble_svc_dis_model_number_set'.
#define BLE_SVC_DIS_MODEL_NUMBER_DEFAULT    "Apache Mynewt NimBLE"

// <o BLE_SVC_DIS_SERIAL_NUMBER_READ_PERM> Permissions for reading "Serial Number" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "Serial Number" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_SERIAL_NUMBER_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_SERIAL_NUMBER_DEFAULT> Default value for "Serial number"
// <i> Default: 0
// <i> Defines a default value for "Serial number" if not set with
// <i> 'ble_svc_dis_serial_number_set'.
#define BLE_SVC_DIS_SERIAL_NUMBER_DEFAULT    0

// <o BLE_SVC_DIS_HARDWARE_REVISION_READ_PERM> Permissions for reading "Hardware Revision" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "Hardware Revision" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_HARDWARE_REVISION_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_HARDWARE_REVISION_DEFAULT> Default value for "Hardware Revision"
// <i> Default: 0
// <i> Defines a default value for "Hardware Revision" if not set with
// <i> 'ble_svc_dis_serial_number_set'.
#define BLE_SVC_DIS_HARDWARE_REVISION_DEFAULT    0

// <o BLE_SVC_DIS_FIRMWARE_REVISION_READ_PERM> Permissions for reading "Firmware Revision" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "Firmware Revision" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_FIRMWARE_REVISION_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_FIRMWARE_REVISION_DEFAULT> Default value for "Firmware Revision"
// <i> Default: 0
// <i> Defines a default value for "Firmware Revision" if not set with
// <i> 'ble_svc_dis_hardware_revision_set'.
#define BLE_SVC_DIS_FIRMWARE_REVISION_DEFAULT    0

// <o BLE_SVC_DIS_SOFTWARE_REVISION_READ_PERM> Permissions for reading "Software Revision" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "Software Revision" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_SOFTWARE_REVISION_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_SOFTWARE_REVISION_DEFAULT> Default value for "Software Revision"
// <i> Default: 0
// <i> Defines a default value for "Software Revision" if not set with
// <i> 'ble_svc_dis_firmware_revision_set'.
#define BLE_SVC_DIS_SOFTWARE_REVISION_DEFAULT    0

// <o BLE_SVC_DIS_MANUFACTURER_NAME_READ_PERM> Permissions for reading "Manufacturer name" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "Manufacturer name" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_MANUFACTURER_NAME_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_MANUFACTURER_NAME_DEFAULT> Default value for "Manufacturer name"
// <i> Default: 0
// <i> Defines a default value for "Manufacturer name" if not set with
// <i> 'ble_svc_dis_manufacturer_name_set'.
#define BLE_SVC_DIS_MANUFACTURER_NAME_DEFAULT    0

// <o BLE_SVC_DIS_SYSTEM_ID_READ_PERM> Permissions for reading "System ID" characteristics
// <i> Default: BLE_SVC_DIS_DEFAULT_READ_PERM
// <i> Defines permissions for reading "System ID" characteristics.
// <i> Can be set to BLE_SVC_DIS_DEFAULT_READ_PERM or use any of the
// <i> possible values defined for that setting.
#define BLE_SVC_DIS_SYSTEM_ID_READ_PERM    BLE_SVC_DIS_DEFAULT_READ_PERM

// <o BLE_SVC_DIS_SYSTEM_ID_DEFAULT> Default value for "System ID"
// <i> Default: 0
// <i> Defines a default value for "System ID" if not set with
// <i> 'ble_svc_dis_serial_number_set'.
#define BLE_SVC_DIS_SYSTEM_ID_DEFAULT    0

// </h>

// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
