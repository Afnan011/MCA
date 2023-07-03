package ArrayProblems;

public class numWithEvenDigit {
    private static int getCount(int n) {
        int count = 0;
        while (n > 0) {
            count++;
            n /= 10;
        }

        return count;
    }

    private static int findNumbers(int[] nums) {

        int res = 0;

        for (int num : nums) {
            if (getCount(num) % 2 == 0) {
                res++;
            }

        }

        return res;
    }

    public static void main(String[] args) {

        int a[] = new int[] {12, 223, 2, 656, 45, 236};

        System.out.println(findNumbers(a));

    }
}
