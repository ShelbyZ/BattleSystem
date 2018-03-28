#ifndef _EXPORTS_H
#define _EXPORTS_H

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BATTLESYSTEM_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// BATTLESYSTEM_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef battle_system_EXPORTS
    #ifdef __GNUC__
        #define BATTLESYSTEM_API
    #else
        #define BATTLESYSTEM_API __declspec(dllexport)
    #endif
#else
    #ifdef __GNUC__
        #define BATTLESYSTEM_API
    #else
        #define BATTLESYSTEM_API __declspec(dllimport)
    #endif
#endif

#endif