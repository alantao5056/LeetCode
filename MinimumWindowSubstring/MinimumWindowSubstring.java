import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.ObjectInputStream.GetField;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class MinimumWindowSubstring {
  static StreamTokenizer st;
  static int[] S;
  static Map<Integer, Integer> T = new HashMap<>();
  static int N;
  static int M;
  static int s;
  static int e;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("minimumwindowsubstring.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("minimumwindowsubstring.out"));
    char[] str = nextString().toCharArray();
    N = str.length;
    S = new int[N];
    for (int i = 0; i < N; i++) {
      S[i] = str[i] - 'A';
    }

    str = nextString().toCharArray();
    
    M = str.length;
    for (int i = 0; i < M; i++) {
      int key = str[i] - 'A';
      if (!T.containsKey(key)) {
        T.put(key, 1);
      } else {
        T.put(key, T.get(key)+1);
      }
    }

    // solve
    int low = M;
    int high = N - 1;
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low) / 2;
      valid(mid);
      if (s != -1)
        high = mid;
      else
        low = mid + 1;
    }

    valid(low);
    if (s==-1) {
      pw.println("");
    } else {
      StringBuilder sb = new StringBuilder();
      for (int i = s; i <= e; i++) {
        sb.append((char) (65+S[i]));
      }
      pw.println(sb.toString());
    }

    br.close();
    pw.close();
  }

  private static void valid(int length) {
    Map<Integer, Integer> m = new HashMap<>();
    int count = 0;
    for (int i = 0; i < length; i++) {
      if (T.containsKey(S[i])) {
        if (!m.containsKey(S[i])) {
          m.put(S[i], 1);
        } else {
          m.put(S[i], m.get(S[i])+1);
        }

        // might be equal or more
        if (m.get(S[i]) == T.get(S[i])) {
          count++;
        }
      }
    }

    int start = 0;
    int end = length-1;
    while (count < M && end != N-1) {
      if (T.containsKey(S[start])) {
        m.put(S[start], m.get(S[start]) - 1);
        if (m.get(S[start]) == T.get(S[start]) - 1) {
          count--;
        }
      }
      if (T.containsKey(S[end+1])) {
        if (!m.containsKey(S[end+1])) {
          m.put(S[end+1], 1);
        } else {
          m.put(S[end+1], m.get(S[end+1]) + 1);
        }
        if (m.get(S[end+1]) == T.get(S[end+1])) {
          count++;
        }
      }

      start++;
      end++;
    }

    if (count < M) {
      s=-1;
      return;
    }
    s=start;
    e=end;
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