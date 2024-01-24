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


#ifndef NIMBLE_HOST_CONFIG_H_
#define NIMBLE_HOST_CONFIG_H_

#include "ble_hs.h"
#include "ble_sm.h"

// <<< Use Configuration Wizard in Context Menu >>>

// <h> NimBLE Host Debug Configurations
// <q BLE_HS_DEBUG> Enables extra runtime assertions.
// <i> Default: 0
// <i> Enables extra runtime assertions.
#define BLE_HS_DEBUG    0

// <q BLE_HS_PHONY_HCI_ACKS> The host simulates incoming acks
// <i> Default: 0
// <i> Rather than wait for HCI acknowledgements from a controller, the
//     host simulates incoming acks.  Only recommended for test code
//     running in the simulator.
#define BLE_HS_PHONY_HCI_ACKS    0

// <q BLE_HS_REQUIRE_OS> Host depends on the kernel being present
// <i> Default: 1
// <i> Specifies whether the host can depend on the kernel being present.
//     This should only be disabled for unit tests running in the
//     simulator.
#define BLE_HS_REQUIRE_OS    1
// </h>

// <h> L2CAP Settings
// TODO: This would cause compiling issue
// <o BLE_L2CAP_MAX_CHANS> Number of L2CAP channels to allocate
// <i> Default: 3*BLE_MAX_CONNECTIONS
// <i> The number of L2CAP channels to allocate.  The default value allows
//     for the signal, ATT, and SM channels for each connection.
#define BLE_L2CAP_MAX_CHANS    3*BLE_MAX_CONNECTIONS

// <o BLE_L2CAP_SIG_MAX_PROCS> Maximum concurrent L2CAP signal procedures
// <i> Default: 1
// <i> The maximum number of concurrent L2CAP signal procedures.
#define BLE_L2CAP_SIG_MAX_PROCS    1

// <o BLE_L2CAP_JOIN_RX_FRAGS> Collapse incoming L2CAP fragments
// <i> Default: 1
// <i> Whether to collapse incoming L2CAP fragments into a minimal set of mbufs.
// <1=> Slower, more memory efficient.
// <0=> Faster, less memory efficient.
#define BLE_L2CAP_JOIN_RX_FRAGS    1

// <o BLE_L2CAP_RX_FRAG_TIMEOUT> Expiry time for incoming data packets
// <i> Default: 30000
// <i> Expiry time for incoming data packets (ms).  If this much time
//     passes since the previous fragment was received, the connection is
//     terminated.  A value of 0 means no timeout.
#define BLE_L2CAP_RX_FRAG_TIMEOUT    30000

// <o BLE_L2CAP_COC_MAX_NUM> Maximum number of LE Connection Oriented Channels channels
// <i> Default: 0
// <i> Defines maximum number of LE Connection Oriented Channels channels.
//     When set to (0), LE COC is not compiled in.
#define BLE_L2CAP_COC_MAX_NUM    0

// <o BLE_L2CAP_COC_MPS> The MPS of L2CAP COC module
// <i> Default: MSYS_1_BLOCK_SIZE-8
// <i> Defines the MPS of L2CAP COC module. This is actually NimBLE's internal
// L2CAP MTU. The default MPS size is chosen in a way, that the MPS plus
// the required HCI and L2CAP headers fit into the smallest available
// MSYS blocks.
#define BLE_L2CAP_COC_MPS   MSYS_1_BLOCK_SIZE-8

// TODO: 
// restrictions:
//     - 'BLE_L2CAP_COC_SDU_BUFF_COUNT > 0'
// <o BLE_L2CAP_COC_SDU_BUFF_COUNT> Maximum number of SDU buffers
// <i> Default: 1
// <i> Defines maximum number of SDU buffers in L2CAP COC endpoints.
// Provides more currently available credits to receive more data packets.
#define BLE_L2CAP_COC_SDU_BUFF_COUNT   1

// <q BLE_L2CAP_ENHANCED_COC> LE Enhanced CoC mode
// <i> Default: 0
// <i> Enables LE Enhanced CoC mode.
#define BLE_L2CAP_ENHANCED_COC   0
// </h>

// <h> Security Manager Settings
// <q BLE_SM_LEGACY> SM Leagcy Pairing
// <d> 1
// <i> Security manager legacy pairing.
#define BLE_SM_LEGACY    1 

