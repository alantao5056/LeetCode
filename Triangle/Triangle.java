import java.util.*;
import java.io.PrintWriter;

public class Triangle {
  static int N;
  static int minTotal = Integer.MAX_VALUE;

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("1.in"));
    PrintWriter pw = new PrintWriter("1.out");
    // Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    
    List<List<Integer>> triangle = new ArrayList<>();

    for (int i = 0; i < N; i++) {
      triangle.add(new ArrayList<>());
      for (int j = 0; j < i+1; j++) {
        triangle.get(i).add(sc.nextInt());
      }
    }

    pw.println(minimumTotal(triangle));

    pw.close();
    sc.close();
  }

  public static int minimumTotal(List<List<Integer>> triangle) {
    // brute force
    recursive(triangle, 0, 0, 0);
    return minTotal;
  }

  public static void recursive(List<List<Integer>> triangle, int curI, int curJ, int count) {
    count += triangle.get(curI).get(curJ);

    if (curI == N-1) {
      // end
      minTotal = Math.min(minTotal, count);
    } else {
      recursive(triangle, curI+1, curJ, count);
      recursive(triangle, curI+1, curJ+1, count);
    }
  }
}
