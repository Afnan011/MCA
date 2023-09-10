public class PrimeAndArea {
    public static void main(String[] args) {
        
        findArea(5);
        
        System.out.println(isPrime(51));

    }


private static void findArea(float r)
{
    final float PI = 3.14f;

    float area = PI * r * r;
    float cir = 2 * PI * r;

    System.out.println("Area = " + area);
    System.out.printf("Circumference = %.2f\n", cir);
}

private static boolean isPrime(int n)
{
    if(n <= 1)
    {
        return false;
    }

    for(int i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

}