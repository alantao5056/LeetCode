import java.io.File;
import java.util.*;

public class Main {

  public static void main(String[] args) throws Exception {
    // read input
    Scanner sc = new Scanner(new File("1.in"));
    
    // solve
    String s1 = sc.next();
    String s2 = sc.next();
    String s3 = sc.next();
    
    System.out.println(isInterleave(s1, s2, s3));

    sc.close();
  }

  private static boolean isInterleave(String s1, String s2, String s3) {
    char[] c1 = s1.toCharArray();
    char[] c2 = s2.toCharArray();
    char[] c3 = s3.toCharArray();

    if (c3.length != c1.length + c2.length) {
      return false;
    }

    return recursion(c1, c2, c3, new boolean[s3.length()], 0, -1);
  }

  private static boolean recursion(char[] s1, char[] s2, char[] s3, boolean[] visited, int s1Idx, int s3Idx) {
    if (s1Idx == s1.length) {
      // found one, check if rest is the other string
      int curLetterIdx = 0;
      boolean found = true;
      for (int i = 0; i < visited.length; i++) {
        if (!visited[i]) {
          if (s3[i] == s2[curLetterIdx]) {
            curLetterIdx++;
          } else {
            found = false;
            break;
          }
        }
      }
      return found;
    }

    char target = s1[s1Idx];

    for (int i = s3Idx + 1; i < s3.length; i++) {
      if (s3[i] != target) continue;

      boolean[] newArr = Arrays.copyOf(visited, visited.length);
      newArr[i] = true;
      if (recursion(s1, s2, s3, newArr, s1Idx+1, i)) {
        return true;
      }
    }

    return false;
  }
}