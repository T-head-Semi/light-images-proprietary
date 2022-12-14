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

#ifndef __CAMERIC_ISP_BLS_DRV_RY_API_H__
#define __CAMERIC_ISP_BLS_DRV_RY_API_H__

/**
 * @cond    cameric_isp_bls
 *
 * @file    cameric_isp_bls_drv_ry_api.h
 *
 * @brief   This file contains the CamerIC ISP BLS driver API definitions.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_isp_bls_drv_api CamerIC ISP BLS driver API definitions
 * @{
 *
 * The BLS (black level substraction) module is able to correct the image sensor
 * values via subtracting or adding an offset to the values. To be able to
 * calculate the correct settings the BLS module supports up to two measurement
 * windows. The Black Level Subtraction driver serves as an abstraction layer,
 * so the application does not need to know which bit has to be set where in the
 * registers of the BLS module.
 *
 * @image html bls.png "Overview of the CamerIC ISP BLS driver" width=\textwidth
 * @image latex bls.png "Overview of the CamerIC ISP BLS driver" width=\textwidth
 *
 * There are two main use cases for the BLS module (@ref CamerIcIspBlsMode_ry_e):
 *
 * @arg Automatic mode of the BLS module. Here the mean measured values
 * of the BLS module are used as subtraction values for the image sensor
 * data. The disadvantage is here that the digitized values are manipulated.
 *
 * @arg Manual mode of the BLS module. In the case the ISI sensor driver
 * supports to do the black level subtraction before the values are
 * digitized the noise of the image sensor data will be reduced also.
 * Then the BLS module could be used only for measurements and the mean
 * measured values are given to the ISI driver to calculate appropriate
 * settings inside the image sensor.
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
 * @brief   Enumeration type to configure ISP BLS module substraction mode.
 *
 *****************************************************************************/
typedef enum CamerIcIspBlsMode_ry_e
{
    CAMERIC_ISP_BLS_MODE_INVALID                = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_BLS_MODE_USE_FIX_VALUES         = 1,    /**< substract fix values */
    CAMERIC_ISP_BLS_MODE_USE_MEASURED_VALUES    = 2,    /**< substract measured values */
    CAMERIC_ISP_BLS_MODE_MAX                            /**< upper border (only for an internal evaluation) */
} CamerIcIspBlsMode_ry_t;



/******************************************************************************/
/**
 * @brief   Enumeration type to identify the ISP BLS measuring window.
 *
 *****************************************************************************/
typedef enum CamerIcIspBlsWindowId_ry_e
{
    CAMERIC_ISP_BLS_WINDOW_INVALID  = 0,    /**< lower border (only for an internal evaluation) */
    CAMERIC_ISP_BLS_WINDOW_1        = 1,    /**< Window 1 (1st window) */
    CAMERIC_ISP_BLS_WINDOW_2        = 2,    /**< Window 2 (2nd window) */
    CAMERIC_ISP_BLS_WINDOW_MAX              /**< upper border (only for an internal evaluation) */
} CamerIcIspBlsWindowId_ry_t;



