#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

void sort_helper(const std::vector<int>::iterator& first, const std::vector<int>::iterator& last)
{
    if (last - first > 1) {
        std::vector<int>::iterator middle = first + (last - first) / 2;
        sort_helper(first, middle);
        sort_helper(middle, last);
        std::inplace_merge(first, middle, last);
    }
}

int inPlaceMergeSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();
    sort_helper(nums.begin(), nums.end());
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();

    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size() / 2;
    if(nums.size() % 2 != 0){
        mid++;
    }
    return *mid;
}