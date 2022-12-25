// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 11.12.2022.
//

#include "GlobalTest.h"
#include <filesystem>
#include <vector>
#include <toml.hpp>

void GlobalTest::SetUp()
{
    Test::SetUp();
}

void GlobalTest::TearDown()
{
    Test::TearDown();
}

TEST_F(GlobalTest, succeed)
{
    SUCCEED();
}

TEST_F(GlobalTest, scanDirectory)
{
    std::filesystem::path path(RESOURCE_PATH);
    std::filesystem::directory_iterator it(path);
    std::vector<std::string> entries;
    for (const auto& entry : it) {
        entries.emplace_back(entry.path().filename());
    }
    ASSERT_EQ(entries.size(), 2);
    ASSERT_NE(std::find(entries.begin(), entries.end(), "basic.toml"), entries.end());
    ASSERT_NE(std::find(entries.begin(), entries.end(), "basic.txt"), entries.end());
}

TEST_F(GlobalTest, testBasicTOML)
{
    auto basic = toml::parse(RESOURCE_PATH "basic.toml");

    ASSERT_EQ(basic.size(), 5);
    ASSERT_TRUE(basic.contains("a"));
    ASSERT_TRUE(basic.contains("b"));
    ASSERT_TRUE(basic.contains("c"));
    ASSERT_TRUE(basic.contains("table1"));
    ASSERT_TRUE(basic.contains("table2"));

    ASSERT_EQ(basic["table1"].size(), 3);
    ASSERT_TRUE(basic["table1"].contains("a"));
    ASSERT_TRUE(basic["table1"].contains("b"));
    ASSERT_TRUE(basic["table1"].contains("c"));

    ASSERT_EQ(basic["table2"].size(), 4);
    ASSERT_TRUE(basic["table2"].contains("a"));
    ASSERT_TRUE(basic["table2"].contains("b"));
    ASSERT_TRUE(basic["table2"].contains("c"));
    ASSERT_TRUE(basic["table2"].contains("subtable1"));

    ASSERT_EQ(basic["table2"]["subtable1"].size(), 3);
    ASSERT_TRUE(basic["table2"]["subtable1"].contains("d"));
    ASSERT_TRUE(basic["table2"]["subtable1"].contains("e"));
    ASSERT_TRUE(basic["table2"]["subtable1"].contains("f"));

    ASSERT_EQ(basic["a"].as_integer(), 1);
    ASSERT_EQ(basic["b"].as_floating(), 2.0);
    ASSERT_EQ(basic["c"].as_string(), "c");

    ASSERT_EQ(basic["table1"]["a"].as_integer(), 3);
    ASSERT_EQ(basic["table1"]["b"].as_floating(), 4.0);
    ASSERT_EQ(basic["table1"]["c"].as_string(), "c");

    ASSERT_EQ(basic["table2"]["a"].as_integer(), 5);
    ASSERT_EQ(basic["table2"]["b"].as_floating(), 6.0);
    ASSERT_EQ(basic["table2"]["c"].as_string(), "cc");

    ASSERT_EQ(basic["table2"]["subtable1"]["d"].as_integer(), 7);
    ASSERT_EQ(basic["table2"]["subtable1"]["e"].as_floating(), 8.0);
    ASSERT_EQ(basic["table2"]["subtable1"]["f"].as_string(), "ccc");
}

TEST_F(GlobalTest, testBasicTXT)
{
    std::ifstream t(RESOURCE_PATH "basic.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
    ASSERT_EQ(buffer.str(), "This is not a toml file.\n");
}
