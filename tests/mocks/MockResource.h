//
// Created by koepke on 3/7/22.
//

#ifndef TOMLCONFIG_MOCKRESOURCE_H
#define TOMLCONFIG_MOCKRESOURCE_H

#include "TOMLConfig/resource/IResource.h"

namespace config::resource {

class MockResource : public IResource {
public:
    MOCK_METHOD(std::string, get_name, (), (const, override));
    MOCK_METHOD(std::string, get_path, (), (const, override));
    MOCK_METHOD(ResourceType, get_type, (), (const, override));
    MOCK_METHOD(void, set_parent, (IResource*), (override));
    MOCK_METHOD(toml::value, as_toml, (), (const, override));
};

}

#endif //TOMLCONFIG_MOCKRESOURCE_H
