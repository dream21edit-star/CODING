public class EX38 {
    public static boolean isEven(int num) {
        return num%2 == 0;
    }
    public static void main(String[] args){
        int a = 4, b = 7;
        System.out.println(a+" is even: "+isEven(a));
        System.out.println(b+" is even: "+isEven(b));
    }
}
