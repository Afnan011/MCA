package ArrayProblems;

import java.util.Arrays;

public class maxConsecutive1s {

    public static int findMaxConsecutiveOnes(int[] nums) {

        int max = 0;

        int i = 0;
        while(i < nums.length) {
            int count = 0;

            if (nums[i] == 1) {
                count++;
                int j;
                for (j = i + 1; j < nums.length && nums[j] == 1; j++) {
                    count++;
                }
                i = j;
            }
            else{
                i++;
            }

            if (max < count) {
                max = count;
            }
        }

        return max;

    }

    public static void main(String[] args) {

        int a[] = new int[]{1, 1, 0, 0, 1};


        System.out.println(findMaxConsecutiveOnes(a));
    }

}
