#pragma once
#ifndef   PIXELBOOM_ERROR
#define   PIXELBOOM_ERROR

#include <iostream>

#include "termcolor.hpp"
#include "core.hpp"

namespace pb {
    
    class ErrorHandler {
    public:
        ErrorHandler();

        void checkError();
    };

};

#endif // PIXELBOOM_ERROR