/*****************************************************************************/
/**
 * @brief   This function enables the ISP BLS module.
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsEnable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function disables the ISP BLS module (bypass the black level
 *          processing).
 *
 * @param   handle              CamerIc driver handle
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsDisable_ry
(
    CamerIcDrvHandle_ry_t handle
);



/*****************************************************************************/
/**
 * @brief   This function
 *
 * @param   handle              CamerIc driver handle
 * @param   pIsEnabled          Pointer to value to store current state
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_NULL_POINTER    pIsEnabled is NULL pointer
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsIsEnabled_ry
(
    CamerIcDrvHandle_ry_t  handle,
    bool_t              *pIsEnabled
);



/*****************************************************************************/
/**
 * @brief   This function sets the substraction mode of the ISP BLS module.
 *
 * @param   handle              CamerIc driver handle
 * @param   submode             Substraction mode to configure (@ref
 *                              CamerIcIspBlsMode_ry_e).
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_OUTOFRANGE      given substraction mode not valid
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsSetSubstractionMode_ry
(
    CamerIcDrvHandle_ry_t          handle,
    const CamerIcIspBlsMode_ry_t   submode
);



/*****************************************************************************/
/**
 * @brief   This function sets the fixed black level substraction values
 *          for the color channels.
 *
 * @note    The assignment of the values for A, B, C and D to R, G, G and B
 *          pattern depends on the position and offset of the input acquisition
 *          window.
 *
 *          The position [0,0] is always assigned to A, correlatively [0,1]
 *          is assigned to B, [1,0] to C and [1,1] to D.
 *
 * @param   handle              CamerIc driver handle
 * @param   A                   black-level substraction value A
 * @param   B                   black-level substraction value B
 * @param   C                   black-level substraction value C
 * @param   D                   black-level substraction value D
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_WRONG_CONFIG    a bayer-pattern was not configured
 * @retval  RET_OUTOFRANGE      substraction value is to large
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsSetBlackLevel_ry
(
    CamerIcDrvHandle_ry_t  handle,
    const uint16_t      A,
    const uint16_t      B,
    const uint16_t      C,
    const uint16_t      D
);



/*****************************************************************************/
/**
 * @brief   This function reads out the current configured fixed black level
 *          substraction values.
 *
 * @note    The assignment of the values for A, B, C and D to R, G, G and B
 *          pattern depends on the position and offset of the input acquisition
 *          window.
 *
 *          The position [0,0] is always assigned to A, correlatively [0,1]
 *          is assigned to B, [1,0] to C and [1,1] to D.
 *
 * @param   handle              CamerIc driver handle
 * @param   A                   pointer to store the black-level substraction value A
 * @param   B                   pointer to store the black-level substraction value B
 * @param   C                   pointer to store the black-level substraction value C
 * @param   D                   pointer to store the black-level substraction value D
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsGetBlackLevel_ry
(
    CamerIcDrvHandle_ry_t  handle,
    uint16_t            *A,
    uint16_t            *B,
    uint16_t            *C,
    uint16_t            *D
);



/*****************************************************************************/
/**
 * @brief   This function sets the position and size of a the black-level
 *          measurement window in the CamerIC ISP BLS module.
 *
 * @param   handle              CamerIc driver handle
 * @param   WdwId               window identifier (@ref CamerIcIspBlsWindowId_ry_e)
 * @param   x                   start x position of measuring window
 * @param   y                   start y position of measuring window
 * @param   width               width of measuring window
 * @param   height              height of measuring window
 *
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         Configuration successfully applied
 * @retval  RET_INVALID_PARM    invalid window identifier
 * @retval  RET_WRONG_HANDLE    handle is invalid
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsSetMeasuringWindow
(
    CamerIcDrvHandle_ry_t      handle,
    CamerIcIspBlsWindowId_ry_t WdwId,
    const uint16_t          x,
    const uint16_t          y,
    const uint16_t          width,
    const uint16_t          height
);



/*****************************************************************************/
/**
 * @brief   This function reads out the current measured black level
 *          substraction values.
 *
 * @note    The assignment of the values for A, B, C and D to R, G, G and B
 *          pattern depends on the position and offset of the input acquisition
 *          window.
 *
 *          The position [0,0] is always assigned to A, correlatively [0,1]
 *          is assigned to B, [1,0] to C and [1,1] to D.
 *
 * @param   handle              CamerIc driver handle
 * @param   A                   pointer to store the black-level substraction value A
 * @param   B                   pointer to store the black-level substraction value B
 * @param   C                   pointer to store the black-level substraction value C
 * @param   D                   pointer to store the black-level substraction value D
 *
 * @return                      Return the result of the function call.
 * @retval  RET_SUCCESS         operation succeded
 * @retval  RET_WRONG_HANDLE    handle is invalid
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
extern RESULT CamerIcIspBlsGetMeasuredBlackLevel
(
    CamerIcDrvHandle_ry_t  handle,
    uint16_t            *A,
    uint16_t            *B,
    uint16_t            *C,
    uint16_t            *D
);



#ifdef __cplusplus
}
#endif

/* @} cameric_isp_bls_drv_api */

/* @endcond */

#endif /* __CAMERIC_ISP_BLS_DRV_RY_API_H__ */

