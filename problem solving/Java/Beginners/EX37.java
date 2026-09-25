import java.util.Arrays;
public class EX37 {
    public static void main(String[] args) {
        String str1= "listen", str2 = "silent";
        char[] arr1 = str1.toLowerCase().toCharArray(), arr2 = str2.toLowerCase().toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        if(Arrays.equals(arr1, arr2))
            System.out.println("\""+str1+"\" and "+"\""+str2+"\" are anagrams");
    }
}
