public class EX23 {
    public static void main(String[] args) {
        int n = 5;
        char x = '*';
        String esp = " ";
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                System.out.print(x+esp);
            }
            System.out.println();
        }
    }
    
}
