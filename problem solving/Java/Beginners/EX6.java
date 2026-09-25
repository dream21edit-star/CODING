public class EX6 {
    public static void main(String[] args) {
        double principal = 1000.0, rate = 5.0;
        int time = 3;
        double  A = principal*Math.pow((1 + rate/100), time);
        double CI = A - principal;
        System.out.println("Amount after interest = "+A);
        System.out.println("Compound Interest     = "+CI);

    }
    
}
