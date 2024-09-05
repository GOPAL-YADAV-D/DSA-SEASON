#include <iostream>

int main(){
    int numOne, numTwo;
    std::cout << "Enter the Numbers: ";
    std::cin >> numOne >> numTwo;

    // To find the GCD

    //Brute
    // int smaller = (numOne < numTwo) ? numOne:numTwo;
    // int hcf=1;
    // for(int i=smaller ; i>1 ; i--){
    //     if(numOne%i == 0 && numTwo%i == 0){
    //         hcf=i;
    //         break;
    //     }
    // }

    // std::cout << "Greatest Common Divisor is : " << hcf;

    //Euclid's Division Method
    int hcf = 1;
    while(numTwo !=0){
        int temp = numTwo;
        numTwo = numOne % numTwo;
        numOne = temp;
        hcf=numOne;
    }

    std::cout << "Greatest Common Divisor is: " << hcf;
}
