import java.util.Scanner;
public class EX22 {
    public static void main(String[] args) {
        int digit = 0, sum = 0;
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Write a number (integer type): ");
        int num = sc.nextInt();
        int digits = String.valueOf(num).length();
        sc.close();
        int tmp = num;
        while(tmp!=0){
            digit = tmp%10;
            sum +=(int)Math.pow(digit, digits);
            tmp /= 10;
        }
        
        if(num==sum) System.out.println(num+" is an Amstrong Number");
        else System.out.println("Sorry... try again");
    }
}

