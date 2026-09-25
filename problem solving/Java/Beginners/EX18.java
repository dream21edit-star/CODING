import java.util.Scanner;
public class EX18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number:");
        int n = sc.nextInt();
        sc.close();
        int a=0, b=1;
        if(n==1) System.out.println(a);
        else if(n==0) System.out.println("NULL");
        else {
            System.out.print(a+" ");
            System.out.print(b+" ");
        }
        for(int i=0; i<n-2; i++) {
            a = a+b;
            b = b+a;
            System.out.print(a);
            System.out.print(b);
        }
    }
}
