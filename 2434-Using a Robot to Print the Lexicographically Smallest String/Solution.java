import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
  static StreamTokenizer st;
  static String s_;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    s_ = nextString();
    
    // solve
    pw.println(robotWithString(s_));

    br.close();
    pw.close();
  }

  private static String robotWithString(String s) {
    int n = s.length();
    char[] c = s.toCharArray();
    char[] prefix = new char[n];
    char cur = '{';
    for (int i = n-1; i >= 0; i--) {
      prefix[i] = c[i] < cur ? c[i] : cur;
      cur = prefix[i];
    }


    Stack<Character> stack = new Stack<>();
    int idx = 0;
    StringBuilder sb = new StringBuilder();
    while (idx < n) {
      if (!stack.isEmpty() && stack.peek() <= prefix[idx]) {
        sb.append(stack.pop());
      } else {
        while (c[idx] != prefix[idx]) {
          stack.add(c[idx]);
          idx++;
        }
        sb.append(c[idx]);
        idx++;
      }
    }

    while (!stack.isEmpty()) {
      sb.append(stack.pop());
    }

    return sb.toString();
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