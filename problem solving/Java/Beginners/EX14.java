public class EX14 {
    public static void main(String[] args) {
        int n =20;
        int i;
        for(i=1; i<=n; i++) {
            if(i%3!=0 && i%5!=0) continue;
            else System.out.println(i);
            i++;
        }
    }
}
