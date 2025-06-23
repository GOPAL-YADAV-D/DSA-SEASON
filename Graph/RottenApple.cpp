#include <iostream>
#include <vector>

void isPossible(std::vector<std::vector<int>> &fruitPeti, int n, int m, std::vector<bool>& visited){
    // The Function Checks if is it possible to rot all the fuites in the fruit peti
    // Returns true if all fruits can be rotted, otherwise false.
    if(n >= fruitPeti.size() ||  m >= fruitPeti[0].size() || n<0 || m<0 ){
        return;
    }

    if (fruitPeti[n][m] == 0)
    {
        visited[fruitPeti[0].size() * n + m ] = true;
        return;
    }
}


int main(){
    int rows, col;
    std::cin >> rows >> col;

    std::vector<std::vector<int>> fruitPeti(rows, std::vector<int>(col));

    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<col ; j++){
            std::cin >> fruitPeti[i][j];
        }
    }

    std::vector<bool> visited(rows * col , false);

}