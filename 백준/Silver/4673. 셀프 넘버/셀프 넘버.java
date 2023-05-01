import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        boolean[] arr = new boolean[10001];

        for(int i=1; i<10000; i++) {
            int first = i%10;
            int second = (i/10)%10;
            int third = (i/100)%10;
            int fourth = i/1000;

            int value = i + first + second + third + fourth;

            if(value <= 10000) {
                arr[value] = true;
            }
        }

        for(int i=1; i<=10000; i++) {
            if(!arr[i]) {
                System.out.println(i);
            }
        }
    }
}