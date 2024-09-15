#include "Exception.hpp"

ResultExistMany::ResultExistMany() : std::runtime_error("Result exist many"){}

ResultNotExist::ResultNotExist() : std::runtime_error("Result does not exist"){}
