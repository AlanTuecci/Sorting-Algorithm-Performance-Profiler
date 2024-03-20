#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

int standardSort ( std::vector<int>& nums, int& duration ){

    auto start = HRC::now();
    std::sort(nums.begin(), nums.end());
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();

    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size()/2;
    if(nums.size() % 2 != 0){
        mid++;
    }

    return *mid;
}

//On input 9, this took 264 milliseconds