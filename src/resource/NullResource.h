// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_NULLRESOURCE_H
#define TOMLCONFIG_NULLRESOURCE_H

#include "IResource.h"

class NullResourceTest;

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
    void set_parent(IResource* resource) override;
    friend class ::NullResourceTest;

public:
    NullResource(const NullResource&) = delete;
    void operator=(const NullResource&) = delete;
private:
    NullResource() = default;
};

} // tcfg

#endif //TOMLCONFIG_NULLRESOURCE_H
