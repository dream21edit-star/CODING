import java.util.Scanner;

public class EX7 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number: ");
        int num = sc.nextInt();
        double square = Math.pow(num, 2);
        double cube =  Math.pow(num, 3);
        sc.close();
        System.out.println("Square of "+num+" = "+square);
        System.out.println("Cube of "+num+" = "+cube);


    }    
}
