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
    int[] arr = new int[N];
    for (int i = 0; i < N; i++) {
      arr[i] = nextInt();
    }

    pw.println(firstMissingPositive(arr));

    br.close();
    pw.close();
  }

  private static int firstMissingPositive(int[] nums) {
    boolean[] visited = new boolean[100002];

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] <= 100000 && nums[i] >= 0) {
        visited[nums[i]] = true;
      }
    }

    for (int i = 1; i <= 100001; i++) {
      if (!visited[i]) {
        return i;
      }
    }
    return 0;
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