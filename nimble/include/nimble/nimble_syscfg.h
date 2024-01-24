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


#ifndef NIMBLE_CONFIG_H_
#define NIMBLE_CONFIG_H_

// <<< Use Configuration Wizard in Context Menu >>>
// <h> NimBLE stack Configurations

// <q BLE_ROLE_CENTRAL> Enables the Central bluetooth role
// <i> Default: 1
// <i> Enables the Central bluetooth role
#define BLE_ROLE_CENTRAL    1

// <q BLE_ROLE_PERIPHERAL> Enables the Peripheral bluetooth role
// <i> Default: 1
// <i> Enables the Peripheral bluetooth role
#define BLE_ROLE_PERIPHERAL    1

// <q BLE_ROLE_BROADCASTER> Enables the Broadcaster bluetooth role
// <i> Default: 1
// <i> Enables the Broadcaster bluetooth role
#define BLE_ROLE_BROADCASTER    1

// <q BLE_ROLE_OBSERVER> Enables the Observer bluetooth role
// <i> Default: 1
// <i> Enables the Observer bluetooth role
#define BLE_ROLE_OBSERVER    1

// <o BLE_MAX_CONNECTIONS> Maximum number of concurrent connections
// <i> Default: 1
// <i> The maximum number of concurrent connections.
#define BLE_MAX_CONNECTIONS    1

// <o BLE_MAX_PERIODIC_SYNCS> Maximum number of concurrent periodic syncs
// <i> Default: 1
// <i> The maximum number of concurrent periodic syncs that can be created
#define BLE_MAX_PERIODIC_SYNCS    1

// <q BLE_WHITELIST> Enables the BLE whitelist
// <i> Default: 1
// <i> Enables the BLE whitelist for controlling who to connect to or accept a connection from.
#define BLE_WHITELIST    1

// <o BLE_MULTI_ADV_INSTANCES> Number of multi-advertising instances
// <i> Default: 0
// <i> This is the number of multi-advertising instances. This is NOT the
// <i> total number of advertising instances. The total number of
// <i> advertising instances is this number plus 1 (assuming the device
// <i> supports advertising).
#define BLE_MULTI_ADV_INSTANCES    0

// <q BLE_EXT_ADV> Extended advertising feature
// <i> Default: 0
// <i> This enables extended advertising feature.
#define BLE_EXT_ADV    0

// TODO: restrictions:
//            - 'BLE_EXT_ADV if 1'
// <q BLE_PERIODIC_ADV> Periodic advertising feature
// <i> Default: 0
// <i> This enables periodic advertising feature.
#define BLE_PERIODIC_ADV    0

// TODO:
// restrictions:
//     - 'BLE_PERIODIC_ADV if 1'
//     - '(BLE_ROLE_CENTRAL || BLE_ROLE_PERIPHERAL) if 1'
// <q BLE_PERIODIC_ADV_SYNC_TRANSFER> Periodic Advertising Sync Transfer Feature
// <i> Default: 0
// <i> This enables Periodic Advertising Sync Transfer Feature.
#define BLE_PERIODIC_ADV_SYNC_TRANSFER    0

// TODO:
// restrictions:
//     - 'BLE_PERIODIC_ADV if 1'
//     - '(BLE_VERSION >= 52) if 1'
// <q BLE_PERIODIC_ADV_SYNC_BIGINFO_REPORTS> BIGInfo reports
// <i> Default: 0
// <i> This enables BIGInfo reports.
#define BLE_PERIODIC_ADV_SYNC_BIGINFO_REPORTS    0

// <o BLE_EXT_ADV_MAX_SIZE> Maximum size of advertising data and response
// <i> Default: 31
// <i> This allows to configure maximum size of advertising data and
//     scan response data used in LE Advertising Extensions.
//     Valid range 31-1650.
// <31..1650>
#define BLE_EXT_ADV_MAX_SIZE    31

// <o BLE_VERSION> Supported Bluetooth Core version
// <i> Default: 50
// <i> This allows to configure supported Bluetooth Core version. Some
//     features may not be available if version is too low. Version is
//     integer for easy comparison.
// <50..54>
#define BLE_VERSION    50

// TODO:
// restrictions:
//     - '(BLE_VERSION >= 52) if 1'
// <q BLE_ISO> LE Isochronous Channels
// <i> Default: 0
// <i> This enables LE Isochronous Channels as per Bluetooth v5.2
#define BLE_ISO    0

// TODO:
// restrictions:
//     - '(BLE_VERSION >= 52) if 1'
// <q BLE_ISO_BROADCASTER> LE Audio Broadcaster feature
// <i> Default: 0
// <i> This enables LE Audio Broadcaster feature
#define BLE_ISO_BROADCASTER    0

// TODO:
// restrictions:
//     - 'BLE_ISO if 1'
// <q BLE_ISO_TEST> BLE ISO Testing commands
// <i> Default: 0
// <i> Enables BLE ISO Testing commands
#define BLE_ISO_TEST    0

// <q BLE_HCI_VS> NimBLE specific vendor HCI commands
// <i> Default: 0
// <i> Enables support for NimBLE specific vendor HCI commands
#define BLE_HCI_VS    0

// <o BLE_HCI_VS_OCF_OFFSET> Starting offset for NimBLE specific vendor HCI commands
// <i> Default: 0
// <i> This defines starting offset for NimBLE specific vendor HCI commands.
//     Purpose of this is to improve compatibility with other custom
//     implementations.
#define BLE_HCI_VS_OCF_OFFSET    0

// <q BLE_POWER_CONTROL> LE Power Control feature
// <i> Default: 0
// <i> This enabled LE Power Control feature
#define BLE_POWER_CONTROL    0

// <q BLE_CONN_SUBRATING> LE Connection Subrating feature
// <i> Default: 0
// <i> This enables LE Connection Subrating feature
#define BLE_CONN_SUBRATING    0

// TODO:
// restrictions:
//     - 'BLE_PHY if 1'
// <q BLE_PHY_2M> Support for addtitional 2M PHY
// <i> Default: 0
// <i> This enables support for addtitional 2M PHY
#define BLE_PHY_2M    0

// TODO:
// restrictions:
//     - 'BLE_PHY if 1'
// <q BLE_PHY_CODED> Support for addtitional CODED PHY
// <i> Default: 0
// <i> This enables support for addtitional CODED PHY
#define BLE_PHY_CODED    0

// TODO: Some contrains need to be applied:
// syscfg.defs.'BLE_PHY_2M || BLE_PHY_CODED':
//     BLE_PHY: 1

// # Allow periodic sync transfer only if 5.1 or higher
// syscfg.restrictions:
//     - "'BLE_PERIODIC_ADV_SYNC_TRANSFER == 0' || 'BLE_VERSION >= 51'"

// # Enable VS HCI by default for combined or standalone controller build
// syscfg.vals.BLE_CONTROLLER:
//     BLE_HCI_VS: 1

// </h>

// <<< end of configuration section >>>
#endif // NIMBLE_CONFIG_H_
