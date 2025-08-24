#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin >> t;

    for(int i=0 ; i<t ; i++){
        int x;
        cin >> x;
        int length = log10(x) + 1;

        int smallest = 10;
        for(int i=0 ; i<length ; i++){
            int digit = (x / static_cast<int>(pow(10, i))) % 10;
            if(digit < smallest) {
                smallest = digit;
            }
        }

        cout << smallest << endl;
    }

    return 0;
}