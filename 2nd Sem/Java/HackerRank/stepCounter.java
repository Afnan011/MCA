public class stepCounter {
    
    public static int numberOfSteps(int num) {
        
        int stepCount = 0;

        while (num > 0) {
            if (num % 2 == 0) {
                num = num / 2;
            }
            else{
                num = num - 1;
            }
            stepCount++;
        }

        return stepCount;
    }

    public static void main(String[] args) {
        
        int n = 123;
        int res = numberOfSteps(n);

        System.out.println("res = " + res);

    }
}
