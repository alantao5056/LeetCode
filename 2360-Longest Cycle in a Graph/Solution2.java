import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution2 {
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

  public static int longestCycle(int[] edges) {
    int n = edges.length;
    int[] in = new int[n];
    for (int i = 0; i < n; i++) {
      if (edges[i] == -1) continue;
      in[edges[i]]++;
    }
    boolean[] visited = new boolean[n];

    for (int i = 0; i < n; i++) {
      if (in[i] != 0 || visited[i]) continue;

      int cur = i;
      while (cur != -1 && in[cur] == 0) {
        visited[cur] = true;
        cur = edges[cur];
        if (cur != -1) {
          in[cur]--;
        }
      }
    }

    int max = -1;
    for (int i = 0; i < n; i++) {
      if (visited[i]) continue;

      int cur = i;
      int count = 0;
      do {
        cur = edges[cur];
        visited[cur] = true;
        count++;
      } while (cur != i);
      max = Math.max(max, count);
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