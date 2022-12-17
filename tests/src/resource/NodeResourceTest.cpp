// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 17.12.2022.
//

#include <memory>
#include "NodeResourceTest.h"
#include "resource/NodeResource.h"
#include "../../mocks/MockResource.h"

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
