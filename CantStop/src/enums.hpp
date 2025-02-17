// ================================================================
// Name: Can't Stop Board Game        Jan, 2025
// Author:  Ashish Khadka and Aryan Tandon      File: enums.hpp
// ================================================================
#pragma once
#include "tools.hpp"
// -----------------------------------------------------------------
enum class ECcolor {White, Yellow, Green, Blue, Orange, Error};
enum class ECstate { Available, Pending, Captured };
extern const string colorNames[];
extern const string stateNames[];
