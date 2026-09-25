public class EX32 {
    public static void main(String[] args) {
        String str = "Hello, World!";
        int Length = 0;
        char[] arr = str.toCharArray();
        //for(char c : str.toCharArray()) Length++;
        for(int i=0; i<(int)arr.length; i++) Length++;
        System.out.println("Length = "+Length);
    }
}