// <o BLE_SM_SC> Security manager secure connections (4.2).
// <d> 0
// <i> Security manager secure connections (4.2).
#define BLE_SM_SC    0

// <o BLE_SM_SC_ONLY> Force global Secure Connections Pairing Only mode
// <d> 0
// <i> Force global Secure Connections Pairing Only mode. This means
// <i> that only SC pairing mode 1 level 4 shall be used, and all
// <i> characteristics will require it to access, except these
// <i> requiring mode 1 level 1.
// TODO: restrictions:
// - 'BLE_SM_LVL == 4 if 1'
// - BLE_SM_MITM
// - 'BLE_SM_SC if 1'
// - '!BLE_SM_LEGACY if 1'
#define BLE_SM_SC_ONLY     0

// <o BLE_SM_LVL> Force global Secure Connections mode 1 level
// <d> 0
// <i> Force global Secure Connections mode 1 level. This level
// <i> describes requirements for pairing response/request received
// <i> to accept pairing:
// <i> - 1 - do not pair; only access to characteristics with no
// <i>       authentication requirements is granted
// <i> - 2 - allow to pair despite MITM being on or off
// <i> - 3 - allow to pair only when MITM protection is on
// <i> - 4 - allow to pair only with Secure Connections and
// <i>       when 128 bit key is used and MITM is on
// <i> When set to 0 level is no forced and pairing is allowed for all
// <i> requests/responses with valid values (for example pairing will be
// <i> rejected with key longer than 128 bits). Successful pairing with
// <i> insufficient security will still cause denying access to protected
// <i> GATT characteristics.
// <0=> No choice
// <1=> Do not allow pair
// <2=> Allow to pair despite MITM being on or off
// <3=> Allow to pair only when MITM protection is on
// <4=> allow to pair only with Secure Connections and when 128 bit key is used and MITM is on
#define BLE_SM_LVL   0


// <o BLE_SM_MAX_PROCS> Maximum number of concurrent security manager procedures
// <d> 1
// <i> The IO capabilities to report during pairing
// <BLE_HS_IO_DISPLAY_ONLY=> BLE_HS_IO_DISPLAY_ONLY
// <BLE_HS_IO_NO_INPUT_OUTPUT=> BLE_HS_IO_NO_INPUT_OUTPUT
// <BLE_HS_IO_KEYBOARD_ONLY=> BLE_HS_IO_KEYBOARD_ONLY
// <BLE_HS_IO_KEYBOARD_DISPLAY=> BLE_HS_IO_KEYBOARD_DISPLAY
// <BLE_HS_IO_DISPLAY_YESNO=> BLE_HS_IO_DISPLAY_YESNO
#define BLE_SM_MAX_PROCS      BLE_HS_IO_NO_INPUT_OUTPUT

// <q BLE_SM_OOB_DATA_FLAG> Out-of-band pairing algorithm
// <d> 0
// <i> Whether the out-of-band pairing algorithm is advertised.
#define BLE_SM_OOB_DATA_FLAG 0

// <q BLE_SM_BONDING> Enables bonding
// <d> 0
// <i> Enables bonding (persistence and restoration of secure links).
#define BLE_SM_BONDING 0

// <q BLE_SM_MITM> Man-in-the-middle protection
// <d> 0
// <i> Whether man-in-the-middle protection is advertised during pairing.
#define BLE_SM_MITM 0

// <q BLE_SM_KEYPRESS> Whether keypress support is advertised during pairing.
// <d> 0
// <i> Whether keypress support is advertised during pairing.
#define BLE_SM_KEYPRESS 0

// <q BLE_SM_KEYPRESS> Whether keypress support is advertised during pairing.
// <d> 0
// <i> Whether keypress support is advertised during pairing.
#define BLE_SM_KEYPRESS 0

// <q BLE_SM_OUR_KEY_DIST> Keys to distribute during pairing
// <d> 0
// <0=> 0
// <0x01=> BLE_SM_PAIR_KEY_DIST_ENC
// <0x02=> BLE_SM_PAIR_KEY_DIST_ID
// <0x04=> BLE_SM_PAIR_KEY_DIST_SIGN
// <0x08=> BLE_SM_PAIR_KEY_DIST_LINK
// <i> A bitmap indicating which keys to distribute during pairing.
#define BLE_SM_OUR_KEY_DIST 0


