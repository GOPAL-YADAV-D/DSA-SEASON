java.util.*;

class UniqueElements {
    public static void main(String args[]){
        Scanner input = new Scanner(System.in);
        String inputString = input.nextLine();
        
        LinkedHashSet<Character> unique = new LinkedHashSet<>();
        
        for(char ch: inputString.toCharArray()){
            unique.add(ch);
        }
        
        StringBuilder result = new StringBuilder();
        for(char ch:unique){
            result.append(ch);
        }
        
        System.out.println(result.toString());
        input.close();
    }
}