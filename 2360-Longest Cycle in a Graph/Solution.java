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
    int[] edges = new int[N];
    for (int i = 0; i < N; i++) {
      edges[i] = nextInt();
    }

    pw.println(longestCycle(edges));

    br.close();
    pw.close();
  }

  private static int longestCycle(int[] edges) {
    int n = edges.length;
    boolean[] visited = new boolean[n];

    int max = -1;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;

      HashSet<Integer> v = new HashSet<>();

      int cur = i;
      while (cur != -1 && !visited[cur]) {
        visited[cur] = true;
        v.add(cur);
        cur = edges[cur];
      }

      if (cur != -1 && v.contains(cur)) {
        // found cycle
        int count = 0;
        int start = cur;
        do {
          count++;
          cur = edges[cur];
        } while (cur != start);

        max = Math.max(max, count);
      }
    }

    return max;
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