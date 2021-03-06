//
// Created by koepke on 3/7/22.
//

#include "AbstractResourceTreeTest.h"
#include "TOMLConfig/resource/abstract/RootResource.h"
#include "TOMLConfig/resource/abstract/NodeResource.h"
#include "TOMLConfig/resource/abstract/LeafResource.h"

void AbstractResourceTreeTest::SetUp()
{
    mock_resource_ptr = std::make_shared<MockResource>();
    Test::SetUp();
}

void AbstractResourceTreeTest::TearDown()
{
    Test::TearDown();
}

TEST_F(AbstractResourceTreeTest, constructRoot)
{
    RootResource resource;
}

TEST_F(AbstractResourceTreeTest, constructNode)
{
    NodeResource resource("name");
}

TEST_F(AbstractResourceTreeTest, constructLeaf)
{
    LeafResource resource("name");
}

TEST_F(AbstractResourceTreeTest, makeSimpleTree)
{
    auto root_ptr = std::make_shared<RootResource>();

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node2");
    root_ptr->add_resource(node1_ptr);
    root_ptr->add_resource(node2_ptr);

    auto leaf11_ptr = std::make_shared<LeafResource>("leaf11");
    auto leaf12_ptr = std::make_shared<LeafResource>("leaf12");
    node1_ptr->add_resource(leaf11_ptr);
    node1_ptr->add_resource(leaf12_ptr);

    auto leaf21_ptr = std::make_shared<LeafResource>("leaf21");
    auto leaf22_ptr = std::make_shared<LeafResource>("leaf22");
    auto leaf23_ptr = std::make_shared<LeafResource>("leaf23");
    node2_ptr->add_resource(leaf21_ptr);
    node2_ptr->add_resource(leaf22_ptr);
    node2_ptr->add_resource(leaf23_ptr);
}

TEST_F(AbstractResourceTreeTest, throwOnSameNameInsert)
{
    auto root_ptr = std::make_shared<RootResource>();

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node1");
    root_ptr->add_resource(node1_ptr);
    ASSERT_THROW(root_ptr->add_resource(node2_ptr), AbstractResourceException);

    auto leaf1_ptr = std::make_shared<LeafResource>("leaf1");
    auto leaf2_ptr = std::make_shared<LeafResource>("leaf1");
    node1_ptr->add_resource(leaf1_ptr);
    ASSERT_THROW(node1_ptr->add_resource(leaf2_ptr), AbstractResourceException);
}

TEST_F(AbstractResourceTreeTest, testNameHandling)
{
    auto root_ptr = std::make_shared<RootResource>();
    ASSERT_EQ(root_ptr->get_name(), "");

    auto node_ptr = std::make_shared<NodeResource>("node");
    root_ptr->add_resource(node_ptr);
    ASSERT_EQ(node_ptr->get_name(), "node");

    auto leaf_ptr = std::make_shared<LeafResource>("leaf");
    node_ptr->add_resource(leaf_ptr);
    ASSERT_EQ(leaf_ptr->get_name(), "leaf");
}

TEST_F(AbstractResourceTreeTest, testPathHandling)
{
    auto root_ptr = std::make_shared<RootResource>();
    ASSERT_EQ(root_ptr->get_path(), "/");

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node2");
    root_ptr->add_resource(node1_ptr);
    root_ptr->add_resource(node2_ptr);
    ASSERT_EQ(node1_ptr->get_path(), "/node1/");
    ASSERT_EQ(node2_ptr->get_path(), "/node2/");

    auto leaf11_ptr = std::make_shared<LeafResource>("leaf11");
    auto leaf12_ptr = std::make_shared<LeafResource>("leaf12");
    node1_ptr->add_resource(leaf11_ptr);
    node1_ptr->add_resource(leaf12_ptr);
    ASSERT_EQ(leaf11_ptr->get_path(), "/node1/leaf11");
    ASSERT_EQ(leaf12_ptr->get_path(), "/node1/leaf12");

    auto leaf21_ptr = std::make_shared<LeafResource>("leaf21");
    auto leaf22_ptr = std::make_shared<LeafResource>("leaf22");
    auto leaf23_ptr = std::make_shared<LeafResource>("leaf23");
    node2_ptr->add_resource(leaf21_ptr);
    node2_ptr->add_resource(leaf22_ptr);
    node2_ptr->add_resource(leaf23_ptr);
    ASSERT_EQ(leaf21_ptr->get_path(), "/node2/leaf21");
    ASSERT_EQ(leaf22_ptr->get_path(), "/node2/leaf22");
    ASSERT_EQ(leaf23_ptr->get_path(), "/node2/leaf23");
}

