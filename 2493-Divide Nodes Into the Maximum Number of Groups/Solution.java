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
  static int M;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    N = nextInt();
    M = nextInt();
    
    // solve
    int[][] edges = new int[M][2];
    for (int j = 0; j < M; j++) {
      edges[j][0] = nextInt();
      edges[j][1] = nextInt();
    }

    pw.println(magnificentSets(N, edges));

    br.close();
    pw.close();
  }

  private static int magnificentSets(int n, int[][] edges) {
    Node[] nodes = new Node[n];

    for (int i = 0; i < n; i++) {
      nodes[i] = new Node();
    }

    for (int i = 0; i < edges.length; i++) {
      nodes[edges[i][0]-1].nbs.add(nodes[edges[i][1]-1]);
      nodes[edges[i][1]-1].nbs.add(nodes[edges[i][0]-1]);
    }

    // try starting with every node
    int result = 0;
    for (int i = 0; i < n; i++) {
      if (nodes[i].visited) continue;
      // check cur group
      ArrayDeque<Node> q_ = new ArrayDeque<>();
      q_.add(nodes[i]);
      nodes[i].visited = true;
      List<Node> group = new ArrayList<>();
      while (!q_.isEmpty()) {
        Node cur = q_.poll();
        group.add(cur);

        for (Node nb : cur.nbs) {
          if (!nb.visited) {
            q_.add(nb);
            nb.visited = true;
          }
        }
      }

      int maxNum = 0;
      boolean works2 = false;
      for (Node start : group) {
        int num = 1;
        ArrayDeque<Node> q = new ArrayDeque<>();
        q.add(start);
        start.groupNum = 1;

        boolean works = true;
        while (!q.isEmpty()) {
          Node cur = q.poll();

          for (Node nb : cur.nbs) {
            if (nb.groupNum == 0) {
              nb.groupNum = cur.groupNum+1;
              num = cur.groupNum+1;
              q.add(nb);
            }
          }

          for (Node nb : cur.nbs) {
            if (nb.groupNum != 0 && Math.abs(cur.groupNum-nb.groupNum) != 1) {
              works = false;
              break;
            }
          }
        }

        if (works) {
          maxNum = Math.max(maxNum, num);
          works2 = true;
        }

        // reset
        for (Node start_ : group) {
          start_.groupNum = 0;
        }
      }
      if (!works2) return -1;
      result += maxNum;
    }

    return result > 0 ? result : -1;
  }

  private static class Node {
    List<Node> nbs = new ArrayList<>();
    int groupNum = 0;
    boolean visited = false;
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