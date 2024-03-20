//Alan Tuecci
//January 13, 2023

#include <vector> 
#include <algorithm>
#include <chrono>
typedef std::chrono::milliseconds MSEC;
typedef std::chrono::high_resolution_clock HRC;

// Internal method used to update the child value in the percDown function
inline int newChild(int hole) {
    return hole * 2;
}

// Internal method to percolate down at a hole
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

// Internal method to build the heap
void buildHeap(std::vector<int> &heap) {
    for (int i = heap.size() / 2; i > 0; --i) {
        percDown(heap, i, heap.size());
    }
}

// Modify heapsort to sort the entire vector
int heapSort(std::vector<int> &nums, int &duration) {
    auto start = HRC::now();

    buildHeap(nums); 
    for (int i = nums.size(); i > 1; --i) {
        std::swap(nums[0], nums[i - 1]); 
        percDown(nums, 1, i - 1); 
    }

    auto end = HRC::now();
    auto execTime = std::chrono::duration_cast<MSEC>(end-start);
    duration = execTime.count();

    std::vector<int>::iterator mid = nums.begin() - 1 + nums.size() / 2;
    if(nums.size() % 2 != 0){
        mid++;
    }
    
    return *mid;
}
