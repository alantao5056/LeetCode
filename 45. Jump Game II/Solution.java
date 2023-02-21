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
  static int min = Integer.MAX_VALUE;

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

    pw.println(jump(nums));

    br.close();
    pw.close();
  }

  private static int jump(int[] nums) {
    int count = 0;
    int start = 0;
    int end = 0;
    while (end < nums.length-1) {
      int newEnd = end;
      for (int i = start; i <= end; i++) {
        newEnd = Math.max(newEnd, i+nums[i]);
      }
      start = end+1;
      end = newEnd;
      count++;
    }
    return count;
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