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

//! Powered by Yong Yang

#pragma once

#include "engine.hpp"

namespace t_shell {

struct Filter : Engine {
  enum {
    Begin = Engine::Filter * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,
    StatusGet,
    TableGet,
    TableSet,

    End,
  };

  Filter(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Filter &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Filter &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Filter &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Filter &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Filter &enableSet(Json::Value const &jQuery, Json::Value &jResponse);

  Filter &statusGet(Json::Value const &jQuery, Json::Value &jResponse);

  Filter &tableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Filter &tableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
