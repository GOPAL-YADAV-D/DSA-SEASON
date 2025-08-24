#include <iostream>
using namespace std;

int value(int row, int col){
    int res = 1;
    for(int i=0 ; i < col ; i++){
        res = res - i;
        res = res / ( i + 1 );
    }
    
    return res;
}

int main(){
    int n,r;
    cin >> n >> r;
    cout << value(n,r);
}

#include <iostream>
using namespace std;

void pascalsRow(int row){
    int element = 1;
    cout << element << " ";
    
    for(int i=0 ; i<row ; i++){
        element *= (4-i);
        element /= (i+1);
        cout << element << " ";
    }
    
}

int main(){
    int n;
    cout << "Enter the Row to be printed: ";
    cin >> n;
    
    pascalsRow(n);
    
    return 0;
}