// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_NULLRESOURCE_H
#define TOMLCONFIG_NULLRESOURCE_H

#include "IResource.h"

namespace tcfg {

class NullResource : public IResource {
public:
    ~NullResource() override = default;
    static NullResource& get_instance();

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

private:
    NullResource() = default;
public:
    NullResource(const NullResource&) = delete;
    void operator=(const NullResource&) = delete;
};

} // tcfg

#endif //TOMLCONFIG_NULLRESOURCE_H
