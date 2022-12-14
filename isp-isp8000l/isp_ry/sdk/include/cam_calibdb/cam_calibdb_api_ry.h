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
 * @file cam_calibdb_api.h
 *
 * @brief
 *   Interface description of the CamEngine.
 *
 *****************************************************************************/
/**
 * @mainpage General Concept
 *
 * @defgroup cam_calibdb_api CamCalibDb API
 * @{
 */

#ifndef __CAM_CALIBDB_API_H__
#define __CAM_CALIBDB_API_H__

#include <ebase/types_ry.h>
#include <common/return_codes_ry.h>
#include <common/cam_types_ry.h>

#include "cam_calibdb_common_ry.h"

#ifdef __cplusplus
extern "C"
{
#endif


/*******************************************************************************
 * @brief   Handle to a CamCalibDb instance.
 *
 *****************************************************************************/
typedef struct CamCalibDbContext_s *CamCalibDbHandle_t;



/*****************************************************************************/
/**
 * @brief   The function creates and initializes a CamCalibDb instance.
 *
 * @param   pConfig             Instance configuration structure.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_INVALID_PARM    invalid configuration
 * @retval  RET_OUTOFRANGE      a configuration parameter is out of range
 * @retval  RET_WRONG_HANDLE    invalid HAL handle
 * @retval  RET_OUTOFMEM        not enough memory available
 *
 *****************************************************************************/
RESULT CamCalibDbCreate
(
    CamCalibDbHandle_t  *hCamCalibDb
);



/*****************************************************************************/
/**
 * @brief   This function releases a CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbRelease
(
    CamCalibDbHandle_t  *hCamCalibDb
);



/*****************************************************************************/
/**
 * @brief   The function clears the CamCalibDb instance.
 *
 * @param   pConfig             Instance configuration structure.
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_INVALID_PARM    invalid configuration
 * @retval  RET_OUTOFRANGE      a configuration parameter is out of range
 * @retval  RET_WRONG_HANDLE    invalid HAL handle
 * @retval  RET_OUTOFMEM        not enough memory available
 *
 *****************************************************************************/
RESULT CamCalibDbClear
(
    CamCalibDbHandle_t  hCamCalibDb
);



/*****************************************************************************/
/**
 * @brief   This function stores a DB meta-data in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbSetMetaData
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCalibDbMetaData_t    *pParam
);



/*****************************************************************************/
/**
 * @brief   This function stores a DB meta-data in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbSetSystemData
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCalibSystemData_t    *pData
);



/*****************************************************************************/
/**
 * @brief   This function stores a DB meta-data in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetSystemData
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCalibSystemData_t    *pData
);



/*****************************************************************************/
/**
 * @brief   This function adds a resolution in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddRes             Resolution to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbAddResolution
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamResolution_t         *pAddRes
);



/*****************************************************************************/
/**
 * @brief   This function returns the number of added resolutions.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of resolution
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetNoOfResolutions
(
    CamCalibDbHandle_t  hCamCalibDb,
    int32_t             *no
);



/*****************************************************************************/
/**
 * @brief   This function returns a resolution identified by a given name.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of resolution
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetResolutionByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamResolutionName_t     name,
    CamResolution_t         **pResolution
);



/*****************************************************************************/
/**
 * @brief   This function returns the resolution identified by a given height,
 *          width and framerate
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of resolution
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetResolutionByWidthHeightFrameRate
(
    CamCalibDbHandle_t      hCamCalibDb,
    const uint16_t          width,
    const uint16_t          height,
    const uint16_t          framerate,
    CamResolution_t         **pResolution
);



/*****************************************************************************/
/**
 * @brief   This function returns the resolution name identified by a given
 *          height, width and framerate
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of resolution
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetResolutionNameByWidthHeightFrameRate
(
    CamCalibDbHandle_t      hCamCalibDb,
    const uint16_t          width,
    const uint16_t          height,
    const uint16_t          framerate,
    CamResolutionName_t     *pResolutionName
);



RESULT CamCalibDbGetResolutionIdxByName
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   name,
    int32_t                     *pIdx
);



/*****************************************************************************/
/**
 * @brief   This function adds a global AWB profile in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddAwbGlobal       AWB profile to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbAddAwbGlobal
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamCalibAwbGlobal_t *pAddAwbGlobal
);



/*****************************************************************************/
/**
 * @brief   This function returns a global AWB profile in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddAwbGlobal       AWB profile to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetAwbGlobalByResolution
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   ResName,
    CamCalibAwbGlobal_t         **pAwbGlobal
);



/*****************************************************************************/
/**
 * @brief   This function adds the global AEC configuration to the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddAecGlobal       Reference of AEC global configuration to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbAddAecGlobal
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCalibAecGlobal_t     *pAddAecGlobal
);



/*****************************************************************************/
/**
 * @brief   This function returns the global AEC configuration from the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   ppAecGlobal         Reference of pointer to AEC global configuration
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetAecGlobal
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCalibAecGlobal_t     **ppAecGlobal
);



/*****************************************************************************/
/**
 * @brief   This function adds an ECM profile to the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddEcmProfile      Reference of ECM profile to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbAddEcmProfile
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfile_t         *pAddEcmProfile
);



/*****************************************************************************/
/**
 * @brief   This function returns the number of added ECM profiles.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   no                  Reference to count storage
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetNoOfEcmProfiles
(
    CamCalibDbHandle_t  hCamCalibDb,
    int32_t             *no
);



/*****************************************************************************/
/**
 * @brief   This function returns the requested ECM profile from the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   AecProfileName      Name of ECM profile to retrieve
 * @param   ppAecProfile        Reference of pointer to retrieved ECM profile
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetEcmProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfileName_t     EcmProfileName,
    CamEcmProfile_t         **ppEcmProfile
);



/*****************************************************************************/
/**
 * @brief   This function returns the ECM profile identified by a given index.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   idx                 Index of ECM profile to retrieve
 * @param   ppAecProfile        Reference of pointer to retrieved ECM profile
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetEcmProfileByIdx
(
    CamCalibDbHandle_t      hCamCalibDb,
    const uint32_t          idx,
    CamEcmProfile_t         **ppEcmProfile
);



/*****************************************************************************/
/**
 * @brief   This function adds an ECM scheme to the given external ECM profile.
 *
 * @param   pAecProfile         Reference to ECM profile to add ECM scheme to
 * @param   pAddEcScheme        Reference to ECM scheme to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbAddEcmSchemeExtern
(
    CamEcmProfile_t         *pEcmProfile,
    CamEcmScheme_t          *pAddEcmScheme
);



/*****************************************************************************/
/**
 * @brief   This function adds an ECM scheme to the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAecProfile         Reference to ECM profile to add ECM scheme to
 * @param   pAddEcScheme        Reference to ECM scheme to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbAddEcmScheme
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfile_t         *pEcmProfile,
    CamEcmScheme_t          *pAddEcmScheme
);



/*****************************************************************************/
/**
 * @brief   This function returns the number of added ECM schemes.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAecProfile         Reference to ECM profile to count ECM schemes for
 * @param   no                  Reference to count storage
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetNoOfEcmSchemes
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfile_t         *pEcmProfile,
    int32_t                 *no
);


/*****************************************************************************/
/**
 * @brief   This function returns the requested ECM scheme for the given AEC
 *          profile from the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAecProfile         Reference of ECM profile for which the ECM scheme is to be retrieved
 * @param   EcSchemeName        Name of ECM scheme to retrieve
 * @param   ppEcScheme          Reference of pointer to retrieved ECM scheme
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetEcmSchemeByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfile_t         *pEcmProfile,
    CamEcmSchemeName_t      EcmSchemeName,
    CamEcmScheme_t          **ppEcmScheme
);



/*****************************************************************************/
/**
 * @brief   This function returns for the given ECM profile the ECM scheme
 *          identified by a given index.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAecProfile         Reference of ECM profile for which the ECM scheme is to be retrieved
 * @param   idx                 Index of ECM scheme to retrieve
 * @param   ppEcScheme          Reference of pointer to retrieved ECM scheme
 *
 * @return  Return the result of the function call.
 * @retval  RET_SUCCESS         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_INVALID_PARM    invalid parameter
 *
 *****************************************************************************/
RESULT CamCalibDbGetEcmSchemeByIdx
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamEcmProfile_t         *pEcmProfile,
    const uint32_t          idx,
    CamEcmScheme_t          **ppEcmScheme
);



