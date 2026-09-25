public class EX24 {
    public static void main(String[] args) {
        int[] arr = {10, 20, 30, 40, 50};
        for(int i=0; i < arr.length-1; i++)
            System.out.printf("%d\t", arr[i]);
        System.out.println();
        /*alternative:
        
        for(int num : arr) System.out.print(num+" ");*/
    }
}
