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

    int[] result = secondGreaterElement(nums);

    for (int r : result) {
      pw.println(r);
    }

    br.close();
    pw.close();
  }

  private static int[] secondGreaterElement(int[] nums) {
    TreeMap<Integer, List<Integer>> tm1 = new TreeMap<>();
    TreeMap<Integer, List<Integer>> tm2 = new TreeMap<>();

    int[] result = new int[nums.length];
    Arrays.fill(result, -1);

    for (int n = 0; n < nums.length; n++) {
      // do tm2
      while (!tm2.isEmpty() && tm2.firstEntry().getKey() < nums[n]) {
        List<Integer> values = tm2.pollFirstEntry().getValue();
        for (int v : values) {
          result[v] = nums[n];
        }
      }

      // do tm1
      while (!tm1.isEmpty() && tm1.firstEntry().getKey() < nums[n]) {
        var entry = tm1.pollFirstEntry();
        Integer key = entry.getKey();
        List<Integer> values = entry.getValue();
        if (!tm2.containsKey(key)) {
          tm2.put(key, new ArrayList<>());
        }
        List<Integer> l = tm2.get(key);
        for (int v : values) {
          l.add(v);
        }
      }

      // add to tm1
      if (!tm1.containsKey(nums[n])) {
        tm1.put(nums[n], new ArrayList<>());
      }
      tm1.get(nums[n]).add(n);
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