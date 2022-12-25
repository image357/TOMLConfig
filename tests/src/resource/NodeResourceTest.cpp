// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 17.12.2022.
//

#include <memory>
#include "NodeResourceTest.h"
#include "resource/NodeResource.h"
#include "MockResource.h"

void NodeResourceTest::SetUp()
{
    Test::SetUp();
}

void NodeResourceTest::TearDown()
{
    Test::TearDown();
}

TEST_F(NodeResourceTest, construct)
{
    NodeResource resource("name");
}

TEST_F(NodeResourceTest, testName)
{
    NodeResource resource("test_name");
    ASSERT_EQ(resource.get_name(), "test_name");
}

TEST_F(NodeResourceTest, testPath)
{
    NodeResource resource("name");

    MockResource mock_parent;
    EXPECT_CALL(mock_parent, get_path())
            .WillOnce(::testing::Return(std::string("/mock/")));

    set_parent_helper(resource, &mock_parent);
    ASSERT_EQ(resource.get_path(), "/mock/name/");
}

TEST_F(NodeResourceTest, testType)
{
    NodeResource resource("name");
    ASSERT_EQ(resource.get_type(), ResourceType::Node);
}
