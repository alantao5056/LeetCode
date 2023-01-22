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
    int[] nums = new int[N];
    int[] cost = new int[N];

    for (int i = 0; i < N; i++) {
      nums[i] = nextInt();
    }

    for (int i = 0; i < N; i++) {
      cost[i] = nextInt();
    }

    pw.println(minCost(nums, cost));

    br.close();
    pw.close();
  }

  private static long minCost(int[] nums, int[] cost) {
    int n = nums.length;
    int[][] numCost = new int[nums.length][2];
    for (int i = 0; i < n; i++) {
      numCost[i][0] = nums[i];
      numCost[i][1] = cost[i];
    }
    Arrays.sort(numCost, (int[] a, int[] b) -> a[0]-b[0]);
    long[] prefix = new long[n+1];
    long cur = 0;
    for (int i = 1; i <= n; i++) {
      prefix[i] = prefix[i-1] + numCost[i-1][1];
      cur += (long) numCost[i-1][1] * numCost[i-1][0];
    }

    long result = cur;
    long prev = 0;

    for (int i = 0; i < n; i++) {
      // turn everything into numCost[i][0]
      long difference = numCost[i][0] - prev;
      cur -= (prefix[n]-prefix[i]) * difference;
      cur += prefix[i] * difference;
      result = Math.min(result, cur);
      prev = numCost[i][0];
    }

    return result;
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