// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_STATIC_PTR_H
#define TOMLCONFIG_STATIC_PTR_H

#include <memory>

namespace tcfg {

template<typename T>
std::shared_ptr<T> static_ptr(T* ptr)
{
    return std::shared_ptr<T>(ptr, [](T*) { });
}

} // tcfg

#endif //TOMLCONFIG_STATIC_PTR_H
