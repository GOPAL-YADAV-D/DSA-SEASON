#include <iostream>

int main()
{

    // Taking input of number of elements in the array
    int n;
    std::cout << "Enter the number of Elements: ";
    std::cin >> n;

    // Taking the Elements of the arra
    int numbers[n];
    std::cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    // Dynamically Creating the Elements
    //  int* numbers_dynamic = new int[n];
    //  for(int i=0 ; i<n ; i++){
    //      std::cin >> numbers_dynamic[i];
    //  }

    // Brute force

    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    std::cout << "Largest Number in the Series: " << max;
}