// <q BLE_SM_THEIR_KEY_DIST> Keys to accept during pairing
// <d> 0
// <0=> 0
// <BLE_SM_PAIR_KEY_DIST_ENC=> BLE_SM_PAIR_KEY_DIST_ENC
// <BLE_SM_PAIR_KEY_DIST_ID=> BLE_SM_PAIR_KEY_DIST_ID
// <BLE_SM_PAIR_KEY_DIST_SIGN=> BLE_SM_PAIR_KEY_DIST_SIGN
// <BLE_SM_PAIR_KEY_DIST_LINK=> BLE_SM_PAIR_KEY_DIST_LINK
// <i> A bitmap indicating which keys to accept during pairing
#define BLE_SM_THEIR_KEY_DIST 0

// <q BLE_SM_SC_DEBUG_KEYS> Enable SM debug mode
// <d> 0
// <i> Enable SM debug mode. In this mode SM uses predefined DH key pair as
// <i> described in Core Specification 5.0, Vol. 3, Part H, 2.3.5.6.1. This
// <i> allows to decrypt air traffic easily and thus should be only used
// <i> for debugging.
#define BLE_SM_SC_DEBUG_KEYS 0

// <q BLE_SM_CSIS_SIRK> Enable LE Audio CSIS SIRK Encryption and Decryption API.
// <d> 0
// <i> Enable LE Audio CSIS SIRK Encryption and Decryption API.
#define BLE_SM_CSIS_SIRK 0

// </h>

// <h GAP Options>

// <o BLE_GAP_MAX_PENDING_CONN_PARAM_UPDATE> Number of connection parameter updates that can be pending simultaneously
// <d> 1
// <i> Controls the number of connection parameter updates that can be pending
// <i> simultaneously. Devices with many concurrent connections may need
// <i> to increase this value.
#define BLE_GAP_MAX_PENDING_CONN_PARAM_UPDATE 0

// </h>

// <h Supported GATT Procedures
// By default:
//     o Notify and indicate are enabled;
//     o All other procedures are enabled for centrals.

// <q MYNEWT_VAL_BLE_GATT_DISC_ALL_SVCS> Discover All Primary Services GATT
// <i> Enables the Discover All Primary Services GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_SVCS  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_DISC_SVC_UUID> Discover Primary Services by Service UUID GATT
// <i> Enables the Discover Primary Services by Service UUID GATT procedure. 
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_DISC_SVC_UUID  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_FIND_INC_SVCS> Find Included Services GATT
// <i> Enables the Find Included Services GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_FIND_INC_SVCS  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_DISC_ALL_CHRS> Discover All Characteristics of a Service GATT
// <i> Enables the Discover All Characteristics of a Service GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_CHRS  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_DISC_CHR_UUID> Discover Characteristics by UUID GATT
// <i> Enables the Discover Characteristics by UUID GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_DISC_CHR_UUID  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_DISC_ALL_DSCS> Discover All Primary Services GATT
// <i> Enables the Discover All Primary Services GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_DISC_ALL_DSCS  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_READ> Read Characteristic Value GATT
// <i> Enables the Read Characteristic Value GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_READ  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_READ_UUID> Read Using Characteristic UUID GATT
// <i> Enables the Read Using Characteristic UUID GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_READ_UUID  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_READ_LONG> Read Long Characteristic Values GATT
// <i> Enables the Read Long Characteristic Values GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_READ_LONG  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_READ_MULT> Read Multiple Characteristic Values GATT
// <i> Enables the Read Multiple Characteristic Values GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_READ_MULT  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_READ_MULT_VAR> Read Multiple Variable Characteristic Values GATT
// <i> Enables the Read Multiple Variable Characteristic Values GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_READ_MULT_VAR  (MYNEWT_VAL_BLE_ROLE_CENTRAL && (MYNEWT_VAL_BLE_VERSION >= 52))
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_WRITE_NO_RSP> Write Without Response GATT
// <i> Enables the Write Without Response GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_WRITE_NO_RSP  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_SIGNED_WRITE> Signed Write Without Response GATT
// <i> Enables the Signed Write Without Response GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_SIGNED_WRITE  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_WRITE> Write Characteristic Value GATT
// <i> Enables the Write Characteristic Value GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_WRITE  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_WRITE_LONG> Write Long Characteristic Values GATT
// <i> Enables the Write Long Characteristic Values GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_WRITE_LONG  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_WRITE_RELIABLE> Reliable Writes GATT
// <i> Enables the Reliable Writes GATT procedure.
#ifdef MYNEWT_VAL_BLE_ROLE_CENTRAL
#define MYNEWT_VAL_BLE_GATT_WRITE_RELIABLE  (MYNEWT_VAL_BLE_ROLE_CENTRAL)
#endif // MYNEWT_VAL_BLE_ROLE_CENTRAL

