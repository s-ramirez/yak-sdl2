#pragma once
#include <iostream>
#include <string>

#define YAK_ASSERT(condition, message) \
    do { \
        if (condition) { \
            std::cerr << "Assertion failed: " << message << "\n" \
                      << "File: " << __FILE__ << "\n" \
                      << "Line: " << __LINE__ << "\n"; \
            std::abort(); \
        } \
    } while (0)

