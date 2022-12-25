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

// forward declare test class
class NodeResourceTest;

namespace tcfg {

class NodeResource : public IResource, public std::enable_shared_from_this<NodeResource> {
private:
    std::string m_name;
    const IResource* m_parent;
    std::unordered_map<std::string, std::shared_ptr<const IResource>> m_children;

public:
    NodeResource(const std::string& name);
    ~NodeResource() override = default;

    std::string get_name() const override;
    std::string get_path() const override;
    ResourceType get_type() const override;
    toml::value as_toml() const override;

    void register_child(const std::shared_ptr<IResource>& resource);

private:
    void set_parent(IResource* resource) override;
    friend class ::NodeResourceTest;
};

} // tcfg

#endif //TOMLCONFIG_NODERESOURCE_H
