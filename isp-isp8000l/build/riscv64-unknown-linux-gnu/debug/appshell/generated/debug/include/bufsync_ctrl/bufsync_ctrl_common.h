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
 * @file bufsync_ctrl_common.h
 *
 * @brief
 *   ADD_DESCRIPTION_HERE
 *
 *****************************************************************************/
/**
 * @page module_name_page Module Name
 * Describe here what this module does.
 *
 * For a detailed list of functions and implementation detail refer to:
 * - @ref module_name
 *
 * @defgroup module_name Module Name
 * @{
 *
 */
#ifndef __BUFSYNC_CTRL_COMMON_H__
#define __BUFSYNC_CTRL_COMMON_H__

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Handle to mom ctrl process context.
 *
 * @note
 *
 */
typedef struct BufSyncCtrlContext_s *BufSyncCtrlHandle_t;


/**
 * @brief
 *
 * @note
 *
 */
enum BufSyncCtrlCommand_e
{
    BUFSYNC_CTRL_CMD_INVALID        = 0,
    BUFSYNC_CTRL_CMD_START          = 1,
    BUFSYNC_CTRL_CMD_STOP           = 2,
    BUFSYNC_CTRL_CMD_SHUTDOWN       = 3,
    BUFSYNC_CTRL_CMD_PROCESS_BUFFER = 4,
    BUFSYNC_CTRL_CMD_MAX
};



/**
 * @brief
 *
 * @note
 *
 */
typedef int32_t BufSyncCtrlCmdId_t;



/**
 *  @brief Event signalling callback
 *
 *  Callback for signalling some event which could require application interaction.
 *  The eventId (see @ref momEventId_t) identifies the event and the content of
 *  pParam depends on the event ID.
 *
 */
typedef void (* BufSyncCtrlCompletionCb_t)
(
    BufSyncCtrlCmdId_t  CmdId,          /**< The Commad Id of the notifying event */
    RESULT              result,         /**< Result of the executed command */
    const void          *pUserContext   /**< User data pointer that was passed on chain creation */
);



typedef void (*BufSyncCtrlBufferCb_t)
(
    int32_t             path,
    MediaBuffer_t       *pMediaBuffer,
    void                *pBufferCbCtx
);



typedef struct BufSyncCtrlBuffer_s
{
    BufSyncCtrlBufferCb_t   fpCallback;      /**< Buffer callback */
    void                    *pBufferCbCtx;   /**< Pointer to user context to pass to callback */
} BufSyncCtrlBuffer_t;



#ifdef __cplusplus
}
#endif

/* @} module_name*/

#endif /* __BUFSYNC_CTRL_COMMON_H__ */

