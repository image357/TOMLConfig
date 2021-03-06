//
// Created by koepke on 3/6/22.
//

#include "TOMLConfig/resource/abstract/LeafResource.h"

namespace config::resource {

LeafResource::LeafResource(const std::string& name)
        :m_name(name) { }

std::string LeafResource::get_name() const
{
    return m_name;
}

std::string LeafResource::get_path() const
{
    return m_parent->get_path()+get_name();
}

ResourceType LeafResource::get_type() const
{
    return ResourceType::Leaf;
}

void LeafResource::set_parent(IResource* resource)
{
    m_parent = resource;
}

toml::value LeafResource::as_toml() const
{
    return toml::table();
}

}
