import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class dfroggereasy {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int numOfBoardSquares = scanner.nextInt();
        int currentSquare = scanner.nextInt() - 1;
        int magicNum = scanner.nextInt();

        Integer[] boardSquares = new Integer[numOfBoardSquares];
        for(int i = 0; i < numOfBoardSquares; i++){
            boardSquares[i] = scanner.nextInt();
        }

        ArrayList<Integer> visitedSquares = new ArrayList<>();
        int numOfTurns = 0;

        while (true){
            if(currentSquare >= boardSquares.length || currentSquare < 0)
            {
                System.out.println(currentSquare > 0 ? "right\n" + numOfTurns: "left\n" + numOfTurns);
                return;
            }
            if(visitedSquares.contains(currentSquare)){
                System.out.println("cycle\n" + numOfTurns);
                return;
            }
            if(boardSquares[currentSquare] == magicNum){
                System.out.println("magic\n" + numOfTurns);
                return;
            }
            visitedSquares.add(currentSquare);
            currentSquare += boardSquares[currentSquare];
            numOfTurns++;
        }
    }
}
