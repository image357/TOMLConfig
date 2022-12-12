// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_RESOURCETYPE_H
#define TOMLCONFIG_RESOURCETYPE_H

namespace tcfg {

enum class ResourceType {
    Root,
    Node,
    Leaf,
    Null,
};

} // tcfg

#endif //TOMLCONFIG_RESOURCETYPE_H
