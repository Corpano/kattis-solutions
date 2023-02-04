import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;

public class bank {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int numOfCustomers = scanner.nextInt();
        int maxWaitTime = scanner.nextInt();

        ArrayList<Customer> customers = new ArrayList<>();

        for(int i = 0; i < numOfCustomers; i++)
        {
            Customer c = new Customer(scanner.nextInt(), scanner.nextInt());
            customers.add(c);
        }

        customers.sort(Comparator.comparing((Customer c)-> c.money).reversed());
        HashSet<Integer> occupiedSpots = new HashSet<>();

        int sumOfMoney = 0;

        for(int i = 0; i < customers.size(); i++){
            for(int x = customers.get(i).waitTime; x >= 0; x--) {
                if(occupiedSpots.contains(x))
                    continue;

                occupiedSpots.add(x);
                sumOfMoney+= customers.get(i).money;
                break;
            }
        }

        System.out.print(sumOfMoney);
    }

    static class Customer{
        public int money;
        public int waitTime;

        public Customer(int money, int waitTime){
            this.money = money;
            this.waitTime = waitTime;
        }
    }
}