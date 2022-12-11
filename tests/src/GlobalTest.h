// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 11.12.2022.
//

#ifndef TOMLCONFIG_GLOBALTEST_H
#define TOMLCONFIG_GLOBALTEST_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class GlobalTest : public ::testing::Test {
protected:
    void SetUp() override;
    void TearDown() override;
};

#endif //TOMLCONFIG_GLOBALTEST_H
