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
 * @file    cameric_drv_common_ry.h
 *
 * @brief   This file contains all common definition which are used by the
 *          internal modules and the upper layer too.
 *
 *****************************************************************************/
/**
 * @defgroup cameric_drv_common CamerIC driver common API definitions
 * @{
 */
#ifndef __CAMERIC_DRV_COMMON_RY_H__
#define __CAMERIC_DRV_COMMON_RY_H__

#ifdef __cplusplus
extern "C"
{
#endif


#if 1
/******************************************************************************/
/**
 * @brief   A structure to represent a 3x3 matrix.
 *
 *          The nine values are laid out as follows (zero based index):
 *
 *               | 0 1 2 | \n
 *               | 3 4 5 | \n
 *               | 6 7 8 | \n
 *
 * @note    The values are represented as float numbers.
 *
 *****************************************************************************/
typedef struct CamerIc3x3FloatMatrix_ry_s
{
    float fCoeff[9U];               /**< array of 3x3 float values */
} CamerIc3x3FloatMatrix_ry_t;
#endif



/******************************************************************************/
/**
 * @brief   A structure to represent a 5x5 matrix.
 *
 *          The 25 values are laid out as follows (zero based index):
 *
 *               | 00 01 02 03 04 | \n
 *               | 05 06 07 08 09 | \n
 *               | 10 11 12 13 14 | \n
 *               | 15 16 17 18 19 | \n
 *               | 20 21 22 23 24 | \n
 *
 * @note    The 25 values are represented as float numbers.
 *
 *****************************************************************************/
typedef struct CamerIc5x5FloatMatrix_ry_s
{
    float fCoeff[25U];              /**< array of 5x5 float values */
} CamerIc5x5FloatMatrix_ry_t;



/******************************************************************************/
/**
 * @brief   A structure to represent a 3x3 matrix.
 *
 *          The nine values are laid out as follows (zero based index):
 *
 *               | 0 1 2 | \n
 *               | 3 4 5 | \n
 *               | 6 7 8 | \n
 *
 * @note    The values are represented as fix point numbers.
 *
 *****************************************************************************/
typedef struct CamerIc3x3Matrix_ry_s
{
    uint32_t    Coeff[9U];               /**< array of 3x3 float values */
} CamerIc3x3Matrix_ry_t;



/*******************************************************************************
 **
 * @brief   A structure/tupple to represent gain values for four (R,Gr,Gb,B)
 *          channels.
 *
 * @note    The gain values are represented as fix point numbers.
 *
 *****************************************************************************/
typedef struct CamerIcGains_ry_s
{
    uint16_t Red;                       /**< gain value for the red channel */
    uint16_t GreenR;                    /**< gain value for the green-red channel */
    uint16_t GreenB;                    /**< gain value for the green-blue channel */
    uint16_t Blue;                      /**< gain value for the blue channel */
} CamerIcGains_ry_t;



/******************************************************************************/
/**
 * @brief   A structure/tupple to represent offset values for three (R,G,B)
 *          channels.
 *
 * @note    The offset values are represented as 2's complement integer.
 *          Number ranging from -2048 (0x800) to 2047 (0x7FF).
 *          0 is represented as 0x000.
 *
 *****************************************************************************/
typedef struct CamerIcXTalkOffset_ry_s
{
    uint16_t Red;                       /**< offset value for the red channel */
    uint16_t Green;                     /**< offset value for the green channel */
    uint16_t Blue;                      /**< offset value for the blue channel */
} CamerIcXTalkOffset_ry_t;



/******************************************************************************/
/**
 * @brief   A structure to represent a general purpose window. The window is
 *          spanned by a horizontal and vertical offset, counting from zero,
 *          the width and the height.
 *
 * @note    The windows points are represented by 16-bit unsigned integer
 *          numbers.
 *
 *****************************************************************************/
typedef struct CamerIcWindow_ry_s
{
    uint16_t    hOffset;
    uint16_t    vOffset;
    uint16_t    width;
    uint16_t    height;
} CamerIcWindow_ry_t;



/*****************************************************************************/
/**
 * @brief   This function initialize/configures a general purpose window.
 *
 * @param   pWnd            pointer to a window to initialize
 * @param   hOffset         horizontal offset (starting at zero)
 * @param   vOffset         vertical offset (starting at zero)
 * @param   height          window height
 * @param   width           window width
 *
 *****************************************************************************/
static inline void SetCamerIcWindow_ry
(
    CamerIcWindow_ry_t *pWnd,
    const uint16_t  hOffset,
    const uint16_t  vOffset,
    const uint16_t  height,
    const uint16_t  width
)
{
    if ( pWnd != NULL )
    {
        pWnd->hOffset   = hOffset;
        pWnd->vOffset   = vOffset;
        pWnd->height    = height;
        pWnd->width     = width;
    }
}



#ifdef __cplusplus
}
#endif

/* @} cameric_drv_common */

#endif /* __CAMERIC_DRV_COMMON_RY_H__ */