TEST_F(AbstractResourceTreeTest, testTypeHandling)
{
    auto root_ptr = std::make_shared<RootResource>();
    ASSERT_EQ(root_ptr->get_type(), ResourceType::Root);

    auto node_ptr = std::make_shared<NodeResource>("node");
    root_ptr->add_resource(node_ptr);
    ASSERT_EQ(node_ptr->get_type(), ResourceType::Node);

    auto leaf_ptr = std::make_shared<LeafResource>("leaf");
    node_ptr->add_resource(leaf_ptr);
    ASSERT_EQ(leaf_ptr->get_type(), ResourceType::Leaf);
}

TEST_F(AbstractResourceTreeTest, throwOnRootSetParent)
{
    auto root1_ptr = std::make_shared<RootResource>();
    auto root2_ptr = std::make_shared<RootResource>();
    ASSERT_THROW(root1_ptr->add_resource(root2_ptr), AbstractResourceException);
}

TEST_F(AbstractResourceTreeTest, testAsToml)
{
    auto root_ptr = std::make_shared<RootResource>();

    auto node1_ptr = std::make_shared<NodeResource>("node1");
    auto node2_ptr = std::make_shared<NodeResource>("node2");
    root_ptr->add_resource(node1_ptr);
    root_ptr->add_resource(node2_ptr);

    auto leaf11_ptr = std::make_shared<LeafResource>("leaf11");
    auto leaf12_ptr = std::make_shared<LeafResource>("leaf12");
    node1_ptr->add_resource(leaf11_ptr);
    node1_ptr->add_resource(leaf12_ptr);

    auto leaf21_ptr = std::make_shared<LeafResource>("leaf21");
    auto leaf22_ptr = std::make_shared<LeafResource>("leaf22");
    auto leaf23_ptr = std::make_shared<LeafResource>("leaf23");
    node2_ptr->add_resource(leaf21_ptr);
    node2_ptr->add_resource(leaf22_ptr);
    node2_ptr->add_resource(leaf23_ptr);

    auto root_toml = root_ptr->as_toml();
    toml::find(root_toml, "node1");
    toml::find(root_toml, "node2");
    toml::find(toml::find(root_toml, "node1"), "leaf11");
    toml::find(toml::find(root_toml, "node1"), "leaf12");
    toml::find(toml::find(root_toml, "node2"), "leaf21");
    toml::find(toml::find(root_toml, "node2"), "leaf22");
    toml::find(toml::find(root_toml, "node2"), "leaf23");
    ASSERT_EQ(root_toml.size(), 2);
    ASSERT_EQ(toml::find(root_toml, "node1").size(), 2);
    ASSERT_EQ(toml::find(root_toml, "node2").size(), 3);
    ASSERT_EQ(toml::find(toml::find(root_toml, "node1"), "leaf11").size(), 0);
    ASSERT_EQ(toml::find(toml::find(root_toml, "node1"), "leaf12").size(), 0);
    ASSERT_EQ(toml::find(toml::find(root_toml, "node2"), "leaf21").size(), 0);
    ASSERT_EQ(toml::find(toml::find(root_toml, "node2"), "leaf22").size(), 0);
    ASSERT_EQ(toml::find(toml::find(root_toml, "node2"), "leaf23").size(), 0);

    auto node1_toml = node1_ptr->as_toml();
    toml::find(node1_toml, "leaf11");
    toml::find(node1_toml, "leaf12");
    ASSERT_EQ(node1_toml.size(), 2);
    ASSERT_EQ(toml::find(node1_toml, "leaf11").size(), 0);
    ASSERT_EQ(toml::find(node1_toml, "leaf12").size(), 0);

    auto node2_toml = node2_ptr->as_toml();
    toml::find(node2_toml, "leaf21");
    toml::find(node2_toml, "leaf22");
    toml::find(node2_toml, "leaf23");
    ASSERT_EQ(node2_toml.size(), 3);
    ASSERT_EQ(toml::find(node2_toml, "leaf21").size(), 0);
    ASSERT_EQ(toml::find(node2_toml, "leaf22").size(), 0);
    ASSERT_EQ(toml::find(node2_toml, "leaf23").size(), 0);

    auto leaf11_toml = leaf11_ptr->as_toml();
    ASSERT_EQ(leaf11_toml.size(), 0);

    auto leaf21_toml = leaf21_ptr->as_toml();
    ASSERT_EQ(leaf21_toml.size(), 0);

    std::stringstream root_stream;
    root_stream << root_ptr->as_toml();
    ASSERT_EQ(
            root_stream.str(),
            "\n"
            "[node1]\n"
            "\n"
            "[node1.leaf11]\n"
            "\n"
            "[node1.leaf12]\n"
            "\n"
            "[node2]\n"
            "\n"
            "[node2.leaf21]\n"
            "\n"
            "[node2.leaf22]\n"
            "\n"
            "[node2.leaf23]\n"
            "\n\n"
    );
}
