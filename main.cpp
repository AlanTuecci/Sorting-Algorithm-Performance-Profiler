#include <iostream>
#include <vector>

#include ".\\algorithms\\standardSort.hpp"
#include ".\\algorithms\\selectionSort.hpp"
#include ".\\algorithms\\mergeSort.hpp"
#include ".\\algorithms\\inPlaceMergeSort.hpp"
#include ".\\algorithms\\heapSort.hpp"

#include ".\\utility_functions\\startPrompt.hpp"
#include ".\\utility_functions\\displayResults.hpp"
#include ".\\utility_functions\\readDataFromFile.hpp"

int main(){
    if (startPrompt()){
        Start:
        clearTerminal();

        std::string input = "";
        std::cout << "This program has 9 inputs:" << std::endl;
        std::cout << std::endl;
        std::cout << "input1.txt \t input2.txt \t input3.txt \t input4.txt \t input5.txt \t input6.txt \t input7.txt \t input8.txt \t input9.txt" << std::endl;
        std::cout << std::endl << std::endl;
        Again:
        std::cout << "Please enter the name of the input exactly as it appears in the examples above: ";
        std::cin >> input;
        std::cout << std::endl;

        std::vector<int> nums;
        int duration = 0;

        nums = readDataFromFile(".\\input_files\\" + input);
        if(nums.size() == 0){
            std::cout << "Something went wrong! Did you type the input name correctly? Remember it should be entered like this: input4.txt" << std::endl;
            goto Again;
        }

        clearTerminal();

        std::cout << "You chose " << input << std::endl;
        std::cout << "The size of " << input << " is " << nums.size() << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "\t\t\t | Minimum\t| Median\t| Maximum\t| Execution Time\t| Big-O Complexity" << std::endl;

        standardSort(nums, duration);
        std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "STL Sort: \t\t |";
        displayResults(nums, duration);
        std::cout << "\t| O(N log N)" << std::endl;
        nums = readDataFromFile(".\\input_files\\" + input);
        duration = 0;

        heapSort(nums, duration);
        std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Heap Sort: \t\t |";
        displayResults(nums, duration);
        std::cout << "\t| O(N log N)" << std::endl;
        nums = readDataFromFile(".\\input_files\\" + input);
        duration = 0;

        inPlaceMergeSort(nums, duration);
        std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "In-Place Merge Sort: \t |";
        displayResults(nums, duration);
        std::cout << "\t| O(N log N)" << std::endl;
        nums = readDataFromFile(".\\input_files\\" + input);
        duration = 0;

        mergeSort(nums, duration);
        std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Merge Sort: \t\t |";
        displayResults(nums, duration);
        std::cout << "\t| O(N log N)" << std::endl;
        nums = readDataFromFile(".\\input_files\\" + input);
        duration = 0;

        if(nums.size() <= 50000){
            selectionSort(nums, duration);
            std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Selection Sort: \t |";
            displayResults(nums, duration);
            std::cout << "\t| O(N^2)" << std::endl;
            nums = readDataFromFile(".\\input_files\\" + input);
            duration = 0;
        }
        else{
            std::cout << "------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Selection Sort: \t | N/A\t\t| N/A\t\t| N/A\t\t| N/A milliseconds\t| O(N^2)" << std::endl;
            std::cout << std::endl;
            std::cout << "*Due to a very large input, Selection Sort was not run as it would take an unmeasurably long time to run." << std::endl;
        }

        std::cout << std::endl;
        std::cout << std::endl;

        std::cout << "The sorting algorithms have finished running!" << std::endl;
        std::cout << std::endl;
        std::cout << "You have the following options:" << std::endl;
        std::cout << "\t (1) Re-run the algorithms with a different input" << std::endl;
        std::cout << "\t (2) Exit the program" << std::endl;
        std::cout << std::endl;
        Retry:
        std::cout << "Enter '1' or '2' to make your selection: ";
        std::cin >> input;
        if(input == "1")
            goto Start;
        else if(input == "2")
            return 0;
        else{
            std::cout << std::endl;
            std::cout << "You entered something that is not '1' or '2'" << std::endl;
            goto Retry;
        }
    }

    return 0;
}