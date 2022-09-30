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

struct Dg : Engine {
  enum {
    Begin = Engine::Dg * Engine::Step,

    ConfigGet,
    ConfigSet,
    EnableGet,
    EnableSet,

    End,
  };

  Dg(t_camera::Camera *pCamera) : Engine(pCamera) {
    idBegin = Begin;
    idEnd = End;
  }

  Dg &process(Json::Value const &jQuery, Json::Value &jResponse) override;

  Dg &configGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dg &configSet(Json::Value const &jQuery, Json::Value &jResponse);

  Dg &enableGet(Json::Value const &jQuery, Json::Value &jResponse);
  Dg &enableSet(Json::Value const &jQuery, Json::Value &jResponse);
};

} // namespace t_shell
