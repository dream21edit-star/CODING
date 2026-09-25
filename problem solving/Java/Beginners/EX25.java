public class EX25 {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        int sum = 0;
        for(int num:arr) {
            sum+=num;
        }
        double moy = (double)sum/arr.length;
        System.out.println("sum = "+sum);
        System.out.println("average = "+moy);
    }
}
