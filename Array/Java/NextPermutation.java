import java.util.*;

class NextPermutation {
    static void printArray(int[] nums) {
        for (int num : nums) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String args[]) {
        Scanner input = new Scanner(System.in);

        int n;
        System.out.print("Enter the number of Numbers: ");
        n = input.nextInt();

        int[] numbers = new int[n];

        System.out.println("Enter the numbers:");
        for (int i = 0; i < n; i++) {
            numbers[i] = input.nextInt();
        }

        System.out.print("Original: ");
        printArray(numbers);

        // Step 1: Find the breakpoint
        int breakPoint = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (numbers[i] < numbers[i + 1]) {
                breakPoint = i;
                break;
            }
        }

        if (breakPoint == -1) {
            // This is the last permutation, so reverse to get the first
            Arrays.sort(numbers);
        } else {
            // Step 2: Find the next greater number from the right
            for (int i = n - 1; i > breakPoint; i--) {
                if (numbers[i] > numbers[breakPoint]) {
                    int temp = numbers[i];
                    numbers[i] = numbers[breakPoint];
                    numbers[breakPoint] = temp;
                    break;
                }
            }

            // Step 3: Reverse the suffix
            int left = breakPoint + 1;
            int right = n - 1;
            while (left < right) {
                int temp = numbers[left];
                numbers[left] = numbers[right];
                numbers[right] = temp;
                left++;
                right--;
            }
        }

        System.out.print("Next Permutation: ");
        printArray(numbers);
        input.close();
    }
}
