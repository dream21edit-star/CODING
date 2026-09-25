public class EX31 {
    public static void main(String[] args) {
        int[][] A = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int[][] B = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
        int[][] C = new int[A.length][B.length];
        int n=3;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                C[i][j]=A[i][j]+B[i][j];
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++)
                System.out.printf("%d\t", C[i][j]);
            System.out.println();
        }
    }
}
