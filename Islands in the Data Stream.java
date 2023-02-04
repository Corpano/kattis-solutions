package kattis;

import java.util.*;

public class islands {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numOfRows = Integer.parseInt(scanner.nextLine());

        for(int i = 0; i < numOfRows; i++) {
            String[] elements = scanner.nextLine().split(" ");
            ArrayList<Integer> inputValues = new ArrayList<Integer>();

            for(int x = 1; x < elements.length; x++) {
                inputValues.add(Integer.parseInt(elements[x]));
            }

            printNumOfIslands(inputValues, i + 1);
        }
    }
    public static void printNumOfIslands(ArrayList<Integer> inputSet, int dataSetNum) {
        int total = 0;

        for(int i = 1; i < inputSet.size() - 1; i++) {
            int left = inputSet.get(i);
            int leftOfLeft = inputSet.get(i - 1);
            int lowestPoint = left;

            if(left > leftOfLeft) {
                for(int x = i; x < inputSet.size() - 1; x++) {
                    int right = inputSet.get(x);
                    int rightOfRight = inputSet.get(x + 1);

                    if(right < lowestPoint)
                        lowestPoint = right;

                    if(lowestPoint > leftOfLeft && lowestPoint > rightOfRight)
                        total++;
                }
            }
        }

        System.out.println(dataSetNum + " " + total);
    }
}
