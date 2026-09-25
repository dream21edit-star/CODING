import java.util.Scanner;
public class EX10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the year: ");
        int year = sc.nextInt();
        sc.close();
        if((year%4==0 && year%100!=0) || year%400==0) System.out.println(year+" is a leap Year");
        else System.out.println(year+" is not a Leap Year you stupid (I don't even know what does it mean btw..)");
    }
}
