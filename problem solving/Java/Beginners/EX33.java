public class EX33 {
    public static void main(String[] args) {
        String str="RaceCar";
        boolean isPalindrome = true;
        String Lstr = str.toLowerCase();
        int leftIndex = 0, rightIndex = Lstr.length()-1;
        char left = Lstr.charAt(leftIndex);
        char right = Lstr.charAt(rightIndex);
        while(leftIndex<rightIndex) {
            if(left == right) { 
                leftIndex++; rightIndex--;
            } else {
                isPalindrome = false;
                break;
            }
        }
        if(isPalindrome) System.out.println("\""+str+"\" is a Palindrome");
        else System.out.println("\""+str+"\" is not a Palindrome");

    }
}
