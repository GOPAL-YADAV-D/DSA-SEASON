#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        int k;

        cin >> n >> k;

        vector<int> a(n);

        for(int i=0 ; i<n ; i++){
            int weather ;
            cin >> weather;
            a[i] = weather;
        }

        int count = 0;
        int left = 0 ;
        int right = 0;

        for(int i=0 ; i<n ; i++){
            bool peakReached = false;
            if(a[i] == 0){
                int num = 0;
                int j = i ;
                while(num < k){
                    if(a[j] == 1){
                        break;
                    }else{
                        num++;
                        j++;
                    }
                }
                if(num == k) {
                    count++;
                    peakReached = true;
                }
                i = j - 1;

                if(peakReached) i++;
            }   
        }

        cout << count << endl;
    }

    return 0;
}