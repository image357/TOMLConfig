// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#include "NullResourceTest.h"

void NullResourceTest::SetUp()
{
    Test::SetUp();
}

void NullResourceTest::TearDown()
{
    Test::TearDown();
}

TEST_F(NullResourceTest, testName)
{
    ASSERT_EQ(resource.get_name(), "");
}

TEST_F(NullResourceTest, testPath)
{
    ASSERT_EQ(resource.get_path(), "");
}

TEST_F(NullResourceTest, testType)
{
    ASSERT_EQ(resource.get_type(), ResourceType::Null);
}

TEST_F(NullResourceTest, testTOML)
{
    ASSERT_TRUE(resource.as_toml().is_table());
    ASSERT_EQ(resource.as_toml().size(), 0);
}
