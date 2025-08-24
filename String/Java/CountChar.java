java.util.*;

class CountChar{
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        
        // Taking input Line
        String inputLine = input.nextLine();
        
        int vowel = 0, consonents = 0, digits = 0, symbols = 0;
        
        for(char ch: inputLine.toCharArray()){
            if(Character.isLetter(ch)){
                char lower = Character.toLower(ch);
                if(lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') vowel++;
                else consonents++;
            } else if(Character.isDigit(ch)) digit++;
            else symbols++;
        }
        
        System.out.println("Vowels: " + vowels);
        System.out.println("Consonents: " + consonents);
        System.out.println("Digits: " + digits);
        System.out.println("Symbols: " + symbols);
    }
}