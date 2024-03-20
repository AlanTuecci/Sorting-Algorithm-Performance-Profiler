#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

//Internal method used to implement the merge sort algorithm
void sort_helper(const std::vector<int>::iterator& first, const std::vector<int>::iterator& last){
    if (last - first > 1){
        std::vector<int>::iterator middle = first + (last - first) / 2;
        sort_helper(first, middle);
        sort_helper(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

/**
 * @param: a reference to a vector of integers to be sorted
 * @param: a reference to an integer that will be used to store the amount of time used(in milliseconds)
 * @post: sorts the vector using an implementation of the In-Place Merge Sort algorithm and measures the amount of time the sorting operation took (in milliseconds)
 * @return: an iterator to the middle index of the vector 
 **/
void inPlaceMergeSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();
    
    sort_helper(nums.begin(), nums.end());
    
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();
}