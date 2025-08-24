#include <iostream>
#include <vector>
#include <algorithm>

void leftRotateByOne(std::vector<int>& arr);
void printArray(const std::vector<int>& arr);

int main(){
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;
    
    std::vector<int> numbers;
    std::cout << "Enter the elements of the array: ";
    for(int i=0 ; i<n ; i++){
        int element;
        std::cin >> element;
        numbers.push_back(element);
    }

    std::cout << "Array before left rotation: ";
    printArray(numbers);

    std::cout << std::endl;
    leftRotateByOne(numbers);
    std::cout << "Array after left rotation by one: ";
    printArray(numbers);

    return 0;
}

void leftRotateByOne(std::vector<int>& arr){
    if(arr.empty()) return;

    int pointer = arr.size() - 1;
    while(pointer > 0){
        std::swap(arr[pointer], arr[0]);
        pointer--;
    }
}

void printArray(const std::vector<int>& arr){
    for(const auto& num: arr){
        std::cout << num << " ";
    }
    std::cout << std::endl;
}