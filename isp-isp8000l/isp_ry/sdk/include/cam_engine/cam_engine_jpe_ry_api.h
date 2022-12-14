/******************************************************************************\
|* Copyright 2010, Dream Chip Technologies GmbH. used with permission by      *|
|* VeriSilicon.                                                               *|
|* Copyright (c) <2020> by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")     *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

/* VeriSilicon 2020 */

/**
 * @cond    cam_engine_jpe
 *
 * @file    cam_engine_jpe_api.h
 *
 * @brief
 *
 *   Interface description of the CamEngine JPE.
 *
 *****************************************************************************/
/**
 *
 * @defgroup cam_engine_jpe_api CamEngine JPE API
 * @{
 *
 */

#ifndef __CAM_ENGINE_JPE_RY_API_H__
#define __CAM_ENGINE_JPE_RY_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

//FIXME
#include <cameric_drv/cameric_jpe_drv_ry_api.h>


/*****************************************************************************/
/**
 * @brief   This function enables the jpe.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 * @param   pConfig             configuration of jpe
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_CONFIG    image effects isn't configured
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineEnableJpe_ry
(
    CamEngineHandle_ry_t hCamEngine,
    CamerIcJpeConfig_ry_t *pConfig
);


/*****************************************************************************/
/**
 * @brief   This function disables the image effects.
 *
 * @param   hCamEngine          handle to the CamEngine instance
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_NOTAVAILABLE    module not available by driver or hardware
 *
 *****************************************************************************/
RESULT CamEngineDisableJpe_ry
(
    CamEngineHandle_ry_t hCamEngine
);


#ifdef __cplusplus
}
#endif

/* @} cam_engine_jpe_api */

#endif /* __CAM_ENGINE_JPE_RY_API_H__ */

