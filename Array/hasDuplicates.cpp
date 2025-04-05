#include <iostream>



//Most Crude Way of doing it
// bool hasDuplicates(int numbers[], int n){
//     for(int i=0 ; i<n ; i++){
//         for(int j=0 ; j<n ; j++){
//             if(i==j){
//                 continue;
//             }else if(numbers[i] == numbers[j]){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main(){
    std::cout << "Enter the size of the array: ";
    int number_of_elements;
    std::cin >> number_of_elements;

    int num_array[number_of_elements];
    for(int i=0 ; i<number_of_elements ; i++){
        std::cin >> num_array[i];
    }

    std::cout << (hasDuplicates(num_array, number_of_elements)) ? "Duplicates Present." : "No Duplicates!";
}