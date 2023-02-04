package org.example;

import java.util.*;

public class haypoints {
    public static void main (String[] args){
        Scanner scanner = new Scanner(System.in);
        int numOfDescs = scanner.nextInt();
        int numOfJobs = scanner.nextInt();

        HashMap<String, Integer> money = new HashMap<>();

        for(int i = 0; i < numOfDescs; i++){
            String k = scanner.next();
            int v = scanner.nextInt();
            money.put(k, v);
        }

        for (int i = 0; i < numOfJobs; i++){
            int sum = 0;
            String value = scanner.next();
            while(value.charAt(0) != '.'){
                if(money.containsKey(value)){
                    sum += money.get(value);
                }
                value = scanner.next();
            }

            System.out.println(sum);
        }

    }
}
