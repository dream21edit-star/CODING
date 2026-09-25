public class EX26 {
    public static void main(String[] args) {
        
        int[] arr = {34, 7, 23, 89, 12, 55};
        int max = arr[0], min = arr[0];
        for(int i=0; i<arr.length; i++)
            if(arr[i]<min) min = arr[i];
        for(int i=0; i<arr.length; i++)
            if(arr[i]>max) max = arr[i];
        System.out.println("Minimum = "+min);
        System.out.println("Maximum = "+max);

    }
}
