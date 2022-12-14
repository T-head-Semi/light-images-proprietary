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
 * Module    : Operating System Abstraction Layer
 *
 * Hierarchy :
 *
 * Purpose   : Encapsulates and abstracts services from different operating
 *             system, including user-mode as well as kernel-mode services.
 ******************************************************************************/
#ifdef UCOSII

#include <stdlib.h>
#include <ucos_ii_ry.h>
#include <ebase/types_ry.h>
#include <ebase/dct_assert_ry.h>

#ifdef __cplusplus
extern "C"
{
#endif

#define UCOSII_STACK_SIZE   1024
#define OSLAYER_ASSERT      DCT_ASSERT

typedef int32_t (*osThreadFunc)(void *);
typedef int32_t (*osIsrFunc)(void *);
typedef int32_t (*osDpcFunc)(void *);


#ifdef OSLAYER_EVENT
/*****************************************************************************/
/*  @brief  Event object (Linux Version) of OS Abstraction Layer */
typedef struct _osEvent
{
    OS_FLAG_GRP*    pFlagGroup;
    INT8U           wait_type;
} osEvent;
#endif /* OSLAYER_EVENT */


#ifdef OSLAYER_MUTEX
/*****************************************************************************/
/*  @brief  Mutex object (Linux Version) of OS Abstraction Layer */
typedef struct _osMutex
{
    OS_EVENT*   semaphore;
} osMutex;
#endif /* OSLAYER_MUTEX */


#ifdef OSLAYER_SEMAPHORE
/*****************************************************************************/
/*  @brief  Semaphore object (Linux Version) of OS Abstraction Layer */
typedef struct _osSemaphore
{
    OS_EVENT*   semaphore;
} osSemaphore;
#endif /* OSLAYER_SEMAPHORE */


#ifdef OSLAYER_THREAD
/*****************************************************************************/
/*  @brief  Thread object (Linux Version) of OS Abstraction Layer */
typedef struct _osThread
{
    int32_t (*pThreadFunc)(void *);
    void*   p_arg;
    OS_STK* stack;
    INT32U  stackSize;
    INT8U   prio;
} osThread;
#endif /* OSLAYER_THREAD */

#ifdef __cplusplus
}
#endif



#endif /* UCOSII */