// <q MYNEWT_VAL_BLE_GATT_NOTIFY> Whether sending and receiving of GATT notifications
// <i> Enables sending and receiving of GATT notifications.
// <d> 1
#define MYNEWT_VAL_BLE_GATT_NOTIFY  1

// <q MYNEWT_VAL_BLE_GATT_INDICATE> Whether sending and receiving of GATT indications
// <i> Enables sending and receiving of GATT indications.
// <d> 1
#define MYNEWT_VAL_BLE_GATT_INDICATE  1

// </h>

// <h GATT Options>

// <o MYNEWT_VAL_BLE_GATT_READ_MAX_ATTRS> Maximum number of attributes that can be read
// <i> The maximum number of attributes that can be read with a single
// <i> GATT Read Multiple Characteristic Values procedure.
// <d> 8
#define MYNEWT_VAL_BLE_GATT_READ_MAX_ATTRS  8

// <o MYNEWT_VAL_BLE_GATT_WRITE_MAX_ATTRS> maximum number of attributes that can be written with a single procedure
// <i> The maximum number of attributes that can be written with a single
// <i> GATT Reliable Write procedure.
// <d> 4
#define MYNEWT_VAL_BLE_GATT_WRITE_MAX_ATTRS  4

// <o MYNEWT_VAL_BLE_GATT_MAX_PROCS> maximum number of concurrent client GATT procedures
// <i> The maximum number of concurrent client GATT procedures.
// <d> 4
#define MYNEWT_VAL_BLE_GATT_MAX_PROCS  4

// <o MYNEWT_VAL_BLE_GATT_RESUME_RATE> The rate to periodically resume GATT procedures that have stalled
// <i> The rate to periodically resume GATT procedures that have stalled
// <i> due to memory exhaustion. Units are milliseconds
// <d> 1000
#define MYNEWT_VAL_BLE_GATT_RESUME_RATE  1000

// </h>

// <h Supported server ATT commands>

// <o MYNEWT_VAL_BLE_EATT_CHAN_NUM> Number of CoC channels allocated to EATT
// <i> Number of CoC channels allocated to EATT
// <d> 0
#define MYNEWT_VAL_BLE_EATT_CHAN_NUM     0

// <o MYNEWT_VAL_BLE_EATT_MTU> MTU used for EATT channels.
// <i> MTU used for EATT channels.
// <d> 128
#define MYNEWT_VAL_BLE_EATT_MTU     128

// <q MYNEWT_VAL_BLE_ATT_SVR_FIND_INFO> Processing of incoming Find Information Request ATT
// <i> Enables processing of incoming Find Information Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_FIND_INFO     1

// <q MYNEWT_VAL_BLE_ATT_SVR_FIND_TYPE> Processing of incoming Find By Type Value Request ATT
// <i> Enables processing of incoming Find By Type Value Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_FIND_TYPE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_READ_TYPE> Processing of incoming Read By Type Value Request ATT
// <i> Enables processing of incoming Read By Type Value Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_READ_TYPE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_READ> Processing of incoming Read Request ATT
// <i> Enables processing of incoming Read Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_READ     1

// <q MYNEWT_VAL_BLE_ATT_SVR_READ_BLOB> Processing of incoming Read Blob Request ATT
// <i> Enables processing of incoming Read Blob Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_READ_BLOB     1

// <q MYNEWT_VAL_BLE_ATT_SVR_READ_MULT> Processing of incoming Read Multiple Request ATT
// <i> Enables processing of incoming Read Multiple Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_READ_MULT     1

// <q MYNEWT_VAL_BLE_ATT_SVR_READ_GROUP_TYPE> Processing of incoming Read By Group Type Request ATT
// <i> Enables processing of incoming Read By Group Type Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_READ_GROUP_TYPE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_WRITE> Processing of incoming Write Request ATT
// <i> Enables processing of incoming Write Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_WRITE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_WRITE_NO_RSP> Processing of incoming Write Command ATT
// <i> Enables processing of incoming Write Command ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_WRITE_NO_RSP     1

