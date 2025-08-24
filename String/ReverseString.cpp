#include <iostream>
#include <string>
using namespace std;

int main(){
    string inputString;
    cin >> inputString;
    
    cout << "Original String: " << inputString;
    reverse(inputString.begin(), inputString.end());
    cout << "Reverse String: " << inputString;
    
    // Two pointer approach to get the original String
    int left = 0;
    int right = inputString.size() - 1;
    
    while(left < right){
        swap(inputString[left], inputString[right]);
        left++;
        right--;
    }
    
    cout << "Original Recovered String: " << inputString;
    
    return 0;
}
