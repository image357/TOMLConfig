// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 17.12.2022.
//

#include <memory>
#include "NodeResourceTest.h"
#include "resource/NodeResource.h"
#include "MockResource.h"
#include "utils/static_ptr.h"
#include "resource/ResourceException.h"

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

TEST_F(NodeResourceTest, testTOML)
{
    NodeResource resource("name");

    MockResource mock_child1;
    EXPECT_CALL(mock_child1, set_parent(&resource)).Times(1);
    EXPECT_CALL(mock_child1, get_name())
            .Times(2)
            .WillRepeatedly(::testing::Return(std::string("child1")));
    EXPECT_CALL(mock_child1, as_toml()).WillOnce(::testing::Return(toml::integer(1)));
    resource.register_child(static_ptr(&mock_child1));

    MockResource mock_child2;
    EXPECT_CALL(mock_child2, set_parent(&resource)).Times(1);
    EXPECT_CALL(mock_child2, get_name())
            .Times(2)
            .WillRepeatedly(::testing::Return(std::string("child2")));
    EXPECT_CALL(mock_child2, as_toml()).WillOnce(::testing::Return(toml::integer(2)));
    resource.register_child(static_ptr(&mock_child2));

    auto value = resource.as_toml();
    ASSERT_EQ(value.size(), 2);
    ASSERT_TRUE(value["child1"].is_integer());
    ASSERT_EQ(value["child1"].as_integer(), 1);
    ASSERT_TRUE(value["child2"].is_integer());
    ASSERT_EQ(value["child2"].as_integer(), 2);
}

TEST_F(NodeResourceTest, testNodeChain)
{
    NodeResource resource_1("name1");
    NodeResource resource_2("name2");
    resource_1.register_child(static_ptr(&resource_2));
    ASSERT_EQ(get_parent_helper(resource_2), &resource_1);
}

TEST_F(NodeResourceTest, testThrowOnDuplicateChild)
{
    NodeResource resource_1("name1");
    NodeResource resource_2("name2");
    resource_1.register_child(static_ptr(&resource_2));
    ASSERT_THROW(
            resource_1.register_child(static_ptr(&resource_2)),
            ResourceException
    );
}
