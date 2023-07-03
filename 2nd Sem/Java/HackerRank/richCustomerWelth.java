

public class richCustomerWelth {

    public static int maximumWealth(int[][] accounts) {

        int max = accounts[0][0];

        for(int i = 0; i<accounts.length; i++){
            int sum = 0;
            for (int j = 0; j < accounts[i].length; j++) {
                sum += accounts[i][j];
                if (sum > max) {
                    max = sum;
                }
            }
        }
        return max;
    }

    public static void main(String[] args) {
        
        int a[][] ={ {1,5},{7,3},{3,5} };

        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                System.out.print(a[i][j] + "  ");
            }
            System.out.println();
        }

        int res = maximumWealth(a);

        System.out.println("res = " + res);
    
    }


}
