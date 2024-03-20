#include <vector> 
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

// Internal method used to update the child value in the percDown function
inline int newChild(int hole) {
    return hole * 2;
}

// Internal method used to percolate down at a hole
void percDown(std::vector<int> &heap, std::vector<int>::size_type hole, std::vector<int>::size_type size) {
    int tmp = std::move(heap[hole - 1]); 
    int child = newChild(hole);

    while (child <= size) {
        if (child < size && heap[child - 1] < heap[child]) {
            ++child; 
        }
        if (tmp < heap[child - 1]) {
            heap[hole - 1] = std::move(heap[child - 1]); 
        } else {
            break; 
        }
        hole = child;
        child = newChild(hole);
    }
    heap[hole - 1] = std::move(tmp);
}

// Internal method used to build the heap
void buildHeap(std::vector<int> &heap) {
    for (int i = heap.size() / 2; i > 0; --i) {
        percDown(heap, i, heap.size());
    }
}

/**
 * @param: a reference to a vector of integers to be sorted
 * @param: a reference to an integer that will be used to store the amount of time used (in milliseconds)
 * @post: sorts the vector using an implementation of Heap Sort algorithm and measures the amount of time the sorting operation took (in milliseconds)
**/
void heapSort(std::vector<int> &nums, int &duration) {
    auto start = HRC::now();

    buildHeap(nums); 
    for (int i = nums.size(); i > 1; --i) {
        std::swap(nums[0], nums[i - 1]); 
        percDown(nums, 1, i - 1); 
    }

    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();
}
