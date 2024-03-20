#include <iostream>
#include "ClearTerminal.hpp"

bool startPrompt(){
    clearTerminal();
    std::string response = "";
    std::cout << "Welcome to the sorting algorithm performance profiler!" << std::endl;
    std::cout << "By Alan Tuecci - Version 1.0" << std::endl;
    std::cout << std::endl;
    std::cout << "This program is designed to demonstrate the differences in speed between different sorting algorithms." << std::endl;
    std::cout << "While a brute force solution gets the job done, it can be multiple orders of magnitude slower than an efficient solution, and this program is designed to demonstrate that fact." << std::endl;
    std::cout << "The following algorithms will be examined: Selection Sort, Merge Sort, In-Place Merge Sort, Heap Sort, and the STL Intra Sort algorithm: std::sort()." << std::endl;
    std::cout << std::endl;
    std::cout << "Notes:" << std::endl;
    std::cout << "Depending on your system, the program may crash on certain inputs due to memory-related issues." << std::endl;
    std::cout << "The program will not run the Selection Sort algorithm on inputs greater than 50000 since it will not complete in a reasonable amount of time." << std::endl;
    std::cout << std::endl;
    Retry:
    std::cout << "To begin, enter 'begin': ";
    std::cin >> response;
    std::cout << std::endl;

    if (response == "begin")
        return 1;
    else{
        std::cout << "You inputted something that's not 'begin' - Please try again [Remember: Do not type the asterisks, only type the word begin]" << std::endl;
        goto Retry;
    }

    return 0;
}