#include <iostream>
#include <vector>
#include <algorithm>

class MaxHeap {
    public:
    std::vector<int> heap;
    MaxHeap(std::vector<int>& arr){
        heap = arr;
        heapify();
    }

    void heapifyDown(int index){
        int size = heap.size();
        while(index < size){
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;

            if(left < size && heap[left] > heap[largest]) largest = left;
            if(right < size && heap[right] > heap[largest]) largest = right;

            if(largest != index){
                std::swap(heap[index], heap[largest]);
                index = largest;
            }else return;
        }
    }

    void heapify(){
        int size = heap.size();
        for(int i = size/2 -1 ; i >= 0 ; i--){
            heapifyDown(i);
        }
    }

    void printHeap(){
        for(int i=0 ; i<heap.size() ; i++){
            std::cout << heap[i] << ' ';
        }
    }
};

int main(){
    std::vector<int> arr;
    int n, value;
    std::cout << "Enter then number of elements in the array: ";
    std::cin >> n;
    std::cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        std::cin >> value;
        arr.push_back(value);   
    }

    MaxHeap maxHeap(arr);
    std::cout << "Heap Before Sort: ";
    maxHeap.printHeap();
    
    std::vector<int> sortedArray;

    while(arr.size() > 1){
        sortedArray.push_back(maxHeap.heap[0]);
        maxHeap.heap[0] = maxHeap.heap.back();
        maxHeap.heap.pop_back();
        maxHeap.heapifyDown(0);
    }

    std::cout << "Sorted Array: ";
    for(int i = sortedArray.size() - 1; i >= 0; i--){
        std::cout << sortedArray[i] << ' ';
    }
    std::cout << std::endl;

    return 0;
}

