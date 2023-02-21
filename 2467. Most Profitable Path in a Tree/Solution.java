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
  static int bob;
  static int result = Integer.MIN_VALUE;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    N = nextInt();
    bob = nextInt();
    
    // solve
    int[][] edges = new int[N-1][2];
    for (int i = 0; i < N-1; i++) {
      edges[i][0] = nextInt();
      edges[i][1] = nextInt();
    }
    int[] amount = new int[N];
    for (int i = 0; i < N; i++) {
      amount[i] = nextInt();
    }

    pw.println(mostProfitablePath(edges, bob, amount));

    br.close();
    pw.close();
  }

  private static int mostProfitablePath(int[][] edges, int bob, int[] amount) {
    int n = amount.length;

    Node[] nodes = new Node[n];

    for (int i = 0; i < n; i++) {
      nodes[i] = new Node(i, amount[i]);
    }

    for (int i = 0; i < n-1; i++) {
      nodes[edges[i][0]].nbs.add(nodes[edges[i][1]]);
      nodes[edges[i][1]].nbs.add(nodes[edges[i][0]]);
    }

    // assign parent
    p(nodes[0]);

    int count = 0;
    Node cur = nodes[bob];

    while (cur.idx != 0) {
      cur = cur.parent;
      count++;
    }

    cur = nodes[bob];      
    for (int i = 0; i < count/2; i++) {
      cur.value=0;
      cur = cur.parent;  
    }

    if (count % 2 == 0) {
      // going to meet
      cur.value /= 2;
    } else {
      cur.value = 0;
    }

    getResult(nodes[0], 0);

    return result;
  }

  private static void getResult(Node node, int cur) {
    if (node.parent != null && node.nbs.size() == 1) {
      // leaf
      result = Math.max(result, cur + node.value);
      return;
    }

    for (Node nb : node.nbs) {
      if (nb != node.parent) {
        getResult(nb, cur + node.value);
      }
    }
  }

  private static void p(Node parent) {
    for (Node nb : parent.nbs) {
      if (nb == parent.parent) continue;
      nb.parent = parent;
      p(nb);
    }
  }

  private static class Node {
    int idx;
    int value;
    Node parent;
    List<Node> nbs = new ArrayList<>();

    public Node(int idx, int value) {
      this.idx = idx;
      this.value = value;
    }
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