/*****************************************************************************/
/**
 * @brief   This function returns the number of added illuminations.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of resolution
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetNoOfIlluminations
(
    CamCalibDbHandle_t  hCamCalibDb,
    int32_t             *no
);



/*****************************************************************************/
/**
 * @brief   This function adds an illumination in the CamCalibDb instance.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   pAddIllu            illumination to add
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbAddIllumination
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamIlluProfile_t    *pAddIllu
);



/*****************************************************************************/
/**
 * @brief   This function returns an illumination identified by a given name.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of illumination
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetIlluminationByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamIlluminationName_t   name,
    CamIlluProfile_t        **pIllumination
);



/*****************************************************************************/
/**
 * @brief   This function returns an illumination identified by a given index.
 *
 * @param   hCamCalibDb         Handle to the CamCalibDb instance.
 * @param   name                name/identifier of illumination
 * @param   pointer             pointer to an illumination pointer
 *
 * @return  Return the result of the function call.
 * @retval  RET_PENDING         function succeed
 * @retval  RET_WRONG_HANDLE    invalid instance handle
 * @retval  RET_WRONG_STATE     instance is in wrong state to shutdown
 *
 *****************************************************************************/
RESULT CamCalibDbGetIlluminationByIdx
(
    CamCalibDbHandle_t  hCamCalibDb,
    const uint32_t      idx,
    CamIlluProfile_t    **pIllumination
);



