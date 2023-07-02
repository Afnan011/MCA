import java.util.Scanner;

public class prime {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        int n = sc.nextInt();
        sc.close();

        if(n == 1){
            System.out.println(n + " is neither composite nor prime number.");
            return;
        }

        boolean flag = isPrime(n);

        if(flag){
            System.out.println(n + " is a prime number.");
        }
        else{
            System.out.println(n + " is not a prime number.");
        }

    }

    private static boolean isPrime(int n)
    {
        boolean flag = true;
        int count = 1;

        if(n > 1){
            for (int i = 2; i*i <= n; i++) {            //i*i squaring method more efficient 
                if (n % i == 0) {
                    System.out.println(i);
                    flag = false;
                }
                count++;
            }
        }
        else{
            System.out.println("Must be positive integers");
            flag = false;
        }
        System.out.println("count is : "+ count);
        return flag;
    }
}
