import java.util.Scanner;
public class EX11 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Enter first number:");
        int a = sc.nextInt();
        System.out.println("Enter second number:");
        int b = sc.nextInt();
        System.out.println("Enter the operator (+, -, *, /):");
        char operator = sc.next().charAt(0);
        sc.close();
        switch(operator) {
            case '+': System.out.println(a+" + "+b+" = "+(a+b)); break;
            case '-': System.out.println(a+" - "+b+" = "+(a-b)); break;
            case '*': System.out.println(a+" * "+b+" = "+(a*b)); break;
            case '/': 
            if(b!=0) { System.out.println(a+" / "+b+" = "+(a/b)); }
            else { System.out.println("Error division: b should not equal 0"); return; }
            break;
        default: System.out.println("Operator should be one of the following list: +, -, *, /"); return;
        }
    }
}
