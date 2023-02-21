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
    int[] stones = new int[N];
    for (int i = 0; i < N; i++) {
      stones[i] = nextInt();
    }

    pw.println(maxJump(stones));

    br.close();
    pw.close();
  }

  private static int maxJump(int[] stones) {
    int n = stones.length;
    int low = 0;
    int high = stones[n-1] - stones[0];
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low) / 2;
      if (works(stones, mid))
        high = mid;
      else
        low = mid + 1;
    }

    return low;
  }

  private static boolean works(int[] stones, int maxLen) {
    int n = stones.length;
    boolean[] visited = new boolean[n];

    int curIdx = 0;

    while (curIdx < n-1) {
      int old = curIdx;
      int max = stones[curIdx] + maxLen;

      while (curIdx+1 < n && stones[curIdx+1] <= max) {
        curIdx++;
      }

      if (curIdx == old) {
        return false;
      }

      max = curIdx;
      visited[curIdx] = true;
    }

    while (curIdx > 0) {
      int old = curIdx;

      while (curIdx >= 0 && visited[curIdx]) {
        curIdx--;
      }

      if (stones[old] - stones[curIdx] > maxLen) {
        return false;
      }

      visited[curIdx] = true;
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