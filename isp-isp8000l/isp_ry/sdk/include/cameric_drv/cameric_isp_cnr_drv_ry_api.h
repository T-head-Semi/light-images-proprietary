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

#ifndef __CAMERIC_ISP_CNR_DRV_RY_API_H__
#define __CAMERIC_ISP_CNR_DRV_RY_API_H__

/**
 * @cond    cameric_isp_cnr
 *
 * @file    cameric_isp_cnr_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP CNR driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_cnr_drv_api CamerIC ISP CNR driver API definitions
 * @{
 *
 * @image html cameric20MP_isp_cnr.png "CamerIC ISP CNR driver" width=\textwidth
 * @image latex cameric20MP_isp_cnr.png "CamerIC ISP CNR driver" width=\textwidth
 *
 * The color noise reduction module is used
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************/
/**
 * @brief   This function enables the CamerIC ISP CNR Module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
 * @brief   This function disables the CamerIc ISP CNR module (bypass the
 *          color noise reduction module)
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the CamerIC ISP CNR module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrIsActivated_ry
(
    CamerIcDrvHandle_ry_t  handle,
    bool_t              *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function sets the line-width of the CamerIC ISP CNR module.
 *
 * @param   handle              CamerIc driver handle
 * @param   width               Line width to set
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrSetLineWidth_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      width
);



/*****************************************************************************/
/**
 * @brief   This function returns the thresholds of the CamerIC ISP CNR module.
 *
 * @param   handle              CamerIc driver handle
 * @param   threshold1          Threshold Color Channel 1
 * @param   threshold2          Threshold Color Channel 2
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrGetThresholds_ry
(
    CamerIcDrvHandle_ry_t  handle,
    uint32_t            *threshold1,
    uint32_t            *threshold2
);



/*****************************************************************************/
/**
 * @brief   This function sets the thresholds of the CamerIC ISP CNR module.
 *
 * @param   handle              CamerIc driver handle
 * @param   threshold1          Threshold Color Channel 1
 * @param   threshold2          Threshold Color Channel 2
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspCnrSetThresholds_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint32_t      threshold1,
    const uint32_t      threshold2
);



#ifdef __cplusplus
}
#endif

/* @} cameric_isp_cnr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_CNR_DRV_RY_API_H__ */

