#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

//DEFAULT MACRO DEF FOR THIS LIB:
///CONFIGURATION PROPERTIES -> C/C++-> PREPROCESSOR->PREPROCESSOR DEFINITIONS (BUSINESSLOGIC_EXPORTS)
#ifdef BUSINESSLOGIC_EXPORTS
#	define BUSINESSLOGIC_EXPORT __declspec(dllexport)
#else
#	define BUSINESSLOGIC_EXPORT __declspec(dllimport)
#endif