#include "error.hpp"

namespace pb {
    void HandleError() {
        #define PIXELBOOM_ERROR
        std::time_t t = std::time(0);
        std::tm* now = std::localtime(&t);
        #ifdef PIXELBOOM_WINDOWS
            system("Setlocal");
        #endif
        std::cout << "[33m" << "[" << now->tm_hour << ":" << now->tm_min << ":" << now->tm_sec << "] " << "[31m" << "[PixelBoom]" << "[0m" << " Error: " << sf::err << "[0m" << "\n";
    }
};