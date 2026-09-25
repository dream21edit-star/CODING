public class EX2 {
    public static void main(String[] args) {
        int a=5, b=10, tmp;
        System.out.println("Before swap: a = " + a + ", b = " + b);
        tmp = a;
        a = b;
        b = tmp;
        System.out.println("After swap: a = "+a+", b = "+b);
    }
}
