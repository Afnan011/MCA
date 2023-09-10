public class OverloadingDemo {
    
    public static void main(String[] args) {
        
        System.out.println("\nPassing integers: ");
        MathOperation ob1 = new MathOperation(10, 20);
        
        System.out.println("\nPassing double: ");
        MathOperation ob2 = new MathOperation(2.3, 3.2);

        System.out.println("\nInvoking method using the same object");
        ob1.sum(5, 3);
        ob1.sum(5.5, 3.2);

    }

}


class MathOperation
{
    MathOperation(int a, int b)
    {
        sum(a, b);
    }

    MathOperation(double a, double b)
    {
        sum(a, b);
    }

    void sum(int a, int b) {
        print(a,b);
        System.out.println("sum = " + (a+b));
    }

    void sum(double a, double b) {
        print(a,b);
        System.out.println("sum = " + (a+b));
    }
    
    void print(int a, int b) {
        System.out.println("a = " + a + ", b = " + b);
    }

    void print(double a, double b) {
        System.out.println("a = " + a + ", b = " + b);
    }
}
