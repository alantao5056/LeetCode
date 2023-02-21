import java.io.PrintWriter;
import java.io.File;
import java.util.*;

public class Main {
  static int N;

  public static void main(String[] args) throws Exception {
    // read input
    Scanner sc = new Scanner(new File("1.in"));
    N = sc.nextInt();

    int[] nums = new int[N];
    for (int i = 0; i < N; i++) {
      nums[i] = sc.nextInt();
    }
    
    // solve
    int[] result = productExceptSelf(nums);
    for (int i = 0; i < N; i++) {
      System.out.println(result[i]);
    }

    sc.close();
  }

  private static int[] productExceptSelf(int[] nums) {
    int total = 1;
    int zeroCount = 0;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] == 0) {
        zeroCount++;
      } else {
        total *= nums[i];
      }
    }

    if (zeroCount >= 2) {
      return new int[nums.length];
    } else if (zeroCount == 1) {
      int[] result = new int[nums.length];
      for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
          result[i] = total;
        }
      }
      return result;
    }

    int[] result = new int[nums.length];
    for (int i = 0; i < nums.length; i++) {
      result[i] = total / nums[i];
    }

    return result;
  }
}