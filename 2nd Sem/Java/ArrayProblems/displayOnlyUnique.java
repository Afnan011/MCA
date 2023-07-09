package ArrayProblems;

public class displayOnlyUnique {
    public int removeDuplicates(int[] nums) {

        int i = 0;
        int j = 0;

        int count = 0;

        while (i < nums.length) {
            if (!found(nums, i)) {
                nums[j++] = nums[i];
            }
            i++;
        }

        return j;

    }

    private boolean found(int[] nums, int k) {
        for (int i = k - 1; i >= 0; i--) {
            if (nums[i] == nums[k]) {
                return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {

        displayOnlyUnique ls = new displayOnlyUnique();

        int[] a = { 1, 1, 2, 3 };
        int res = ls.removeDuplicates(a);

        System.out.println("res = " + res);

    }
}