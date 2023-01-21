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
    for (int i = 0; i < N; i++) {
      nums[i] = nextInt();
    }

    pw.println(canJump(nums));

    br.close();
    pw.close();
  }

  private static boolean canJump(int[] nums) {
    return recursive(nums, new boolean[nums.length], 0);
  }

  private static boolean recursive(int[] nums, boolean[] visited, int cur) {
    if (cur == nums.length-1) return true;
    if (visited[cur]) return false;
    for (int i = cur+1; i <= Math.min(nums.length-1, cur+nums[cur]); i++) {
      if (recursive(nums, visited, i)) {
        return true;
      }
      visited[i] = true;
    }
    return false;
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