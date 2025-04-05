#include <iostream>
#include <unordered_map>
#include <vector>



int main(){
    std::vector<int> nums;
    
    int n;
    std::cout<<"Enter the number of Numbers: ";
    std::cin >> n;

    std::cout << "Enter the Numbers: \n";
    for(int i=0 ; i<n ; i++){
        int x;
        std::cin >> x;
        nums.push_back(x);
    }


    //Getting the index of two numbers with the Sum equal to target
    int target;
    std::cout<< "Enter the target Sum: ";
    std::cin >> target;

    std::unordered_map<int,int> visited;
    for(int i=0 ; i<n ; i++){
        int remainder = target - nums[i];
        if(visited.find(remainder) != visited.end()){
            std::cout << "Indices: " << visited[remainder] << "and" << i << std::endl;
            return 0;
        }
        visited[nums[i]] = i;
    }

    std::cout << "No two numbers found with the given target sum.";
    return 0;
}