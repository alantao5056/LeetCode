import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
  static StreamTokenizer st;
  static int N;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    N = nextInt();
    
    // solve
    int[][] blocked = new int[N][2];
    int[] source = new int[2];
    int[] target = new int[2];

    for (int i = 0; i < N; i++) {
      blocked[i][0] = nextInt();
      blocked[i][1] = nextInt();
    }

    source[0] = nextInt();
    source[1] = nextInt();
    target[0] = nextInt();
    target[1] = nextInt();

    pw.println(isEscapePossible(blocked, source, target));

    br.close();
    pw.close();
  }

  private static boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
    Set<String> blocked_ = new HashSet<>();
    for (int i = 0; i < blocked.length; i++) {
      blocked_.add(blocked[i][0] + " " + blocked[i][1]);
    }

    // bfs source
    Set<String> visited = new HashSet<>();
    ArrayDeque<Integer> q = new ArrayDeque<>();
    q.add(source[0]);
    q.add(source[1]);
    visited.add(source[0] + " " + source[1]);

    int count = 0;
    while (count < 40001 && !q.isEmpty()) {
      count++;
      int x = q.poll();
      int y = q.poll();

      if (x == target[0] && y == target[1]) {
        return true;
      }

      String down = x+1 + " " + y;
      if (x+1 <= 999999 && !blocked_.contains(down) && !visited.contains(down)) {
        q.add(x+1);
        q.add(y);
        visited.add(down);
      }
      String up = x-1 + " " + y;
      if (x-1 >= 0 && !blocked_.contains(up) && !visited.contains(up)) {
        q.add(x-1);
        q.add(y);
        visited.add(up);
      }

      String left = x + " " + (y-1);
      if (y-1 >= 0 && !blocked_.contains(left) && !visited.contains(left)) {
        q.add(x);
        q.add(y-1);
        visited.add(left);
      }
      String right = x + " " + (y+1);
      if (y+1 <= 999999 && !blocked_.contains(right) && !visited.contains(right)) {
        q.add(x);
        q.add(y+1);
        visited.add(right);
      }
    }
    if (count < 40001) {
      return false;
    }

    // bfs target
    visited = new HashSet<>();
    q = new ArrayDeque<>();
    q.add(target[0]);
    q.add(target[1]);
    visited.add(target[0] + " " + target[1]);

    count = 0;
    while (count < 40001 && !q.isEmpty()) {
      count++;
      int x = q.poll();
      int y = q.poll();

      if (x == source[0] && y == source[1]) {
        return true;
      }

      String down = x+1 + " " + y;
      if (x+1 <= 999999 && !blocked_.contains(down) && !visited.contains(down)) {
        q.add(x+1);
        q.add(y);
        visited.add(down);
      }
      String up = x-1 + " " + y;
      if (x-1 >= 0 && !blocked_.contains(up) && !visited.contains(up)) {
        q.add(x-1);
        q.add(y);
        visited.add(up);
      }

      String left = x + " " + (y-1);
      if (y-1 >= 0 && !blocked_.contains(left) && !visited.contains(left)) {
        q.add(x);
        q.add(y-1);
        visited.add(left);
      }
      String right = x + " " + (y+1);
      if (y+1 <= 999999 && !blocked_.contains(right) && !visited.contains(right)) {
        q.add(x);
        q.add(y+1);
        visited.add(right);
      }
    }
    if (count < 40001) {
      return false;
    }
    return true;
  }

  private static int nextInt() throws Exception {
    st.nextToken();
    return (int) st.nval;
  }

  private static String nextString() throws Exception {
    st.nextToken();
    return st.sval;
  }
}