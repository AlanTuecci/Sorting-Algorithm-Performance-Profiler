#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

/**
 * @param: a reference to a vector of integers to be sorted
 * @param: a reference to an integer that will be used to store the amount of time used (in milliseconds)
 * @post: sorts the vector using the STl sort() function and measures the amount of time the sorting operation took (in milliseconds)
 * @return: an iterator to the middle index of the vector 
 **/
void standardSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();

    std::sort(nums.begin(), nums.end());
    
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();
}