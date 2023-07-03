// import java.util.Scanner;

public class armstrong {

    public static void main(String[] args) {

        
        /*    
        //check the given number is armstrong or not
        
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        sc.close();

        boolean flag = isArmStrong(n);

        if (flag) {
        System.out.println(n + " is an Armstrong number");
        } else {
        System.out.println(n + " is Not an Armstrong number");
        }
     */    

        //print all the 3 digit armstrong numbers
        for (int i = 100; i <= 999; i++) {
            
            if (isArmStrong(i)) {
                System.out.print(i + " ");
            }
        }

    }

    private static boolean isArmStrong(int n) {
        int rem, cube, sum;
        sum = 0;
        int temp = n;

        while (n > 0) {
            rem = n % 10;
            cube = rem * rem * rem;
            sum += cube;

            n = n / 10;
        }

        if (temp == sum)
            return true;

        return false;
    }

}