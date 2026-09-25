import java.util.Scanner;
public class EX16 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number:");
        int num = sc.nextInt();
        sc.close();
        int f = 10;
        for(int i=1; i<=f; i++) System.out.println(num+" x "+i+" = "+(num*i));
        
    }
}
