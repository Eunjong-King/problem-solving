import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] inp = sc.nextLine().split(" ");

        long a = Long.parseLong(inp[0]);
        long b = Long.parseLong(inp[1]);

        if (b > a) {
            long temp = a;
            a = b;
            b = temp;
        }

        System.out.println(a - b);
    }
}
