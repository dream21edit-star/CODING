import java.util.Scanner;
public class EX17 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number:");
        int n = sc.nextInt();
        sc.close();
        if(n<0) System.out.println("The number should be positive");
        int fact = 1;
        for(int i=1; i<=n; i++) fact *= i;
        System.out.println("Factorial of "+n+" = "+fact);
    }
}
