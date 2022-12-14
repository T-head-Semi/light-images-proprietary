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

#ifndef __CAMERIC_SIMP_DRV_RY_API_H__
#define __CAMERIC_SIMP_DRV_RY_API_H__

/**
 * @cond    cameric_simp
 *
 * @file    cameric_simp_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC SI driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_simp_drv_api CamerIC SI Driver API definitions
 * @{
 *
 * The Super Impose module overlays an image with a bitmap from the main memory
 * (see Figure). Color of the transparent area in superimpose bitmap is configurable.
 * So the camera picture interfuses through the transparent area. Furthermore the
 * Superimpose block is able to position a bitmap with the appropriate coordinates
 * over the camera image range.
 *
 * @image html si-usecase.png "Superimpose Effect with the CamerIC SI driver" width=\textwidth
 * @image latex si-usecase.png "Superimpose Effect with the CamerIC SI driver" width=\textwidth
 *
 * The Superimpose module gets picture data in YCbCr 4:2:2 formats from Image Effects module.
 * The Memory Interface module delivers the Y, Cb and Cr pixel components of the superimpose
 * bitmap. Within the common area of the two pictures, output pixel data is determined by the
 * bitmap from main memory or by the image from image effect module. The overlaid picture is
 * sent to the Y/C splitter module.
 * @if CAMERIC_LITE
 *
 * @image html si_lite.png "Overview of the CamerIC SI driver" width=\textwidth
 * @image latex si_lite.png "Overview of the CamerIC SI driver" width=\textwidth
 *
 * @endif
 *
 * @if CAMERIC_FULL
 *
 * @image html si.png "Overview of the CamerIC SI driver" width=\textwidth
 * @image latex si.png "Overview of the CamerIC SI driver" width=\textwidth
 *
 * @endif
 *
 */
#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the Super-Impose transparency mode.
 *
 *****************************************************************************/
typedef enum CamerIcSimpTransparencyMode_ry_e
{
    CAMERIC_SIMP_TRANSPARENCY_MODE_INVALID  = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_SIMP_TRANSPARENCY_MODE_ENABLED  = 1,        /**< transparency mode disabled */
    CAMERIC_SIMP_TRANSPARENCY_MODE_DISABLED = 2,        /**< transparency mode disabled */
    CAMERIC_SIMP_TRANSPARENCY_MODE_MAX                    /**< upper border (only for an internal evaluation) */
} CamerIcSimpTransparencyMode_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to configure the Super-Impose reference mode.
 *
 * @note    The reference image defines the size of the output image.
 *
 *****************************************************************************/
typedef enum CamerIcSimpReferenceMode_ry_e
{
    CAMERIC_SIMP_REFERENCE_MODE_INVALID     = 0,        /**< lower border (only for an internal evaluation) */
    CAMERIC_SIMP_REFERENCE_MODE_FROM_MEMORY = 1,        /**< reference images comes from main memory */
    CAMERIC_SIMP_REFERENCE_MODE_FROM_CAMERA = 2,        /**< reference images comes from camera (Image Effect module) */
    CAMERIC_SIMP_REFERENCE_MODE_MAX                     /**< upper border (only for an internal evaluation) */
} CamerIcSimpReferenceMode_ry_t;



/******************************************************************************/
/**
 * @brief   Structure to configure the Super-Impose module.
 *
 *****************************************************************************/
typedef struct CamerIcSimpConfig_ry_s
{
    CamerIcSimpTransparencyMode_ry_t   TransparencyMode;   /**< transparency mode */
    CamerIcSimpReferenceMode_ry_t      ReferenceMode;      /**< reference mode */

    uint16_t                        OffsetX;            /**< x offset */
    uint16_t                        OffsetY;            /**< y offset */

    uint8_t                         Y;                  /**< Y-component of transparent color */
    uint8_t                         Cb;                 /**< Cb-component of transparent color */
    uint8_t                         Cr;                 /**< Cr-component of transparent color */
} CamerIcSimpConfig_ry_t;



/*****************************************************************************/
/**
 * @brief   This function enables the Super-Impose module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcSimpEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function disables the Super-Impose module (bypass the super
 *          impose module).
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcSimpDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function returns the status of the Super-Impose module.
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is a NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcSimpIsEnabled_ry
(
    CamerIcDrvHandle_ry_t      handle,
    bool_t                  *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function configures the Super-Impose module
 *
 * @param   handle              CamerIC driver handle
 * @param   pConfig             pointer to image effects configuration structure
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NOTSUPP         selected working mode is not supported
 * @retval  RET_NULL_POINTER    null pointer
 *
 *****************************************************************************/
extern RESULT CamerIcSimpConfigure_ry
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcSimpConfig_ry_t     *pConfig
);



#ifdef __cplusplus
}
#endif

/* @} cameric_simp_drv_api */

/* @endcond */

#endif /* __CAMERIC_SIMP_DRV_RY_API_H__ */

