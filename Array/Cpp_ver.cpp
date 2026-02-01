#include <iostream>

int main() {
    long standard = 0;

    // Check for Microsoft Visual C++ specific macro
    #if defined(_MSVC_LANG)
        standard = _MSVC_LANG;
    #else
        standard = __cplusplus;
    #endif

    std::cout << "C++ Language Standard Code: " << standard << std::endl;

    if (standard <= 199711L) {
        std::cout << "Version: C++98/C++03" << std::endl;
    } else if (standard <= 201103L) {
        std::cout << "Version: C++11" << std::endl;
    } else if (standard <= 201402L) {
        std::cout << "Version: C++14" << std::endl;
    } else if (standard <= 201703L) {
        std::cout << "Version: C++17" << std::endl;
    } else if (standard <= 202002L) {
        std::cout << "Version: C++20" << std::endl;
    } else if (standard > 202002L) {
        std::cout << "Version: C++23 or later" << std::endl;
    }
    
    return 0;
}
