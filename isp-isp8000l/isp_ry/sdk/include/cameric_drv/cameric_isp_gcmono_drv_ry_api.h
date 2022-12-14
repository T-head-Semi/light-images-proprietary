/******************************************************************************\
|* Copyright (c) 2020 by VeriSilicon Holdings Co., Ltd. ("VeriSilicon")       *|
|* All Rights Reserved.                                                       *|
|*                                                                            *|
|* The material in this file is confidential and contains trade secrets of    *|
|* of VeriSilicon.  This is proprietary information owned or licensed by      *|
|* VeriSilicon.  No part of this work may be disclosed, reproduced, copied,   *|
|* transmitted, or used in any way for any purpose, without the express       *|
|* written permission of VeriSilicon.                                         *|
|*                                                                            *|
\******************************************************************************/

#ifndef __CAMERIC_ISP_GCMONO_DRV_RY_API_H__
#define __CAMERIC_ISP_GCMONO_DRV_RY_API_H__
#ifdef ISP_GCMONO

/**
 * @cond    cameric_isp_gcmono
 *
 * @file    cameric_isp_gcmono_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP gcmono driver API definitions.
 *
 *****************************************************************************/
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define CAMERIC_ISP_GCMONO_LUT_NUM 1024    /* 1024 items */
#define CAMERIC_ISP_GCMONO_PX_NUM 64    /* 64 items */
#define CAMERIC_ISP_GCMONO_DATA_X_NUM 63    /* 63 items */
#define CAMERIC_ISP_GCMONO_DATA_Y_NUM 64    /* 64 items */

typedef uint8_t CamerIcGcmonoLut_ry_t[CAMERIC_ISP_GCMONO_LUT_NUM];
typedef uint32_t CamerIcGcmonoPx_ry_t[CAMERIC_ISP_GCMONO_PX_NUM];
typedef uint32_t CamerIcGcmonoDataX_ry_t[CAMERIC_ISP_GCMONO_DATA_X_NUM];
typedef uint32_t CamerIcGcmonoDataY_ry_t[CAMERIC_ISP_GCMONO_DATA_Y_NUM];

/*****************************************************************************/
/**
 * @brief   Enumeration type to configure CamerIC ISP gcmono module.
 *
 *****************************************************************************/
typedef enum CamerIcIspGCMonoSwitch_ry_e
{
    CAMERIC_ISP_GCMONO_SWITCH_DISABLE       = 0,    /**< Gcmono Disable */
    CAMERIC_ISP_GCMONO_SWITCH_ENABLE        = 1,    /**< Gcmono Enable */
    CAMERIC_ISP_GCMONO_SWITCH_MAX,     				/**< upper border (only for an internal evaluation) */
} CamerIcIspGCMonoSwitch_ry_t;

typedef enum CamerIcIspGCMonoSelect_ry_e
{
    CAMERIC_ISP_GCMONO_SELECT_MODE0       = 0,    /**< Gamma mono path select 0: 10->8 */
    CAMERIC_ISP_GCMONO_SELECT_MODE1        = 1,    /**< Gamma mono path select 1: 12->10*/
    CAMERIC_ISP_GCMONO_SELECT_MAX,
} CamerIcIspGCMonoSelect_ry_t;

/*******************************************************************************
 *
 *          CamerIcIspGcMonoContext_ry_t
 *
 * @brief
 *
 */
typedef struct CamerIcIspGcmonoContext_ry_s
{
    CamerIcIspGCMonoSwitch_ry_t         enabled;                            /**< Gcmono switch enabled */
    CamerIcIspGCMonoSelect_ry_t         mode;                            /**< Gcmono mode select */
    CamerIcGcmonoLut_ry_t               gcmonoLut;                          /**< Gcmono lut table */
    CamerIcGcmonoPx_ry_t                gcmonoPx;                          /**< Gcmono px table */
    CamerIcGcmonoDataX_ry_t               gcmonoDataX;                          /**< Gcmono data x table */
    CamerIcGcmonoDataY_ry_t               gcmonoDataY;                          /**< Gcmono data y table */
} CamerIcIspGcMonoContext_ry_t;

/*****************************************************************************/
/**
 * @brief   This functions enables the CamerIC ISP gcmono
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspGcmonoEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);


/*****************************************************************************/
/**
 * @brief   This functions disables the CamerIC ISP gcmono
 *          module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspGcmonoDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   Get CamerIC ISP Gcmono module status.
 *
 * @param   handle          CamerIc driver handle.
 * @param   pIsEnabled
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/
extern RESULT CamerIcIspGcmonoIsEnabled_ry
(
    CamerIcDrvHandle_ry_t          handle,
    CamerIcIspGCMonoSwitch_ry_t    *pIsEnabled
);

/******************************************************************************
 * CamerIcIspGcMonoConfig_ry()
 * @brief   set lut curve for CamerIC ISP Gcmono module.
 *
 * @param   handle          CamerIc driver handle.
 * @param   *gcMonoCtx      GC Mono Context pointer
 * @param   enable_switch   GC Mono Enable switch
 *
 * @return                  Return the result of the function call.
 * @retval                  RET_SUCCESS
 * @retval                  RET_FAILURE
 *
 *****************************************************************************/

extern RESULT CamerIcIspGcMonoConfig_ry
(
    CamerIcDrvHandle_ry_t              handle,
    CamerIcIspGcMonoContext_ry_t       *gcMonoCtx,
    CamerIcIspGCMonoSwitch_ry_t        enable_switch
);

#ifdef __cplusplus
}
#endif

/* @} cameric_isp_gcmono_drv_api */

/* @endcond */
#endif /* ISP_GCMONO */
#endif /* __CAMERIC_ISP_GCMONO_DRV_RY_API_H__ */

