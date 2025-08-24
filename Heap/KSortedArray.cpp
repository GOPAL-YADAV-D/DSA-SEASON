#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& array, int k){
    std::vector<int> mergedArray;
    
    std::priority_queue<std::tuple<int,int,int> , std::vector<int>, std::greater<>> minHeap;
    
    //Inserting the First Element from each array
    for(int i=0 ; i<k ; i++){
        minHeap.push({array[i][0], i, 0});
    }
    
    while(!minHeap.empty()){
        auto [value, arrayIndex, elementIndex] = minHeap.top();
        minHeap.pop();
        
        mergedArray.push_back(value);
        
        if(elementIndex + 1 < array[arrayIndex].size()){
            minHeap.push({array[arrayIndex][elementIndex + 1], arrayIndex, elementIndex + 1});
        }
    }
    
    return mergedArray;
}

int main(){
    std::vector<std::vector<int>> sortedArrays;
    int k;
    std::cout << "Enter the number of Sorted Arrays: ";
    std::cin >> k;
    
    for(int i=0 ; i<k ; i++){
        int n;
        std::cout << "Enter the number of Elements for array " << i << " ";
        std::vector<int> array;
        for(int j=0 ; j<n ; j++){
            int element;
            std::cin >> element;
            array.push_back(element);
        }
        sortedArrays.push_back(array);
    }

    std::vector<int> result = mergeSortedArrays(sortedArrays, k);

    for(int i=0; i<result.size(); i++){
        std::cout << result[i] << " ";
    }
    return 0;
}