java.util.*;

class ReverseString {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        String inputString = input.nextLine();
        
        System.out.println("Original String: " + inputString);
        char[] chars = inputString.toCharArray();
        
        int left = 0;
        int right = chars.length - 1;
        while(left < right){
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
        
        String reversed = new String(chars);
        System.out.println("Reversed String: " + reversed);
    }
}