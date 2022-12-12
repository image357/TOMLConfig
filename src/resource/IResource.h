// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_IRESOURCE_H
#define TOMLCONFIG_IRESOURCE_H

#include "ResourceType.h"
#include <string>
#include <toml.hpp>

namespace tcfg {

class IResource {
public:
    virtual ~IResource() = default;

    virtual std::string get_name() const = 0;
    virtual std::string get_path() const = 0;
    virtual ResourceType get_type() const = 0;
    virtual toml::value as_toml() const = 0;
};

} // tcfg

#endif //TOMLCONFIG_IRESOURCE_H
