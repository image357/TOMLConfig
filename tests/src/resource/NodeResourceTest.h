// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 17.12.2022.
//

#ifndef TOMLCONFIG_NODERESOURCETEST_H
#define TOMLCONFIG_NODERESOURCETEST_H

#include "resource/NodeResource.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

namespace tcfg { }
using namespace tcfg;

class NodeResourceTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;

    void set_parent_helper(NodeResource& resource, IResource* parent_resource)
    {
        resource.set_parent(parent_resource);
    }
};

#endif //TOMLCONFIG_NODERESOURCETEST_H
