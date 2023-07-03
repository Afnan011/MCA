import java.util.Scanner;

public class matrixDiagonal {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[][] a = new int[3][3];
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                a[i][j] = sc.nextInt();
            }
        }

        matrix(a);

    }

    private static void matrix(int[][] a) {

        int s1 = 0;
        int s2 = 0;
        int res = 0;

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {

                int n = a[i].length - 1;
                if (i == j) {
                    s1 += a[i][j];
                    s2 += a[i][n - j];
                }

            }
        }

        res = Math.abs((s1 - s2));

        System.out.println(res);

    }

}
