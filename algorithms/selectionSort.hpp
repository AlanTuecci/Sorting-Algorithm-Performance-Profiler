#include <vector>
#include <iostream>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

/**
 * @param: a reference to a vector of integers to be sorted
 * @param: a reference to an integer that will be used to store the amount of time used(in milliseconds)
 * @post: sorts the vector using an implementation of the Selection Sort algorithm and measures the amount of time the sorting operation took (in milliseconds)
 * @return: an iterator to the middle index of the vector 
 **/
void selectionSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();

    for(std::vector<int>::iterator i = nums.begin(); i <= nums.end(); i++){
        std::vector<int>::iterator smallest = i;
        for(std::vector<int>::iterator j = i; j < nums.end(); j++){
            if(*j < *smallest){
                smallest = j;
            }
        }
        std::swap(*i,*smallest);
    }

    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();
}