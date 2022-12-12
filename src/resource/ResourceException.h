// Copyright (c) 2022, Marcel Koepke
// All rights reserved.

//
// Created by Marcel Koepke on 12.12.2022.
//

#ifndef TOMLCONFIG_RESOURCEEXCEPTION_H
#define TOMLCONFIG_RESOURCEEXCEPTION_H

namespace tcfg {

#include <stdexcept>

class ResourceException : public std::runtime_error {
public:
    explicit ResourceException(const std::string& what = "")
            :std::runtime_error(what) { }
};

} // tcfg

#endif //TOMLCONFIG_RESOURCEEXCEPTION_H
