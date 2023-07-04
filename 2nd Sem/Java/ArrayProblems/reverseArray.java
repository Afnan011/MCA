package ArrayProblems;

import java.util.Arrays;

public class reverseArray {

    public static void main(String[] args) {

        int[] a = new int[] { 1, 2, 3, 4, 5 };

        // swap(a, 1, 3);
        reverse(a);

        System.out.println(Arrays.toString(a));
    }

    private static void reverse(int[] a) {

        int start = 0;
        int end = a.length - 1;

        while(start < end)
        {
            swap(a, start, end);
            start++;
            end--;
        }

    }

    private static void swap(int[] a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

}
