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
    int[] nums = new int[N];

    for (int i = 0; i < N; i++) {
      nums[i] = nextInt();
    }

    int[] result = secondGreaterElement(nums);

    for (int r : result) {
      pw.println(r);
    }

    br.close();
    pw.close();
  }

  private static int[] secondGreaterElement(int[] nums) {
    Stack<Integer> s1 = new Stack<>();
    Stack<Integer> s2 = new Stack<>();

    int[] result = new int[nums.length];
    Arrays.fill(result, -1);

    for (int i = 0; i < nums.length; i++) {
      // do s2
      while (!s2.isEmpty() && nums[s2.peek()] < nums[i]) {
        result[s2.pop()] = nums[i];
      }

      // do s1
      List<Integer> l = new ArrayList<>();
      while (!s1.isEmpty() && nums[s1.peek()] < nums[i]) {
        l.add(s1.pop());
      }

      s1.add(i);

      for (int j = l.size()-1; j >= 0; j--) {
        s2.add(l.get(j));
      }
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