// <q MYNEWT_VAL_BLE_ATT_SVR_SIGNED_WRITE> Processing of incoming Signed Write Command ATT
// <i> Enables processing of incoming Signed Write Command ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_SIGNED_WRITE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE> Processing of incoming Prepare Write Request and Execute Write Request ATT
// <i> Enables processing of incoming Prepare Write Request and Execute Write Request ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE     1

// <q MYNEWT_VAL_BLE_ATT_SVR_NOTIFY> Processing of incoming Handle Value Notification ATT
// <i> Enables processing of incoming Handle Value Notification ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_NOTIFY     1

// <q MYNEWT_VAL_BLE_ATT_SVR_NOTIFY_MULTI> Processing of incoming Multi Handle Value Notification ATT
// <i> Enables processing of incoming Multi Handle Value Notification ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_NOTIFY_MULTI     (MYNEWT_VAL_BLE_ATT_SVR_NOTIFY && (MYNEWT_VAL_BLE_VERSION >= 52))

// <q MYNEWT_VAL_BLE_ATT_SVR_INDICATE> Processing of incoming Handle Value Indication ATT
// <i> Enables processing of incoming Handle Value Indication ATT commands.
// <d> 1
#define MYNEWT_VAL_BLE_ATT_SVR_INDICATE 1

// </h>

// <h ATT Options>

// <o MYNEWT_VAL_BLE_ATT_PREFERRED_MTU> The preferred MTU to indicate in MTU exchange commands
// <i> The preferred MTU to indicate in MTU exchange commands
// <d> 256
#define MYNEWT_VAL_BLE_ATT_PREFERRED_MTU   256

// <o MYNEWT_VAL_BLE_ATT_SVR_MAX_PREP_ENTRIES> BLE_ATT_SVR_MAX_PREP_ENTRIES
// <i> A GATT server uses these when a peer performs a "write long
// <i> characteristic values" or "write long characteristic descriptors"
// <i> procedure.  One of these resources is consumed each time a peer
// <i> sends a partial write.
// <d> 64
#define MYNEWT_VAL_BLE_ATT_SVR_MAX_PREP_ENTRIES   64

// <o MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE_TMO> BLE_ATT_SVR_QUEUED_WRITE_TMO
// <i> Expiry time for incoming ATT queued writes (ms).  If this much
// <i> time passes since the previous prepared write was received, the
// <i> connection is terminated.  A value of 0 means no timeout.
// <d> 30000
#define MYNEWT_VAL_BLE_ATT_SVR_QUEUED_WRITE_TMO   30000

// </h>

// <h Privacy Options>

// <o MYNEWT_VAL_BLE_RPA_TIMEOUT> The rate that new random addresses should be generated
// <i> The rate that new random addresses should be generated (seconds).
// <d> 300
#define MYNEWT_VAL_BLE_RPA_TIMEOUT   300

// </h>

// <h Store Settings>

// <o MYNEWT_VAL_BLE_STORE_MAX_BONDS> Maximum number of bonds that can be persisted
// <i> Maximum number of bonds that can be persisted.  Note: increasing
// <i> this value may also require increasing the capacity of the
// <i> underlying storage mechanism.
// <d> 3
#define MYNEWT_VAL_BLE_STORE_MAX_BONDS   3

// <o MYNEWT_VAL_BLE_STORE_MAX_CCCDS> Maximum number of persisted client characteristic configuration descriptors
// <i> Maximum number of client characteristic configuration descriptors
// <i> that can be persisted.  Note: increasing this value may also
// <i> require increasing the capacity of the underlying storage mechanism.
// <d> 8
#define MYNEWT_VAL_BLE_STORE_MAX_CCCDS   8

// TODO Apply value 1 to the macro: BLE_SM_SC if this macro equals 1 due to below:
//syscfg.vals.BLE_MESH:
//    BLE_SM_SC: 1
// <q MYNEWT_VAL_BLE_MESH> Bluetooth Mesh support
// <i> This option enables Bluetooth Mesh support. The specific
// <i> features that are available may depend on other features
// <i> that have been enabled in the stack, such as GATT support.
// <d> 0
#define MYNEWT_VAL_BLE_MESH   0

// </h>

// <h Flow control settings>

// <q MYNEWT_VAL_BLE_HS_FLOW_CTRL> Host-side flow control
// <i> Whether to enable host-side flow control.  This should only be
// <i> enabled in host-only setups (i.e., not combined-host-controller).
// <d> 0
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL   0