RESULT CamCalibDbAddLscProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamLscProfile_t     *pAddLsc
);



RESULT CamCalibDbGetLscProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamLscProfileName_t     name,
    CamLscProfile_t         **pLscProfile
);



RESULT CamCalibDbAddCcProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamCcProfile_t      *pAddCc
);



RESULT CamCalibDbGetCcProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamLscProfileName_t     name,
    CamCcProfile_t          **pCcProfile
);


RESULT CamCalibDbAddBlsProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamBlsProfile_t     *pAddBls
);



RESULT CamCalibDbGetBlsProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamBlsProfileName_t     name,
    CamBlsProfile_t         **pBlsProfile
);



RESULT CamCalibDbGetBlsProfileByResolution
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   ResName,
    CamBlsProfile_t             **pBlsProfile
);



RESULT CamCalibDbAddCacProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamCacProfile_t     *pAddCac
);

RESULT CamCalibDbGetCacProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamCacProfileName_t     name,
    CamCacProfile_t         **pCacProfile
);

RESULT CamCalibDbGetCacProfileByResolution
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   ResName,
    CamCacProfile_t             **pCacProfile
);

RESULT CamCalibDbAddDpfProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamDpfProfile_t     *pAddDpf
);

RESULT CamCalibDbGetDpfProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamDpfProfileName_t     name,
    CamDpfProfile_t         **pDpfProfile
);

RESULT CamCalibDbGetDpfProfileByResolution
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   ResName,
    CamDpfProfile_t             **pDpfProfile
);

RESULT CamCalibDbAddDpccProfile
(
    CamCalibDbHandle_t  hCamCalibDb,
    CamDpccProfile_t    *pAddDpcc
);

RESULT CamCalibDbGetDpccProfileByName
(
    CamCalibDbHandle_t      hCamCalibDb,
    CamDpccProfileName_t    name,
    CamDpccProfile_t        **pDpccProfile
);

RESULT CamCalibDbGetDpccProfileByResolution
(
    CamCalibDbHandle_t          hCamCalibDb,
    const CamResolutionName_t   ResName,
    CamDpccProfile_t            **pDpccProfile
);


#ifdef __cplusplus
}
#endif


/* @} cam_calibdb_api */


#endif /* __CAM_CALIBDB_API_H__ */

