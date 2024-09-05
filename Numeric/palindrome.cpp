#include <iostream>

int main(){
    int n;
    std::cout << "Enter the Number: ";
    std::cin >> n;

    int enteredNum = n;

    //Reverse of a number
    int revNum = 0;
    while(n>0){
        revNum = revNum*10 + n%10;
        n=n/10;
    }

    if(enteredNum==revNum){
        std::cout << "Entered Number is a palindrome!!";
    }

}
