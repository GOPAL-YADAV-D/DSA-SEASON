#include <iostream>

int main()
{
    int n;
    std::cout << "Enter the number of Elements in the array: ";
    std::cin >> n;

    int *numbers = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
        {
            std::cout << "False";
            return 0;
        }
    }

    std::cout << "True";
    return 0;
}