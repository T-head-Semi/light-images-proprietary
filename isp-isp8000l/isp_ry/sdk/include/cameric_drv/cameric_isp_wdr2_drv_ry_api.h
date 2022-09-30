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

#ifndef __CAMERIC_ISP_WDR2_DRV_RY_API_H__
#define __CAMERIC_ISP_WDR2_DRV_RY_API_H__

/**
 * @file    cameric_isp_wdr2_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP WDR driver API definitions.
 *
 *****************************************************************************/
/**
 * @cond cameric_isp_wdr2
 *
 * @defgroup cameric_isp_wdr2_drv_api CamerIC ISP WDR2 Driver API definitions
 * @{
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_WDR2_MAX_COEFFS      33
#define CAMERIC_WDR2_MAX_SEGMENTS    ( CAMERIC_WDR2_MAX_COEFFS - 1 )



/*******************************************************************************
 *
 *          CamerIcIspWdr2ToneCurve_ry_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspWdr2ToneCurve_ry_s
{
    uint16_t    Segment[CAMERIC_WDR2_MAX_SEGMENTS];
    uint16_t    Ym[CAMERIC_WDR2_MAX_COEFFS];
} CamerIcIspWdr2ToneCurve_ry_t;




/*****************************************************************************/
/**
 *          CamerIcIspWdr2Enable_ry()
 *
 * @brief   Enable WDR2 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr2Enable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 *          CamerIcIspWdr2Disable_ry()
 *
 * @brief   Disable WDR2 Module
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr2Disable_ry
(
    CamerIcDrvHandle_ry_t handle
);

/*****************************************************************************/
/**
 *          CamerIcIspWdr2SetStaticDemoConfig_ry()
 *
 * @brief   Set static WDR2 configuration; quick hack for demo purposes only!
 *
 * @param   handle          CamerIc driver handle
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
RESULT CamerIcIspWdr2SetStaticDemoConfig_ry
(
    CamerIcDrvHandle_ry_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only Start!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdr2SetStaticDemoConfigCurve0_ry
(
    CamerIcDrvHandle_ry_t  handle
);


RESULT CamerIcIspWdr2SetStaticDemoConfigCurve1_ry
(
    CamerIcDrvHandle_ry_t  handle
);

RESULT CamerIcIspWdr2SetStaticDemoConfigCurve2_ry
(
    CamerIcDrvHandle_ry_t  handle
);

RESULT CamerIcIspWdr2SetStaticDemoConfigCurve3_ry
(
    CamerIcDrvHandle_ry_t  handle
);

/***********************************************************************
****************************************************************
*Modify by Fei for demo Only End!!!
****************************************************************
************************************************************************/
RESULT CamerIcIspWdr2SetStrength_ry
(
    CamerIcDrvHandle_ry_t  handle,
    float               wdr2CurveStrength
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_wdr_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_WDR2_DRV_RY_API_H__ */

