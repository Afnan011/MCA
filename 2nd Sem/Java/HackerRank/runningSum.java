import java.util.Arrays;
import java.util.Scanner;

public class runningSum {
    
    private static int[] runningSum(int[] nums) {
       
        int res[] = new int[5];

        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            for (int j = 0; j <= i; j++) {
                sum += nums[j];
            }
            res[i] = sum;
        }
        return res;
    }
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        int a[] = new int[10];
        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }
        sc.close();

        int res[] = new int[10];
        res = runningSum(a);

        System.out.println(Arrays.toString(res) );

    }
}
