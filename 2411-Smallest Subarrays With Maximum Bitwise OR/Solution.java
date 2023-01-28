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

    int[] result = smallestSubarrays(nums);
    for (int i = 0; i < N; i++) {
      pw.println(result[i]); 
    }

    br.close();
    pw.close();
  }

  private static int[] smallestSubarrays(int[] nums) {
    int n = nums.length;
    int[][] prefix = new int[n+1][31];

    for (int i = 0; i < n; i++) {
      String binary = Integer.toString(nums[i], 2);

      for (int j = 30; j >= 0; j--) {
        prefix[i+1][j] = prefix[i][j] + ((binary.length()-31+j) >= 0 ? (binary.charAt(binary.length()-31+j) == '1' ? 1 : 0) : 0);
      }
    }
    int[] result = new int[n];
    for (int i = 0; i < n; i++) {
      boolean[] init = new boolean[31];

      for (int j = 0; j < 31; j++) {
        init[j] = (prefix[n][j]-prefix[i][j]) > 0;
      }

      // binary search
      int low = i;
      int high = n - 1;
      
      while (low < high) { // notice we do not compare element at mid with our target
        int mid = low + (high - low) / 2;
        if (works(i, mid, prefix, init))
          high = mid;
        else
          low = mid + 1;
      }
      result[i] = low-i+1;
    }

    return result;
  }

  private static boolean works(int start, int end, int[][] prefix, boolean[] init) {
    for (int i = 0; i < 31; i++) {
      if (((prefix[end+1][i] - prefix[start][i]) == 0) && init[i]) {
        return false;
      }
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