// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_NULLRESOURCETEST_H
#define TOMLCONFIG_NULLRESOURCETEST_H

#include "resource/NullResource.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace tcfg { }
using namespace tcfg;

class NullResourceTest : public ::testing::Test {
protected:
    NullResource& resource = NullResource::get_instance();
    void SetUp() override;
    void TearDown() override;
};

#endif //TOMLCONFIG_NULLRESOURCETEST_H
