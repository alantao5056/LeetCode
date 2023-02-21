import java.util.*;
import java.io.PrintWriter;

public class Main {
  static int N;
  static int[] prefix;

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner(new java.io.File("1.in"));
    PrintWriter pw = new PrintWriter("1.out");
    // Scanner sc = new Scanner(System.in);

    N = sc.nextInt();
    int target = sc.nextInt();
    int[] arr = new int[N];
    prefix = new int[N];
    int cur = 0;

    for (int i = 0; i < N; i++) {
      arr[i] = sc.nextInt();
      cur += arr[i];
      prefix[i] = cur;
    }

    pw.println(minSubArrayLen(target, arr));

    pw.close();
    sc.close();
  }

  private static int minSubArrayLen(int target, int[] nums) {
    int l = 1, r = nums.length - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
            
      if (!check(target, m, nums)) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    if (check(target, l, nums)) {
      return l;
    } else if (r!=0 && check(target, r, nums)) {
      return r;
    }
    return 0;
  }

  private static boolean check(int target, int minSize, int[] nums) {
    int cur = prefix[minSize-1];
    int startIdx = 0;
    int endIdx = minSize-1;
    int length = nums.length;

    while (true) {
      if (cur >= target) {
        return true;
      }

      cur -= nums[startIdx];
      startIdx++;
      endIdx++;
      if (endIdx == length) {
        break;
      }
      cur += nums[endIdx];
    }

    return false;
  }
}
