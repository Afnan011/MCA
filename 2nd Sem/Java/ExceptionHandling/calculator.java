package ExceptionHandling;

import java.util.Scanner;

public class calculator {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        char ch = 'y';

        try {
            do {
                System.out.println("Enter 2 numbers");

                int num1 = sc.nextInt();
                int num2 = sc.nextInt();

                System.out.println("Enter operator");
                ch = sc.next().charAt(0);

                float res = 0;

                switch (ch) {
                    case '+':
                        res = num1 + num2;
                        break;

                    case '-':
                        res = num1 - num2;
                        break;

                    case '*':
                        res = num1 * num2;
                        break;

                    case '/':
                        res = num1 / num2;
                        break;

                    case 'n':
                        System.out.println("Exiting...");
                        return;
                    default:
                        System.out.println("Enter valid operator");
                        continue;
                }
                System.out.println("res = " + res);

                System.out.println("Do you want to continue? (y/n)");
                ch = sc.next().charAt(0);

            } while (ch != 'n');

        } 
        catch (ArithmeticException e) {
            System.out.println("cannot divide by 0!");
        }

        catch (Exception e) {
            System.out.println("Something went wrong! Please check the input");
        }

        System.out.println("\n\nProgram terminated normally");
        sc.close();
    }

}
