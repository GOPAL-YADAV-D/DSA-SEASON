 #include <iostream>
 #include <cmath>

 int main(){
    int n;
    std::cout << "Enter the Number: ";
    std::cin >> n;

    //Brute force approach for counting number of digits

    // int count = 0;
    // while(n>0){
    //     n/=10;
    //     count++;
    // }
    // std::cout << "Number of digits in the Number are: " << count;


    //Optimized

    std::cout << int(log10(n) +1);
    return 0;
 }
