#include <iostream>
#include <vector>

#include "medianOfVector.hpp"

void displayResults(std::vector<int> &nums, int &duration)
{
    std::cout << " " << *nums.begin();
    if (*nums.begin() > 9999)
        std::cout << "\t";
    else
        std::cout << "\t\t";

    std::cout << "| " << medianOfVector(nums);
    if (medianOfVector(nums) > 9999)
        std::cout << "\t";
    else
        std::cout << "\t\t";

    std::cout << "| " << *(nums.end() - 1);
    if (*(nums.end() - 1) > 9999)
        std::cout << "\t";
    else
        std::cout << "\t\t";

    std::cout << "| " << duration << " milliseconds";
}