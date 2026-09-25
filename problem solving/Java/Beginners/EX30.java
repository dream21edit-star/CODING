public class EX30 {
    public static void main(String[] args) {
        int[] arr1 = {1, 2, 3}, arr2 = {4, 5, 6};
        int[] arr = new int[arr1.length+arr2.length];
        for(int i=0; i<arr1.length; i++){
            arr[i]=arr1[i];
        }
        for(int i=0; i<arr2.length; i++){
            arr[arr1.length+i]=arr2[i];
        }
        for(int num:arr) System.out.print(num+" ");
        System.out.println();
    }
}
