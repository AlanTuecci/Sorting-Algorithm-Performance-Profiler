#include <vector>
#include <iostream>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

int halfSelectionSort ( std::vector<int>& nums, int& duration ){

    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size() / 2;
    if(nums.size() % 2 != 0){
        mid++;
    }


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

    return *mid;
}

//This took 4.5 hours on input 9