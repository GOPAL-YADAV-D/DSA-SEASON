#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(){
    int num;
    std::cout << "Enter the Number: ";
    std::cin >> num;

    std::vector<int> divisors;

    //optimized way
    for(int i=1 ; i<=static_cast<int>(std::sqrt(num)) ; i++){
        if(num%i == 0){
            divisors.push_back(i);
            if(num/i != i){
                divisors.push_back(num/i);
            }
        }
    }

    std::sort(divisors.begin(),divisors.end());


    //Brute force
    // divisors.push_back(1);

    // int divisor = 2;
    // for(int i = 2 ; i<=num/2 ; i++){
    //     if(num % i == 0){
    //         divisor++;
    //         divisors.push_back(i);
    //     }
    // }

    // divisors.push_back(num);

    //looping over a vector
    for(const auto& element : divisors){
        std::cout << element << " ";
    }
}