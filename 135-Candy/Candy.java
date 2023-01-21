import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Candy {
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
    int[] ratings = new int[N];
    for (int i = 0; i< N; i++) {
      ratings[i] = nextInt();
    }

    pw.println(candy(ratings));

    br.close();
    pw.close();
  }

  private static int candy(int[] ratings) {
    int[] left = new int[ratings.length];
    left[0] = 1;
    for (int i = 1; i < ratings.length; i++) {
      if (ratings[i] > ratings[i-1]) {
        left[i] = left[i-1] + 1;
      } else {
        left[i] = 1;
      }
    }

    int[] right = new int[ratings.length];
    right[ratings.length-1] = 1;
    int count = Math.max(1, left[ratings.length-1]);
    for (int i = ratings.length-2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1]) {
        right[i] = right[i+1] + 1;
      } else {
        right[i] = 1;
      }

      count += Math.max(left[i], right[i]);
    }
    return count;
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