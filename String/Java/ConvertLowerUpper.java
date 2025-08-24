java.util.*;

class ConvertLowerUpper {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        String inputString = input.nextLine();
        
        System.out.println(inputString);
        
        char chars[] = inputString.toCharArray();
        
        for(int i=0 ; i<char.length ; i++){
            char ch = chars[i];
            if(Character.isLowerCase(ch)){
                chars[i] = Character.toUpperCase(ch);
            }else if(Character.isUpperCase(ch)){
                chars[i] = Character.toLowerCase(ch);
            }
        }
        
        String result = new String(chars);
        System.out.println(result);
        input.close();
    }
}