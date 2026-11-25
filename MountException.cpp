#include "MountException.h"
MountException::MountException(const std::string& msg) : std::runtime_error(msg) {}
