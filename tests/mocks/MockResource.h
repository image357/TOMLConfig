// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 17.12.2022.
//

#ifndef TOMLCONFIG_MOCKRESOURCE_H
#define TOMLCONFIG_MOCKRESOURCE_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "resource/IResource.h"

namespace tcfg {

class MockResource : public IResource {
public:
    MOCK_METHOD(std::string, get_name, (), (const, override));
    MOCK_METHOD(std::string, get_path, (), (const, override));
    MOCK_METHOD(ResourceType, get_type, (), (const, override));
    MOCK_METHOD(toml::value, as_toml, (), (const, override));
    MOCK_METHOD(void, set_parent, (IResource*), (override));
};

}

#endif //TOMLCONFIG_MOCKRESOURCE_H
