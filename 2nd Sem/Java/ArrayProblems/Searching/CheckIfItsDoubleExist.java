package ArrayProblems.Searching;

import java.util.HashSet;
import java.util.Set;

/**
 * CheckIfItsDoubleExist
 */
public class CheckIfItsDoubleExist {

    public static void main(String[] args) {

        int[] arr = { -2, 0, 10, -19, -4, 6, -8 };

        // Set<Integer> set = new HashSet();

        // for (int i : arr) {
        // if (set.contains(2 * i) || (i % 2 == 0 && set.contains(i / 2))) {
        // System.out.println(true);
        // return;
        // }
        // set.add(i);
        // }

        // System.out.println(false);

        // }

        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length; j++) {

                if (i != j && arr[i] == 2 * arr[j]) {
                    System.out.println(true);
                }
            }
        }

        System.out.println(false);

    }

}