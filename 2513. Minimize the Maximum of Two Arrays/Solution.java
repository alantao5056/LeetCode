import java.io.PrintWriter;
import java.io.StreamTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
  static StreamTokenizer st;

  public static void main(String[] args) throws Exception {
    // read input
    BufferedReader br = new BufferedReader(new FileReader("1.in"));
    // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    st = new StreamTokenizer(br);
    PrintWriter pw = new PrintWriter(new File("1.out"));
    // PrintWriter pw = new PrintWriter(System.out);
    
    // solve
    int divisor1 = nextInt();
    int divisor2 = nextInt();
    int uniqueCnt1 = nextInt();
    int uniqueCnt2 = nextInt();

    pw.println(minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2));

    br.close();
    pw.close();
  }

  public static int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    // binary search
    int low = 1;
    int high = Integer.MAX_VALUE;
    
    while (low < high) { // notice we do not compare element at mid with our target
      int mid = low + (high - low) / 2;
      if (works(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2))
        high = mid;
      else
        low = mid + 1;
    }
    return low;
  }

  public static boolean works(int max, int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
    int noUnique = max/lcm(divisor1, divisor2);
    int unique = max - max / divisor1 - max/divisor2 + noUnique;
    int count1 = max/divisor1;
    int count2 = max/divisor2;

    if (count2 + unique-noUnique < uniqueCnt1) {
      return false;
    }

    unique -= Math.max(0, uniqueCnt1 - (count2-noUnique));

    return count1 + unique-noUnique >= uniqueCnt2;
  }

  public static int lcm(int number1, int number2) {
    if (number1 == 0 || number2 == 0) {
        return 0;
    }
    int absNumber1 = Math.abs(number1);
    int absNumber2 = Math.abs(number2);
    int absHigherNumber = Math.max(absNumber1, absNumber2);
    int absLowerNumber = Math.min(absNumber1, absNumber2);
    int lcm = absHigherNumber;
    while (lcm % absLowerNumber != 0) {
        lcm += absHigherNumber;
    }
    return lcm;
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