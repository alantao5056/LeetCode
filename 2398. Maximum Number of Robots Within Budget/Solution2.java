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
    long budget = nextLong();
    
    // solve
    int[] chargeTimes = new int[N];
    int[] runningCosts = new int[N];
    for (int i = 0; i < N; i++) {
      chargeTimes[i] = nextInt();
    }

    for (int i = 0; i < N; i++) {
      runningCosts[i] = nextInt();
    }

    pw.println(maximumRobots(chargeTimes, runningCosts, budget));

    br.close();
    pw.close();
  }

  private static int maximumRobots(int[] chargeTimes, int[] runningCosts, long budget) {
    int n = chargeTimes.length;
    Robot[] robots = new Robot[n];

    for (int i = 0; i < n; i++) {
      Robot cur = new Robot(chargeTimes[i], runningCosts[i]);
      robots[i] = cur;
    }

    int low = 0;
    int high = n;
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low + 1) / 2;
      if (works(robots, mid, budget))
        low = mid;
      else
        high = mid - 1;
    }

    return low;
  }

  private static boolean works(Robot[] robots, int len, long budget) {
    if (len == 0) return true;
    int n = robots.length;
    long cur = 0;
    ArrayDeque<Integer> dq = new ArrayDeque<>();
    for (int i = 0; i < len; i++) {
      while (!dq.isEmpty() && robots[dq.peekLast()].charge <= robots[i].charge) {
        dq.poll();
      }
      dq.add(i);
      cur += (long) len * robots[i].running;
    }

    if (cur + robots[dq.peekFirst()].charge <= budget) return true;

    for (int i = len; i < n; i++) {
      cur += (long) len * robots[i].running;
      while (!dq.isEmpty() && robots[dq.peekLast()].charge <= robots[i].charge) {
        dq.poll();
      }
      dq.add(i);

      cur -= (long) len * robots[i-len].running;
      while (!dq.isEmpty() && dq.peekFirst() < i-len) {
        dq.pop();
      }

      if (cur + robots[dq.peekFirst()].charge <= budget) return true;
    }

    return false;
  }

  private static class Robot{
    int charge;
    int running;
    public Robot(int charge, int running) {
      this.charge = charge;
      this.running = running;
    }
  }

  private static long nextLong() throws Exception {
    st.nextToken();
    return (long) st.nval;
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