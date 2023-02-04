import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class judging {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        scan.nextLine();
        HashMap<String, Integer> dom = new HashMap<>(); // Integer stores the frequency of words
        for (int i = 0; i < n; i++) {
            String line = scan.nextLine();
            if (dom.containsKey(line)) dom.put(line, dom.get(line) + 1); // If we already have this word, increment value in hashmap
            else dom.put(line,1);
        }
        HashMap<String, Integer> kat = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String line = scan.nextLine();
            if (kat.containsKey(line)) kat.put(line, kat.get(line) + 1);
            else kat.put(line,1);
        }
        HashSet<String> compare = new HashSet<>(kat.keySet()); // Values must be unique in HashSet
        int max = 0;
        for (String line : compare) {
            if (dom.containsKey(line)) {
                max += Math.min(kat.get(line), dom.get(line)); // Minimum is how many are matching
            }
        }
        System.out.println(max);
    }
}
