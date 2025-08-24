java.util.*;

class PalindromeCheck {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        String inputString = input.nextLine();
        char[] chars = inputString.toLowerCase().toCharArray();
        
        int left = 0;
        int right = chars.length - 1;
        
        boolean isPalindrome = true;
        
        while(left < right){
            if(chars[left] != chars[right]) {
                isPalindrome = false;
                break;
            }
            left++;
            right--;
        }
        
        if(ispalindrome) System.out.println("A Palindrome.");
        else System.out.println("Not a Palindrome.");
        
        input.close();
    }
}