#pragma once
#include "lab3_export.h"
#include <stdexcept>
#include <string>

class LAB3_API MountException : public std::runtime_error {
public:
    explicit MountException(const std::string& msg);
};
