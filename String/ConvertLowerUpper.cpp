#include <iostream>
#include <string>
using namespace std;

int main(){
    string inputString;
    cin >> inputString;
    
    cout << inputString << endl;
    
    for(int i=0 ; i<inputString.size() ; i++){
        char ch = inputString.at(i);
        if(islower(ch)){
            inputString[i] = toupper(ch);
        }else if(isupper(ch)){
            inputString[i] = tolower(ch);
        }
    }
    
    cout << inputString;
    return 0;
}
