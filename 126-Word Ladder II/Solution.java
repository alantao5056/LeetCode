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
  static List<List<Integer>> result = new ArrayList<>();
  static int minLen = Integer.MAX_VALUE;
  static int startIdx;
  static int endIdx;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    String beginWord = nextString();
    String endWord = nextString();

    N = nextInt();
    
    List<String> wordList = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      wordList.add(nextString());
    }

    // solve
    
    List<List<String>> result = findLadders(beginWord, endWord, wordList);

    for (int i = 0; i < result.size(); i++) {
      pw.println(result.get(i).size());

      for (String r : result.get(i)) {
        pw.println(r);
      }

      pw.println();
    }

    br.close();
    pw.close();
  }

  private static List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    boolean found = false;
    boolean found2 = false;

    for (int i = 0; i < wordList.size(); i++) {
      if (wordList.get(i).equals(endWord)) {
        found = true;
        endIdx = i;
      }
      if (wordList.get(i).equals(beginWord)) {
        found2 = true;
        startIdx = i;
      }
    }

    if (!found) return new ArrayList<>();

    if (!found2) {
      wordList.add(beginWord);
      startIdx = wordList.size()-1;
    }

    List<Integer>[] next = new ArrayList[wordList.size()];
    for (int i = 0; i < wordList.size(); i++) {
      next[i] = new ArrayList<>();
    }

    for (int i = 0; i < wordList.size(); i++) {
      for (int j = i+1; j < wordList.size(); j++) {
        if (works(wordList.get(i), wordList.get(j))) {
          next[i].add(j);
          next[j].add(i);
        }
      }
    }

    boolean[] visited = new boolean[wordList.size()];
    visited[startIdx] = true;
    List<Integer> path = new ArrayList<>();
    path.add(startIdx);
    recursive(next, startIdx, visited, path);
    
    List<List<String>> result_ = new ArrayList<>();
    for (var l : result) {
      List<String> cur = new ArrayList<>();
      result_.add(cur);
      for (int r : l) {
        cur.add(wordList.get(r));
      }
    }
    return result_;
  }
  
  private static void recursive(List<Integer>[] next, int cur, boolean[] visited, List<Integer> path) {
    if (cur == endIdx) {
      if (path.size() < minLen) {
        result = new ArrayList<>();
        result.add(path);
        minLen = path.size();
      } else if (path.size() == minLen) {
        result.add(path);
      }
      return;
    }
    for (int n : next[cur]) {
      if (!visited[n]) {
        boolean[] visited_ = new boolean[next.length];
        for (int i = 0; i < next.length; i++) {
          visited_[i] = visited[i];
        }
        visited_[n] = true;

        List<Integer> path_ = new ArrayList<>();
        for (int p : path) {
          path_.add(p);
        }
        path_.add(n);

        recursive(next, n, visited_, path_);
      }
    }
  }

  private static boolean works(String a, String b) {
    boolean flag = false;
    for (int i = 0; i < a.length(); i++) {
      if (a.charAt(i) != b.charAt(i)) {
        if (flag) {
          return false;
        }
        flag = true;
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