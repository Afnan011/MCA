import java.util.ArrayList;
import java.util.List;

public class fizzbuzz {
        public static List<String> fizzBuz(int n) {
        
        List<String> res = new ArrayList<>();
        for (int i = 1; i <=n; i++) {
            

            if((i % 3 == 0) && (i % 5 == 0)){
                res.add("FizzBuzz");
            }

            else if((i % 3 == 0)){
                res.add("Fizz");
            }

            else if((i % 5 == 0)){
                res.add("Buzz");
            }

            else{
                res.add(Integer.toString(i));
            }  
        }

        return res;
    }

    public static void main(String[] args) {
        
        int n = 15;
        
        List<String> res = new ArrayList<>();
        
        res = fizzBuz(n);

        for(String i: res)
        {
            System.out.print(i + "  ");
        }
    }
}
