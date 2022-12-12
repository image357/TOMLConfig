// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_NODERESOURCE_H
#define TOMLCONFIG_NODERESOURCE_H

#include "IResource.h"
#include <string>
#include <memory>
#include <toml.hpp>

namespace tcfg {

class NodeResource : public IResource {
private:
    std::string m_name;
    IResource* m_parent;
    std::unordered_map<std::string, std::shared_ptr<const IResource>> m_children;

public:
    void add_child(const std::shared_ptr<NodeResource>& resource);
    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

private:
    void set_parent(IResource* parent);
};

} // tcfg

#endif //TOMLCONFIG_NODERESOURCE_H
