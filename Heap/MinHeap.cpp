#include <iostream>
#include <vector>

class MinHeap {
    private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while(index > 0){
            int parent = (index-1)/2;
            if(heap[index] < heap[parent]){
                std::swap(heap[index], heap[parent]);
                index = parent;
            }else return;
        }
    }

    void heapifyDown(int index){
        int size = heap.size();
        while(index < size){
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int smallest = index;

            if(left < size && heap[left] < heap[smallest]) smallest = left;
            if(right < size && heap[right] < heap[smallest]) smallest = right;

            if(smallest != index){
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else return;
        }
    }

    public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int getMin(){
        if(heap.empty()) throw std::runtime_error("Heap is empty");
        return heap[0];
    }

    void removeMin(){
        if(heap.empty()) throw std::runtime_error("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
};

int main(){
    return 0;
}