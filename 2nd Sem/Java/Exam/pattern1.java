/**
 * pattern1
 */
public class pattern1 {

    public static void main(String[] args) {
        
        int n = 10;

        System.out.println("Factorial of 1- " + n + " is : ");

        fact(n);

    }

    private static void fact(int n)
    {
        int fact = 1;

        int i = 1;
        while(i <= n)
        {
            fact *= i;
            System.out.println(i + "! = " + fact);

            i++;
        }
    }

}