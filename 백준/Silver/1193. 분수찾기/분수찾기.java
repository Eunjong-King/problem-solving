import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        int i=1;
        for(; i<=10000000; i++){
            if(num <= i) {
                break;
            }
            num -= i;
        }

        if(i%2 == 1) {
            System.out.printf("%d/%d", i-num+1, num);
        } else {
            System.out.printf("%d/%d", num, i-num+1);
        }
    }
}