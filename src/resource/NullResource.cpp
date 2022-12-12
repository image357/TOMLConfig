// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#include "NullResource.h"

namespace tcfg {

std::string NullResource::get_name() const
{
    return "";
}

std::string NullResource::get_path() const
{
    return "";
}

ResourceType NullResource::get_type() const
{
    return ResourceType::Null;
}

toml::value NullResource::as_toml() const
{
    return toml::table();
}

NullResource& NullResource::get_instance()
{
    static NullResource instance;
    return instance;
}

} // tcfg
