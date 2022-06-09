import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Soduku {
  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("soduku.in"));
    PrintWriter pw = new PrintWriter("soduku.out");

    Cell[][] grid = new Cell[9][9];

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char c = sc.next().charAt(0);
        grid[i][j] = new Cell(c=='.' ? -1 : c-'0'-1, i, j);
      }
    }

    char[][] result = solveSodoku(grid);
    for (int i = 0; i < 9; i++) {
      StringBuilder sb = new StringBuilder();
      for (int j = 0; j < 9; j++) {
        sb.append(result[i][j]);
      }

      pw.println(sb);
    }

    pw.close();
    sc.close();
  }

  public static char[][] solveSodoku(Cell[][] grid) {
    int visitedCount = 0;
    while (visitedCount != 81) {
      // fill in possible for grid
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (grid[i][j].value == -1 || grid[i][j].visited) continue;

          // update row & column
          updateRowAndColumn(grid[i][j], grid);

          // update quadrant
          updateQuadrant(grid[i][j], grid);
          grid[i][j].visited = true;
          visitedCount++;
        }
      }
      // fill in what we know
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (grid[i][j].value != -1) continue;
          boolean possible = false;
          int possibleValue = 0;
          boolean flag = false;
          for (int k = 0; k < 9; k++) {
            if (grid[i][j].possible[k]) {
              if (!possible) {
                possible = true;
                possibleValue = k;
              } else {
                // not possible
                flag = true;
                break;
              }
            }
          }

          if (flag) continue;
          grid[i][j].value = possibleValue;
        }
      }
    }
    char[][] result = new char[9][9];

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        result[i][j] = Integer.toString(grid[i][j].value+1).charAt(0);
      }
    }
    return result;
  }

  private static void updateRowAndColumn(Cell c, Cell[][] grid) {
    // row
    int x = c.x;
    int y = c.y;
    int value = c.value;

    for (int i = 0; i < 9; i++) {
      grid[x][i].possible[value] = false;
      grid[i][y].possible[value] = false;
    }
  }

  private static void updateQuadrant(Cell c, Cell[][] grid) {
    int x = c.x;
    int y = c.y;
    int value = c.value;

    if (x < 3) {
      if (y < 3) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else if (y > 5) {
        for (int i = 0; i < 3; i++) {
          for (int j = 6; j < 9; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else {
        for (int i = 0; i < 3; i++) {
          for (int j = 3; j < 6; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      }
    } else if (x > 2 && x < 6) {
      if (y < 3) {
        for (int i = 3; i < 6; i++) {
          for (int j = 0; j < 3; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else if (y > 5) {
        for (int i = 3; i < 6; i++) {
          for (int j = 6; j < 9; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else {
        for (int i = 3; i < 6; i++) {
          for (int j = 3; j < 6; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      }
    } else {
      if (y < 3) {
        for (int i = 6; i < 9; i++) {
          for (int j = 0; j < 3; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else if (y > 5) {
        for (int i = 6; i < 9; i++) {
          for (int j = 6; j < 9; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      } else {
        for (int i = 6; i < 9; i++) {
          for (int j = 3; j < 6; j++) {
            grid[i][j].possible[value] = false;
          }
        }
      }
    }
  }

  public static class Cell {
    int value;
    int x;
    int y;
    boolean[] possible = new boolean[9];
    boolean visited = false;
    public Cell (int value, int x, int y) {
      this.value = value;
      this.x = x;
      this.y = y;
      Arrays.fill(possible, true);
    }
    @Override
    public String toString() {
      return Integer.toString(value);
    }
  }
}