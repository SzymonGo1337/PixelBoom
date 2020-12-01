#include "error.hpp"

namespace pb {
    void HandleError() {
        #define PIXELBOOM_ERROR
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        std::cout << termcolor::yellow << "[" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] " << termcolor::red << "[PixelBoom]" << termcolor::white << " Error: " << sf::err << termcolor::white << "\n";
    }
};