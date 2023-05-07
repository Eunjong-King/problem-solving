import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] arr = new int[102][102];

        int left, down;
        for(int i=0; i<N; i++) {
            left = sc.nextInt();
            down = sc.nextInt();

            for(int a=0; a<10; a++) {
                for(int j=0; j<10; j++) {
                    arr[a+left][j+down] = 1;
                }
            }
        }

        int count = 0;

        for(int i=0; i<100; i++) {
            for(int j=0; j<100; j++) {
                if(arr[i][j] == 1) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}