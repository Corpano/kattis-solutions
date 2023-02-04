import java.util.*;
// aaaaaaaaaardvarkk -> ardvrk
// aaaaaaaaaaaaaaa -> aa, same for consonants
// First and last vowels should not be removed
public class liquidassets {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        HashSet<Character> vowels = new HashSet<>();
        String str = new String();
        vowels.add('a'); vowels.add('e'); vowels.add('i'); vowels.add('o'); vowels.add('u');

        int numOfWords = scan.nextInt();
        while (numOfWords > 0) {
            String toAdd = "";
            String word = scan.next();
            char lastC = word.charAt(0);
            toAdd += lastC;
            for (int i = 1; i < word.length(); i++) {
                char c = word.charAt(i);

                if (c != lastC) { // won't access out of bounds ever
                    toAdd += c;
                }

                lastC = c;

            }

            for(int i = 1; i < toAdd.length()-1; i++){
                char c = toAdd.charAt(i);
                if (vowels.contains(c)) {
                    toAdd = toAdd.substring(0, i) + toAdd.substring(i+1, toAdd.length());
                    i--;
                }
            }

            str += toAdd + " "; //Adding spaces unless last word
            numOfWords--;
        }
        System.out.println(str);
        scan.close();
    }
}