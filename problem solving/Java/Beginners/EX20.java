public class EX20 {
    public static void main(String[] args) {
        int num = 49311, sum = 0;
        while(num!=0) {
            int digit = num%10;
            sum = sum + digit;
            num /= 10;
        }
        System.out.println("Sum of digits = "+sum);
    }
}
