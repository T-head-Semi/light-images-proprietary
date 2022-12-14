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
#ifdef WIN32

#include <windows_ry.h>
#include <ebase/types_ry.h>


#ifdef __cplusplus
extern "C"
{
#endif



#ifdef WIN32_KERNEL
#define OSLAYER_KERNEL
#endif


typedef int32_t (*osThreadFunc)(void *);
typedef int32_t (*osIsrFunc)(void *);
typedef int32_t (*osDpcFunc)(void *);


#ifdef OSLAYER_EVENT
/*****************************************************************************/
/*  @brief  Event object (Win32 Version) of OS Abstraction Layer */
typedef struct _osEvent
{
#ifdef OSLAYER_KERNEL
    KEVENT event;
#else
    HANDLE handle;
#endif
} osEvent;
#endif /* OSLAYER_EVENT */


#ifdef OSLAYER_MUTEX
/*****************************************************************************/
/*  @brief  Mutex object (Win32 Version) of OS Abstraction Layer */
typedef struct _osMutex
{
#ifdef OSLAYER_KERNEL
    KMUTEX mutex;
#else
    CRITICAL_SECTION sCritSection;
#endif
} osMutex;
#endif /* OSLAYER_MUTEX */


#ifdef OSLAYER_SEMAPHORE
/*****************************************************************************/
/*  @brief  Semaphore object (Win32 Version) of OS Abstraction Layer */
typedef struct _osSemaphore
{
#ifdef OSLAYER_KERNEL
    KSEMAPHORE sem;
#else
    HANDLE handle;
#endif
} osSemaphore;
#endif /* OSLAYER_SEMAPHORE */


#ifdef OSLAYER_THREAD
/*****************************************************************************/
/*  @brief  Thread object (Win32 Version) of OS Abstraction Layer */
typedef struct _osThread
{
#ifdef OSLAYER_KERNEL
    KTHREAD handle;
#else
    HANDLE handle;
    osMutex access_mut;
    int32_t wait_count;
#endif
} osThread;
#endif /* OSLAYER_THREAD */


#ifdef OSLAYER_MISC
#ifdef OSLAYER_KERNEL
/*****************************************************************************/
/*  @brief  Spin Lock object (Win32 Kernel Version only) of OS Abstraction */
/*          Layer */
typedef struct _osSpinLock
{
    KSPIN_LOCK lock;
} osSpinLock;
#endif /* OSLAYER_KERNEL */
#endif /* OSLAYER_MISC   */


#ifdef __cplusplus
}
#endif



#endif /* WIN32 */
