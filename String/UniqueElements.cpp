#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
    string inputString;
    cin >> inputString;
    
    string finalString = "";
    set<char> unique;
    
    for(char ch: inputString){
        if(unique.find(ch) == unique.end()){
            finalString += ch;
            unique.insert(ch);
        }
    }
    
    cout << finalString;
    
    return 0;
}