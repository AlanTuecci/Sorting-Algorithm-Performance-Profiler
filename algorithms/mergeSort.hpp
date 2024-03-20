#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

//Internal method used to implement the Merge Sort algorithm
void mergeSortHelper(std::vector<int>& nums){
    if (nums.size() > 1) {
        std::vector<int>::iterator mid = nums.begin() + nums.size() / 2;

        std::vector<int> left(nums.begin(), mid);
        std::vector<int> right(mid, nums.end());

        mergeSortHelper(left);
        mergeSortHelper(right);

        std::merge(left.begin(), left.end(), right.begin(), right.end(), nums.begin());
    }
}

/**
 * @param: a reference to a vector of integers to be sorted
 * @param: a reference to an integer that will be used to store the amount of time used(in milliseconds)
 * @post: sorts the vector using an implementation of the Merge Sort algorithm and measures the amount of time the sorting operation took (in milliseconds)
 * @return: an iterator to the middle index of the vector 
 **/
void mergeSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();
    
    mergeSortHelper(nums);
    
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();
}