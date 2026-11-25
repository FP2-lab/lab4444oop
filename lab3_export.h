#pragma once
// Макрос экспорта: статическая сборка (LAB3_STATIC), сборка DLL (LAB3_BUILD_DLL), использование DLL.
#if defined(_WIN32)
  #if defined(LAB3_STATIC)
    #define LAB3_API
  #elif defined(LAB3_BUILD_DLL)
    #define LAB3_API __declspec(dllexport)
  #else
    #define LAB3_API __declspec(dllimport)
  #endif
#else
  #define LAB3_API __attribute__((visibility("default")))
#endif
