
public class EX29 {
    public static void main(String[] args) {
        int[] arr = {1, 3, 4, 2, 3, 5, 4, 6};
        for (int i = 0; i < arr.length-1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    System.out.println("Duplicate found: " + arr[i]);
                    break;
                }
            }
        }
    }
}
