public class OuterInnerDemo {
    public static void main(String[] args) {
        
        Outer o = new Outer(10, 5);
        o.display();
        o.in.sum();

        //Outer.Inner n = o. new Inner(10);
        //n.sum();

    }
}


class Outer
{
    int a;
    Inner in;

    Outer(int a, int x)
    {
        this.a = a;
        in = new Inner(x);
    }


    void display()
    {
        System.out.println("a = "+ a + ", b = " + in.b);
    }

    class Inner
    {
        int b;

        Inner(int b)
        {
            this.b = b;
        } 

        void sum()
        {
            System.out.println("sum = "+ (a+b));
        }
    }

}
