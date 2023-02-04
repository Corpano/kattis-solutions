import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class unlockpattern {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        ArrayList<GridPosition> input = new ArrayList<GridPosition>();
        for (int i = 0; i < 9; i++){
            input.add(new GridPosition(i % 3, i / 3, scanner.nextInt()));
        }

        double dist = 0;
        for(int i = 1; i < 9; i++){
            final int ii = i;
            GridPosition current = input.stream().filter(x -> x.index == ii).findAny().orElse(null);
            GridPosition next = input.stream().filter(x->x.index == ii+1).findAny().orElse(null);

            int distX = Math.abs(current.x - next.x);
            int distY = Math.abs(current.y - next.y);
            if(current.x == next.x || current.y == next.y){
                dist += distX + distY;

            }else{
                int min = Math.min(distX, distY);
                int max = Math.max(distX, distY);

                dist += Math.sqrt(distX * distX + distY * distY);
            }
        }

        System.out.print(dist);
    }

    public static class GridPosition{
        public int x;
        public int y;
        public int index;

        public GridPosition(int x, int y, int index){
            this.x = x;
            this.y = y;
            this.index = index;
        }
    }
}
