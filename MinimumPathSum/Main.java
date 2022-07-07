import java.io.PrintWriter;
import java.io.File;
import java.util.*;

public class Main {
  static int N;
  static int M;

  public static void main(String[] args) throws Exception {
    // read input
    Scanner sc = new Scanner(new File("1.in"));
    N = sc.nextInt();
    M = sc.nextInt();
    
    // solve
    int[][] grid = new int[N][M];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        grid[i][j] = sc.nextInt();
      }
    }

    System.out.println(minPathToSum(grid));

    sc.close();
  }

  private static int minPathToSum(int[][] grid) {
    int n = grid.length;
    int m = grid[0].length;

    int[][] values = new int[n][m];

    // do the last layer
    values[n-1][m-1] = grid[n-1][m-1];
    for (int i = m-2; i >= 0; i--) {
      values[n-1][i] = values[n-1][i+1] + grid[n-1][i];
    }
    for (int i = n-2; i >= 0; i--) {
      values[i][m-1] = values[i+1][m-1] + grid[i][m-1];
    }

    // do the rest
    int i = n-2;
    int j = m-2;

    while (i > -1 && j > -1) {
      values[i][j] = grid[i][j] + Math.min(values[i+1][j], values[i][j+1]);
      for (int k = i-1; k >= 0; k--) {
        values[k][j] = grid[k][j] + Math.min(values[k+1][j], values[k][j+1]);
      }
      for (int k = j-1; k >= 0; k--) {
        values[i][k] = grid[i][k] + Math.min(values[i+1][k], values[i][k+1]);
      }
      i--;
      j--;
    }

    return values[0][0];
  }
}