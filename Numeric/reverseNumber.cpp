 #include <iostream>
 #include <string>
#include <algorithm>
#include <cmath>

 int main(){
    int n;
    std::cout << "Enter the NUmber: ";
    std::cin >> n;

    //Method one
    /*What i will try to do is to convert to a string -> reverse it -> and then convert to integer again*/

    std::string toString = std::to_string(n);
    std::reverse(toString.begin(),toString.end());

    std::cout << std::stoi(toString);

    //Method two
    int digits = log10(n)+1;

    int revNum = 0;
    for(int i=0 ; i<digits ; i++){
        int last = n%10;
        n=n/10;

        std::cout << "Last Digit: " << last << "\n";

        revNum+= last*(static_cast<int>(pow(10,digits-1-i)));
        std::cout << "Current Reverse Number: " << revNum << "\n";
    }

    std::cout<< revNum;


    int newRev =0;
    while(n>0){
        newRev = newRev * 10 + n % 10 ;
        n = n/10;
    }

    std::cout << newRev;

    return 0;

 }
