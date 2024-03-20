
#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

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

int mergeSort ( std::vector<int>& nums, int& duration ){
    auto start = HRC::now();
    mergeSortHelper(nums);
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();

    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size() / 2;
    if(nums.size() % 2 != 0){
        mid++;
    }
    return *mid;
}