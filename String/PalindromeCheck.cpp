#include <iostream>
#include <string>
using namespace std;

int main(){
    string inputString;
    cin >> inputString;
    
    int left = 0;
    int right = inputString.size() - 1;
    
    bool isPalindrome = true;
    while(left < right){
        if(inputString.at(left) != inputString.at(right)) {
            isPalindrome = false;
            break;
        }
    }
    
    if(isPalindrome) cout << "String is a Palindrome.";
    else cout << "String is not a palindrome";
    
    return 0;
}
