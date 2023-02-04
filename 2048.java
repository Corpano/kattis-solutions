import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class k2048 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int[][] board = new int[4][4];
        int[][] inverseBoard = new int[4][4];
        for(int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                board[x][y] = scanner.nextInt();
                inverseBoard[y][x] = board[x][y];
            }
        }

        int moveDir = scanner.nextInt();
        for(int i = 0; i < 4; i++) {

            if(moveDir == 0 || moveDir == 2){
                board[i] = Add(board[i], moveDir == 2 ? true : false);
            }else{
                inverseBoard[i] = Add(inverseBoard[i], moveDir == 3 ? true : false);
            }
        }

        for (int x = 0; x < 4; x++){
            for (int y = 0; y < 4; y++){
                int num = (moveDir != 1 && moveDir != 3) ? board[x][y] : inverseBoard[y][x];
                System.out.print(num + (y == 3 ? "\n": " "));
            }
        }
    }

    public static int[] Add(int[] arr, boolean inverse){
        ArrayList<Integer> arrList = new ArrayList<Integer>();
        for(int i = 0; i < 4; i++)
        {
            arrList.add(inverse ? arr[3-i] : arr[i]);
        }

        int curr = 0;
        while(curr + 1 < arrList.size() && curr + 1 >= 0) {
            if ((int) arrList.get(curr) == 0) {
                arrList.remove(curr);
            } else if ((int) arrList.get(curr + 1) == 0)
            {
                arrList.remove(curr + 1);
            }
            else if((int)arrList.get(curr) == (int)arrList.get(curr + 1) ){
                arrList.set(curr, arrList.get(curr) * 2);
                arrList.set(curr + 1, 0);
                curr += 1;
            }else{
                curr++;
            }
        }

        int[] result = new int[4];
        for(int i = 0; i < 4; i++){
            int index  = inverse ? 3 - i : i;
            result[i] = arrList.size() > index ? arrList.get(index) : 0;
        }
        return result;
    }
}