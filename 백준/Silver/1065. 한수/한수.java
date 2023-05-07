import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int count = 0;

        for(int i=1; i<=N; i++) {
            if(i >= 100) {
                int[] arr = Integer.toString(i).chars().toArray();

                boolean isHan = true;
                int diff = arr[1] - arr[0];
                for (int j = 1; j < arr.length - 1; j++) {
                    if (arr[j + 1] - arr[j] != diff) {
                        isHan = false;
                        break;
                    }
                }

                if(isHan) {
                    count++;
                }
            } else {
                count++;
            }
        }

        System.out.println(count);
    }
}