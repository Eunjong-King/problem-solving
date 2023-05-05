import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();

        String s = str.chars().mapToObj(c -> Character.toString(c))
                .sorted(Comparator.reverseOrder())
                .collect(Collectors.joining());
        System.out.println(s);
    }
}