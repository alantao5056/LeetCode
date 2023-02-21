import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
  static StreamTokenizer st;
  static int n;
  static int N;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    n = nextInt();
    N = nextInt();
    
    // solve
    int[] batteries = new int[N];
    for (int i = 0; i < N; i++) {
      batteries[i] = nextInt();
    }

    pw.println(maxRunTime(n, batteries));

    br.close();
    pw.close();
  }

  private static long maxRunTime(int n, int[] batteries) {
    long low = 0;
    long high = 100000000000000L;
    
    while (low < high) { // notice we do not compare element at mid with our target
      long mid = low + (high - low + 1) / 2;
      if (check(n, batteries, mid))
        low = mid;
      else
        high = mid - 1;
    }
    return low;
  }

  private static boolean check(int n, int[] batteries, long mid) {
    long total = 0;
    for (int i = 0; i < batteries.length; i++) {
      if (batteries[i] > mid) {
        total += mid;
      } else {
        total += batteries[i];
      }
    }

    return total / n >= mid;
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