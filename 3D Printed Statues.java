package printer;

import java.util.Scanner;

public class Printer {

    public static void main(String[] args) {
        int numOfPrints = new Scanner(System.in).nextInt();
        int numOfPrinters = 1;
        int daysPassed = 0;
        
        while(numOfPrinters < numOfPrints/2) {
            numOfPrinters *= 2;
            daysPassed++;
        }
        
        int printedPages = 0;
        while(printedPages < numOfPrints) {
            printedPages += numOfPrinters;
            daysPassed++;
        }
        
        System.out.print(daysPassed);
    }
}