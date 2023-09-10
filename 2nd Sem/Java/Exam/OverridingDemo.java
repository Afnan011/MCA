public class OverridingDemo {
    public static void main(String[] args) {
        
        TwoSum ob;

        ob = new ThreeSum(2, 4, 6);
        System.out.println("sum = " + ob.sum());

        ob = new TwoSum(2, 6);
        System.out.println("sum = " + ob.sum());

    }
}

class TwoSum
{
    int a;
    int b;

    TwoSum(int a, int b)
    {
        this.a = a;
        this.b = b;
    }

    int sum()
    {
        return a+b;
    }

}

class ThreeSum extends TwoSum
{
    int c;

    ThreeSum(int a, int b, int c)
    {
        super(a, b);
        this.c = c;
    }

    int sum()
    {
        return a+b+c;
    }

}