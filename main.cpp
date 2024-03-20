#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "StandardSort.hpp"
#include "HalfSelectionSort.hpp"
#include "MergeSort.hpp"
#include "InPlaceMergeSort.hpp"
#include "HalfHeapSort.hpp"

#include "ClearTerminal.hpp"

/**
 * @param: a string of the filename that contains the numbers to be sorted. Each number is separated by a space.
 * @post: reads the file, creates a vector that is filled with numbers where each entry is separated by a space in the input file.
 * @return: a vector containing the numbers from the input file
 **/
std::vector<int> read_data_from_file(std::string filename)
{
    std::vector<int> data;
    std::ifstream file(filename);
    int number;
    while (file >> number)
    {
        data.push_back(number);
        file.ignore(1, ' ');
    }
    return data;
}

bool startPrompt()
{  
    clearTerminal();
    std::string response = "";
    std::cout << "Welcome to the sorting algorithm analyzer!" << std::endl;
    std::cout << "By Alan Tuecci - 2023" << std::endl;
    std::cout << std::endl;
    std::cout << "This program is designed to demonstrate the differences in speed between different sorting algorithms." << std::endl;
    std::cout << "The purpose is to highlight the fact that while a brute force solution gets the job done, it can be multiple orders of magnitude slower than an efficient solution." << std::endl;
    std::cout << "The following algorithms will be examined: Selection Sort, Merge Sort, In-Place Merge Sort, Heap Sort, and as a benchmark, the STL algorithm sort() [which is an implementation of IntraSort] will be used. " << std::endl;
    std::cout << std::endl;
    std::cout << "Notes:";
    std::cout << "\t Depending on your system, the program may crash on certain inputs due to memory-related issues." << std::endl;
    std::cout << "\t If the program is running Selection Sort on a very large input, it might not finish in a reasonable amount of time, and if you don't wish to wait, please close the program and rerun it with a smaller input." << std::endl;
    std::cout << std::endl;
Retry:
    std::cout << "To begin, enter 'begin': ";
    std::cin >> response;
    std::cout << std::endl;

    if (response == "begin")
        return 1;
    else
    {
        std::cout << "You inputted something that's not 'begin' - Please try again. [Remember: Do not type the asterisks, only type the word begin]" << std::endl;
        goto Retry;
    }

    return 0;
}

int main()
{
    if (startPrompt())
    {
        clearTerminal();

        std::string inputName = "";
        std::cout << "This program has 9 inputs:" << std::endl;
        std::cout << std::endl;
        std::cout << "input1.txt \t input2.txt \t input3.txt \t input4.txt \t input5.txt \t input6.txt \t input7.txt \t input8.txt \t input9.txt" << std::endl;
        std::cout << std::endl << std::endl;
        Again:
        std::cout << "Please type the name of the input exactly as it appears in the examples above: ";
        std::cin >> inputName;
        std::cout << std::endl;

        std::vector<int> nums;
        int duration = 0;

        nums = read_data_from_file(".\\inputs\\" + inputName);
        if(nums.size() == 0){
            std::cout << "Something went wrong! Did you type the input name correctly? Remember it should be entered like this: input4.txt" << std::endl;
            goto Again;
        }

        clearTerminal();

        std::cout << "You chose " << inputName << std::endl;
        std::cout << "The size of " << inputName << " is " << nums.size() << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t | Median \t | Minimum \t | Maximum \t | Execution Time" << std::endl;

        std::cout << "STL Sort: \t\t |" << standardSort(nums, duration) << "\t | " << nums[0] << "\t | " << nums[nums.size()-1] << "\t | " << duration << " milliseconds" << std::endl;
        nums = read_data_from_file(".\\inputs\\" + inputName);
        duration = 0;

        std::cout << "Heap Sort: \t\t |" << heapSort(nums, duration) << "\t | " << nums[0] << "\t | " << nums[nums.size()-1] << "\t | " << duration << " milliseconds" << std::endl;
        nums = read_data_from_file(".\\inputs\\" + inputName);
        duration = 0;
        
        std::cout << "In-Place Merge Sort: \t |" << inPlaceMergeSort(nums, duration) << "\t | " << nums[0] << "\t | " << nums[nums.size()-1] << "\t | " << duration << " milliseconds" << std::endl;
        nums = read_data_from_file(".\\inputs\\" + inputName);
        duration = 0;

        std::cout << "Merge Sort: \t\t |" << mergeSort(nums, duration) << "\t | " << nums[0] << "\t | " << nums[nums.size()-1] << "\t | " << duration << " milliseconds" << std::endl;
        nums = read_data_from_file(".\\inputs\\" + inputName);
        duration = 0;
        
        if(nums.size() <= 50000){
            std::cout << "Selection Sort: \t |" << halfSelectionSort(nums, duration) << "\t | " << nums[0] << "\t | " << nums[nums.size()-1] << "\t | " << duration << " milliseconds" << std::endl;
            nums = read_data_from_file(".\\inputs\\" + inputName);
            duration = 0;
        }
        else{
            std::cout << "Selection Sort: \t | N/A \t\t | N/A \t\t | N/A \t\t | N/A milliseconds \t *Due to a very large input, Selection Sort was not run as it would take an unmeasurably long time to run." << std::endl;
        }
    }

    return 0;
}

// int main()
// {
//     // Iniitialize vector nums and duration with default values
//     std::vector<int> nums;
//     int duration = 0;

//     // std::vector<int> testNums = read_data_from_file("selectionsort4.txt");
//     std::vector<int> stdNums;
//     std::vector<int> mergeNums;
//     std::vector<int> inMergeNums;
//     std::vector<int> heapNums;
//     std::vector<int> quickNums;
//     // std::vector<int> medNums;

//     std::cout << std::endl;
//     stdNums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "input6 Size: " << stdNums.size() << std::endl;
//     std::cout << "standardSort Median: " << standardSort(stdNums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     std::cout << std::endl;
//     nums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "halfSelectionSort Median: " << halfSelectionSort(nums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     // std::vector<int>::iterator mid = testNums.begin() - 1 + testNums.size() / 2;
//     // if(nums.size() % 2 != 0){
//     //     mid++;
//     // }
//     // std::cout << std::endl << "TestSelectionSort Median: " << *mid << std::endl << "Execution time = N/A milliseconds" << std::endl;

//     std::cout << std::endl;
//     mergeNums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "mergeSort Median: " << mergeSort(mergeNums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     std::cout << std::endl;
//     inMergeNums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "inPlaceMergeSort Median: " << inPlaceMergeSort(inMergeNums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     std::cout << std::endl;
//     heapNums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "HalfHeapSort Median: " << halfHeapSort(heapNums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     std::cout << std::endl;
//     quickNums = read_data_from_file(".\\inputs\\input6.txt");
//     std::cout << "QuickSelect Median: " << quickSelect(quickNums, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     // for(int i=0; i < quickNums.size(); i++){
//     //     std::cout << quickNums[i] << std::endl;
//     // }

//     std::cout << std::endl;
//     std::vector<int> worstCase = worstCaseQuickSelect();
//     std::cout << "WorstCaseQuick Size: " << worstCase.size() << std::endl;
//     std::cout << "WorstCaseQuick Median: " << quickSelect(worstCase, duration) << std::endl
//               << "Execution time = " << duration << " milliseconds";
//     std::cout << std::endl;

//     // std::cout << std::endl;
//     // std::cout << "Median of Medians: " << medianOfMediansMethod(worstCase,duration) << std::endl << "Execution time = " << duration << " milliseconds";
//     // std::cout << std::endl;

//     return 0;
// };