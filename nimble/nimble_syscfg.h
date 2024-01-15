/***************************************************************************//**
 * @brief NimBLE component configuration header.
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

// <<< Use Configuration Wizard in Context Menu >>>
// <h>SAPC Tunneling debug options

#ifndef NIMBLE_CONFIG_H_
#define NIMBLE_CONFIG_H_
//TODO Add configuration to here

// <q SAPC_TUNNELING_SERVER_DEBUG_ENABLED> Enable log debug
// <i> Default: TRUE
// <i> Enable log debug for SAPC Tunneling server cluster related features.
#if (SAPC_CONFIG_ENABLE_DEBUG==1)
#define SAPC_TUNNELING_SERVER_DEBUG_ENABLED    1
#endif //SAPC_CONFIG_ENABLE_DEBUG
// </h>
#endif //SAPC_TUNNELING_SERVER_CONFIG_H_
// <<< end of configuration section >>>