import java.util.Arrays;

public class testString {
    public static void main(String[] args) {
                
        String[] arr = {"",""};
        
        if(arr == null)
            System.out.println("it is null");
        else
            System.out.println("not null");


        System.out.println(Arrays.toString(arr));
    }
}
