// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#include "NullResourceTest.h"
#include "MockResource.h"
#include "resource/ResourceException.h"

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
    ASSERT_EQ(default_resource.get_name(), "");
}

TEST_F(NullResourceTest, testPath)
{
    ASSERT_EQ(default_resource.get_path(), "");
}

TEST_F(NullResourceTest, testType)
{
    ASSERT_EQ(default_resource.get_type(), ResourceType::Null);
}

TEST_F(NullResourceTest, testTOML)
{
    ASSERT_TRUE(default_resource.as_toml().is_table());
    ASSERT_EQ(default_resource.as_toml().size(), 0);
}

TEST_F(NullResourceTest, testThrowOnSetParent)
{
    MockResource mock_resource;
    ASSERT_THROW(
            set_parent_helper(default_resource, &mock_resource),
            ResourceException
    );
}
