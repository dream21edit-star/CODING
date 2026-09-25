import java.util.Scanner;

public class EX1 {
    public static void main(String[] args) {
        int a, b;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number: ");
        a = sc.nextInt();
        System.out.println("Enter second number: ");
        b = sc.nextInt();
        int Sum = a + b;
        System.out.println("Sum = " + Sum);
        sc.close();
    }
}
