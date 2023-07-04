package ArrayProblems;

import java.util.Arrays;

public class sumOfSubset {

    public static void main(String[] args) {
        int[] a = new int[] { 1, 2, 1, 4, 5 };

        // swap(a, 1, 3);
        int m = 2;
        int d = 3;
        int res = sum(a, m, d);

        System.out.println("Given array is : " + Arrays.toString(a));
        System.out.println(res);
    }

    private static int sum(int[] a, int m, int d) {

        int sum = 0;
        int count = 0;

        for (int i = 0; i < m; i++) {
            sum += a[i];
        }

        if (sum == d) {
            count++;
        }

        for (int i = m; i < a.length; i++) {
            sum += a[i];
            sum -= a[i - m];

            if (sum == d) {
                count++;
            }
        }

        return count;
    }
}
