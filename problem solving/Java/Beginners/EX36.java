public class EX36 {
    public static void main(String[] args){
        String str ="hello";
        int[] freq = new int[256];
        char[] arr = str.toCharArray();
        for(char c:arr) freq[c]++;
        for(char c:arr) {
            if(freq[c]>0) {
                System.out.println(c+": "+freq[c]);
                freq[c] = 0;
            }
        }
    }
}
