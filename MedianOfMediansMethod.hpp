#include <vector>
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

int medianOfFive(int a, int b, int c, int d, int e) {
    int maxAB = (a > b) ? a : b;  // Compare a and b, and find the larger
    int maxCD = (c > d) ? c : d;  // Compare c and d, and find the larger
    int largerOfABCD = (maxAB > maxCD) ? maxAB : maxCD;  // Larger of the two previous comparisons

    // Compare e with the larger of a, b, c, d
    if (e > largerOfABCD) {
        // e is larger, forget about it
        // Now we have 2 pairs of values where we know which is larger: (e, largerOfABCD)
        // Compare the 2 larger to find the other value greater than the median
        return (e > largerOfABCD) ? std::min(e, largerOfABCD) : std::max(e, largerOfABCD);
    } else {
        // e is not larger, forget about largerOfABCD
        // Now we have 2 pairs of values where we know which is larger: (largerOfABCD, e)
        // Compare the 2 larger to find the other value greater than the median
        return (largerOfABCD > e) ? std::min(largerOfABCD, e) : std::max(largerOfABCD, e);
    }
}

// Partition the array around the pivot element and return the index of the pivot
std::vector<int>::iterator partition(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high, int pivot) {
    while (low <= high) {
        while (*low < pivot) {
            low++;
        }
        while (*high > pivot) {
            high--;
        }
        if (low <= high) {
            std::iter_swap(low, high);
            low++;
            high--;
        }
    }
    return low;
}

// Find the median of medians of a given subarray
int findMedianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    const int groupSize = 5;

    int size = std::distance(low, high) + 1;
    int numGroups = (size + groupSize - 1) / groupSize;

    std::vector<int> medians(numGroups, 0);

    for (int i = 0; i < numGroups; ++i) {
        auto groupLow = low + i * groupSize;
        auto groupHigh = std::min(groupLow + groupSize - 1, high);
        std::sort(groupLow, groupHigh + 1);
        medians[i] = *(groupLow + (groupHigh - groupLow) / 2);
    }

    return (numGroups == 1) ? medians[0] : findMedianOfMedians(medians, medians.begin(), medians.end() - 1);
}

// returns the median of medians of all elements contained between high and low, inclusive.
int medianOfMedians(std::vector<int>& nums, std::vector<int>::iterator low, std::vector<int>::iterator high) {
    const int groupSize = 5;

    if (std::distance(low, high) < groupSize) {
        std::sort(low, high + 1);
        return *(low + std::distance(low, high) / 2);
    }

    int pivot = findMedianOfMedians(nums, low, high);
    auto pivotIter = partition(nums, low, high, pivot);

    int k = std::distance(nums.begin(), pivotIter);

    if (k == nums.size() / 2) {
        return *pivotIter;
    } else if (k < nums.size() / 2) {
        return medianOfMedians(nums, pivotIter + 1, high);
    } else {
        return medianOfMedians(nums, low, pivotIter - 1);
    }
}
   

int medianOfMediansMethod(std::vector<int>& nums, int& duration) {
    auto start = HRC::now();
    std::vector<int>::iterator low = nums.begin();
    std::vector<int>::iterator high = nums.end() - 1;
    //int median = *medianOfMedians(nums, low, high);
    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();

    //return median;
}