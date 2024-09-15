#pragma once
#include <stdexcept>

class ResultNotExist: public std::runtime_error{
public:
    ResultNotExist();
};


class ResultExistMany: public std::runtime_error{
public:
    ResultExistMany();
};
