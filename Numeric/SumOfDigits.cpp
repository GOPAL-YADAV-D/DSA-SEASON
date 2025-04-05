#include <iostream>
#include <cmath>

int main(){
    std::cout << "Enter a Number: ";
    int number;
    std::cin >> number;

    //Brute force to obtain the single digit sum or digital root
    // int digits{0};
    // int sumOfDigits{0};
    // do{
    //     // Extracting the last digit and updating the number
    //     sumOfDigits += number%10;
    //     number /= 10;

    //     if(number == 0){
    //         number = sumOfDigits;
    //         sumOfDigits = 0;
    //         digits = log10(number) + 1;
    //     }

    // }while(digits != 1);

    //optimal approach
    int digitalRoot{0};
    digitalRoot = 1 + (number - 1)%9;

    std::cout << digitalRoot;

    return 0;
}