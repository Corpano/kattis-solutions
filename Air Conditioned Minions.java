import java.util.*;

public class airconditioned {

    public static ArrayList<Pair> tempList = new ArrayList<>();
    public static ArrayList<Pair> minions = new ArrayList<>();
    public static HashMap<Integer, Integer> temperatures = new HashMap<Integer, Integer>();

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        ArrayList<Pair> minions = new ArrayList<>();

        int numOfMinions = scanner.nextInt();
        for(int i = 0; i < numOfMinions; i++){
            minions.add(new Pair(scanner.nextInt(), scanner.nextInt()));
        }

        minions.sort(Comparator.comparing((Pair p) -> p.left).reversed());

        int total =0;
        while(minions.size() > 0)
        {
            int l = minions.get(0).left;

            boolean needsConditioner = false;
            for(int x = 0; x < minions.size(); x++){
                if(minions.get(x).left <= l && minions.get(x).right >= l){
                    minions.remove(x);
                    needsConditioner = true;
                    x--;
                }
            }

            if(needsConditioner){
                total++;
            }
        }


        System.out.print(total);
    }

    static class Pair{
        public int left;
        public int right;

        public Pair(int left, int right){
            this.left = left;
            this.right = right;
        }

    }
}
