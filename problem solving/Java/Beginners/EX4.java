import java.util.Scanner;
public class EX4 {
    public static void main(String[] args) {
        float length, width;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter length: ");
        length = sc.nextFloat();
        System.out.println("Enter width: ");
        width = sc.nextFloat();
        sc.close();
        float area = length*width;
        float perim = 2*(length + width);
        System.out.println("Area = "+area);
        System.out.println("Perimeter = "+perim);
    }
}
