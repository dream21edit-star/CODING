public class EX27 {
    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 4, 5};
        for(int num:arr) System.out.print(num+" ");
        System.out.println();
        int left = 0, right = arr.length-1;
        while(left<right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
        for(int num:arr) System.out.print(num+" ");
        System.out.println();
    }
}
