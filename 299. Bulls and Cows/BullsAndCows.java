import java.io.PrintWriter;
import java.io.File;
import java.util.*;

public class BullsAndCows {
  static int N;
  
  public static void main(String[] args) throws Exception {
    // read input
    Scanner sc = new Scanner(new File("1.in"));
    // PrintWriter pw = new PrintWriter("1.out");
    N = sc.nextInt();
    String secret = sc.next();
    String guess = sc.next();
    
    // solve
    System.out.println(getHint(secret, guess));

    sc.close();
    // pw.close();
  }

  private static String getHint(String secret, String guess) {
    int[] numCount = new int[10];
    char[] secretChar = secret.toCharArray();
    char[] guessChar = guess.toCharArray();
    boolean[] visited = new boolean[secret.length()];

    int A = 0;
    for (int i = 0; i < secretChar.length; i++) {
      if (guessChar[i] != secretChar[i]) {
        numCount[secretChar[i] - '0']++;
      } else {
        A++;
        visited[i] = true;
      }
    }

    int B = 0;
    for (int i = 0; i < secretChar.length; i++) {
      if (visited[i]) continue;
      if (numCount[guessChar[i] - '0'] != 0) {
        numCount[guessChar[i] - '0']--;
        B++;
      }
    }

    return String.format("%dA%dB", A, B);
  }
}