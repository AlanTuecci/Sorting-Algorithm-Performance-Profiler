#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

void clearTerminal() {
#ifdef _WIN32
    system("cls");  // For Windows
#else
    system("clear");  // For Linux/Unix/Mac
#endif
}