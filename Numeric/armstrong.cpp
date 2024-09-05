#include <iostream>
#include <cmath>

int power(int base, int exp){
    int result = 1;
    while(exp > 0){
        if(exp % 2 == 1){
            result *= base;
        }
        base*=base;
        exp/=2;
    }
    return result;
}

int main(){
    int num;
    std::cout << "Enter the number: ";
    std::cin >> num;

    //Brute force
    int duplicate = num;
    int sum=0;

    int length = static_cast<int>(log10(num)+1);

    while(num>0){
        int last_digit = num%10;
        sum+=power(last_digit, length);

        num/=10;
    }

    if(duplicate == sum){
        std::cout << "ArmStrong Number";
    }else{
        std::cout << "nope";
    }
}