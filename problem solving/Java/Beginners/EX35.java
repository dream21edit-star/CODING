public class EX35 {
    public static void main(String[] args) {
        String str = "Hello, World! How are you?";
        StringBuilder result = new StringBuilder();
        for(char c: str.toCharArray()) {
            if(c!=' ') result.append(c);
        }
        System.out.println(result.toString());
    }
}

