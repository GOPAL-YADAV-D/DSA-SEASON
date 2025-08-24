#include <iostream>
#include <string>
using namespace std;

int main(){
    string inputString;
    getline(cin, inputString);
    
    int vowels = 0, consonents = 0, digits = 0, symbols = 0;
    
    for(char ch: inputString){
        if(isalpha(ch)){
            char lower = tolower(ch);
            if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') vowels++;
            else consonents++;
        }else if(isdigit(ch)) digits++;
        else symbols++;
    }
    
    cout << "Vowels: " << vowels << endl;
    cout << "Consonents: " << consonents << endl;
    cout << "Digits: " << digits << endl;
    cout << "Symbols: " << symbols << endl;
    
    return 0;
}
