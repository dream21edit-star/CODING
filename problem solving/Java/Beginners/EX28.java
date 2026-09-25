public class EX28 {
    public static void main(String[] args) {
        int[] arr = {64, 34, 25, 12, 22, 11, 90};
        for(int i=0; i<arr.length-1; i++) {
            for(int j=0; j<arr.length-1-i; j++){
                if(arr[j+1]<arr[j]) {
                    int tmp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1] = tmp;
                }
            }
        }
        for(int num:arr) System.out.print(num+" ");
        System.out.println();
    }
}
