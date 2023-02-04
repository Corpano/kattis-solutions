package kattis;

import java.util.*;

public class guessing {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        ArrayList<Integer> optionsLeft = new ArrayList<Integer>(List.of(1,2,3,4,5,6,7,8,9,10));

        while(true) {
            int inputNum = Integer.parseInt(scanner.nextLine());
            if(inputNum == 0)
                break;
            String inputCommand = scanner.nextLine();

            switch(inputCommand) {
                case "too high":
                    optionsLeft.removeIf(x-> x >= inputNum);
                    break;
                case "too low":
                    optionsLeft.removeIf(x-> x <= inputNum);
                    break;
                case "right on":
                    if(optionsLeft.contains(inputNum)) {
                        System.out.println("Stan may be honest");
                    }else {
                        System.out.println("Stan is dishonest");
                    }

                    optionsLeft = new ArrayList<Integer>(List.of(1,2,3,4,5,6,7,8,9,10));
                    break;
            }
        }}
}