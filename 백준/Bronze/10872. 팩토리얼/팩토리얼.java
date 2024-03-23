import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = Integer.parseInt(scanner.nextLine());

        if (N == 0) {
            System.out.println(1);
            return;
        }

        int result = 1;

        for (int i = 1; i <= N; i++) {
            result *= i;
        }

        System.out.println(result);
    }
}
