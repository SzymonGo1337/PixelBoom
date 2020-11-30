#include "error.hpp"

namespace pb {
    ErrorHandler::ErrorHandler() {
        std::cout << termcolor::red << "[PixelBoom]" << termcolor::blink << " Error Handler Enabled" << termcolor::blink << "\n";
    }

    void ErrorHandler::checkError() {
        std::cout << termcolor::red << "[PixelBoom]" << termcolor::blink << " Error: " << sf::err << termcolor::blink << "\n";
    }
};