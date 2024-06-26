#pragma once

#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
#include <Windows.h>

#define MY_NOTIFICATION_ID 1

#define BUILDING_STATIC 1

#ifdef BUILDING_STATIC
#define DLL_EXPORT
#else
#define DLL_EXPORT __declspec(dllexport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

DLL_EXPORT extern void show_desktop_notification();

DLL_EXPORT extern void show_desktop_notification_(const char* message);

DLL_EXPORT extern void show_desktop_notification_prog_name(const char* program_name, const char* message);

#ifdef __cplusplus
}
#endif
