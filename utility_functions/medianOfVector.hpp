#include <vector>

int medianOfVector(std::vector<int>& nums){
    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size() / 2;
    if(nums.size() % 2 != 0){
        mid++;
    }

    return *mid;
}