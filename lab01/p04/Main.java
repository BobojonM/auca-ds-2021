import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        while (inp.hasNextLine()) {
            String line = inp.nextLine();
            System.out.println(isPalindrome(line) ? "palindrome" : "not palindrome");
        }
    }

    static boolean isPalindrome(String line) {
        StringBuilder builder = new StringBuilder();
        for (char c : line.toCharArray()) {
            if (Character.isLetter(c)) {
                builder.append(Character.toLowerCase(c));
            }
        }

        // reference semantics
        StringBuilder tmp = builder;
        tmp.reverse();

        return builder.toString().equals(tmp.toString());
    }
}