// <o MYNEWT_VAL_BLE_HS_FLOW_CTRL_ITVL> Interval that host provides number-of-completed-packages
// <i> The interval, in milliseconds, that the host should provide
// <i> number-of-completed-packets updates to the controller.
// <d> 1000
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_ITVL   1000

// <o MYNEWT_VAL_BLE_HS_FLOW_CTRL_THRESH> BLE_HS_FLOW_CTRL_THRESH
// <i> If the number of data buffers available to the controller falls to
// <i> this number, immediately send a number-of-completed-packets event.
// <i> The free buffer count is calculated as follows:
// <i> (total-acl-bufs - bufs-freed-since-last-num-completed-event).
// <d> 2
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_THRESH  2

// <q MYNEWT_VAL_BLE_HS_FLOW_CTRL_TX_ON_DISCONNECT> BLE_HS_FLOW_CTRL_TX_ON_DISCONNECT
// <i> If enabled, the host will immediately transmit a
// <i> host-number-of-completed-packets command whenever a connection
// <i> terminates.  This behavior is not required by the standard, but is
// <i> a necessary workaround when interfacing with some controllers.
// <d> 0
#define MYNEWT_VAL_BLE_HS_FLOW_CTRL_TX_ON_DISCONNECT   0

// <q MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN> Stops the Bluetooth host when the system shuts down
// <i> Stops the Bluetooth host when the system shuts down.  Stopping
// <i> entails aborting all GAP procedures and terminating open
// <i> connections.
// <d> 1
#define MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN   1

// <o MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN_TIMEOUT> Timeout used in NimBLE's host stop procedure in ms
// <i> Timeout used in NimBLE's host stop procedure in ms
// <d> 2000
#define MYNEWT_VAL_BLE_HS_STOP_ON_SHUTDOWN_TIMEOUT   2000

// <o MYNEWT_VAL_BLE_HS_SYSINIT_STAGE> Sysinit stage for the NimBLE host.
// <i> Sysinit stage for the NimBLE host.
// <d> 200
#define MYNEWT_VAL_BLE_HS_SYSINIT_STAGE   200

// <q MYNEWT_VAL_BLE_HS_GAP_UNHANDLED_HCI_EVENT> BLE_HS_GAP_UNHANDLED_HCI_EVENT
// <i> Enables GAP event for received HCI events that are not handled by
// <i> host. This can be used to implement/test features that are not yet
// <i> supported by host.
// <d> 0
#define MYNEWT_VAL_BLE_HS_GAP_UNHANDLED_HCI_EVENT   0

// TODO: Apply Configuration validator (BLE_ISO_BROADCASTER if 0)
// <o MYNEWT_VAL_BLE_MAX_BIG> Number of available BIGs
// <i> Number of available BIGs
#define MYNEWT_VAL_BLE_MAX_BIG   (MYNEWT_VAL_BLE_MULTI_ADV_INSTANCES)

// TODO: Apply Configuration validator (BLE_ISO_BROADCASTER if 0)
// <o MYNEWT_VAL_BLE_MAX_BIS> Number of supported BISes
// <i> Number of supported BISes
// <d> 4
#define MYNEWT_VAL_BLE_MAX_BIS   4

// </h>

// <h Log settings>

// <o MYNEWT_VAL_BLE_HS_LOG_MOD> Numeric module ID to use for BLE host log messages
// <i> Numeric module ID to use for BLE host log messages
// <d> 4
#define MYNEWT_VAL_BLE_HS_LOG_MOD   4

// <o MYNEWT_VAL_BLE_HS_LOG_LVL> Minimum level for the BLE host log.
// <i> Minimum level for the BLE host log.
// <d> 1
#define MYNEWT_VAL_BLE_HS_LOG_LVL   1

// <o MYNEWT_VAL_BLE_EATT_LOG_MOD> Numeric module ID to use for BLE EATT log messages.
// <i> Numeric module ID to use for BLE EATT log messages.
// <d> 27
#define MYNEWT_VAL_BLE_EATT_LOG_MOD   27

// <o MYNEWT_VAL_BLE_EATT_LOG_LVL> Minimum level for the BLE EATT log.
// <i> Minimum level for the BLE EATT log.
// <d> 1
#define MYNEWT_VAL_BLE_EATT_LOG_LVL   1

// </h>
// <<< end of configuration section >>>
#endif //SAPC_TIME_CLUSTER_CONFIG_H_
