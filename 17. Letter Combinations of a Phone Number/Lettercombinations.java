import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Lettercombinations {
  static int length;
  static char[][] map = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'},
    {'j', 'k', 'l'},
    {'m', 'n', 'o'},
    {'p', 'q', 'r', 's'},
    {'t', 'u', 'v'},
    {'w', 'x', 'y', 'z'}
  };
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("lettercombinations.in"));
    PrintWriter pw = new PrintWriter("lettercombinations.out");

    String input = sc.next();
    length = input.length();
    letterCombinations(input);

    sc.close();
    pw.close();
  }

  private static List<String> letterCombinations(String digits) {
    if (length == 0) {
      return new ArrayList<>();
    }
    int[] intDigits = new int[length];
    for (int i = 0; i < length; i++) {
      intDigits[i] = digits.charAt(i)-'0'-1;
    }
    int[] comb = new int[length];
    List<String> result = new ArrayList<>();
    do {
      result.add(getComb(comb, intDigits));
    } while (addOne(comb, intDigits));

    return result;
  }

  private static String getComb(int[] comb, int[] digits) {
    StringBuilder sb = new StringBuilder();

    for (int i = 0; i < length; i++) {
      sb.append(map[digits[i]-1][comb[i]]);
    }

    return sb.toString();
  }

  private static boolean addOne(int[] comb, int[] digits) {
    int cur = length-1;

    while (cur > -1) {
      if (comb[cur] + 1 == (digits[cur]==8||digits[cur]==6?4:3)) {
        cur--;
      } else {
        comb[cur]++;
        break;
      }
    }

    if (cur == -1) {
      // cant add
      return false;
    }

    for (int i = cur+1; i < length; i++) {
      comb[i] = 0;
    }
    return true;
  }
}