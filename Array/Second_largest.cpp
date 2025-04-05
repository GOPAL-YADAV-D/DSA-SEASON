#include <iostream>

int main()
{
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    if (n <= 0 || n == 1)
    {
        std::cout << -1;
        return 0;
    }

    int *numbers = new int[n];
    std::cout << "Enter the Numbers: ";
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    // To find the second highest number
    // Sort the array and then take the second last value

    // Solution
    int max = numbers[0];
    int second_max = numbers[0];

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > max)
        {
            second_max = max;
            max = numbers[i];
        }
    }
}