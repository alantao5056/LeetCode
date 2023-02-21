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
  static int time;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    N = nextInt();
    time = nextInt();
    
    // solve
    int[][] clips = new int[N][2];
    for (int i = 0; i < N; i++) {
      clips[i][0] = nextInt();
      clips[i][1] = nextInt();
    }

    pw.println(videoStitching(clips, time));

    br.close();
    pw.close();
  }

  private static int videoStitching(int[][] clips, int time) {
    Arrays.sort(clips, (int[] a, int[] b) -> a[0]-b[0]);

    int cur = 0;
    int curEnd = 0;
    int count = 0;
    while (cur < clips.length && curEnd < time) {
      int i = cur;
      int maxEnd = curEnd;
      while (i < clips.length && clips[i][0] <= curEnd) {
        maxEnd = Math.max(maxEnd, clips[i][1]);
        i++;
      }

      if (maxEnd == curEnd) return -1;
      curEnd = maxEnd;
      cur = i;
      count++;
    }

    if (curEnd >= time) {
      return count;
    }
    return -1;
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