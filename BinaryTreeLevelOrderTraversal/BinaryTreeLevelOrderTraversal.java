import java.io.PrintWriter;
import java.io.File;
import java.util.*;

public class BinaryTreeLevelOrderTraversal {
  static int N;

  public static void main(String[] args) throws Exception {
    // read input
    Scanner sc = new Scanner(new File("1.in"));
    // PrintWriter pw = new PrintWriter("1.out");
    N = sc.nextInt();
    
    // solve
    int cur = 1;
    TreeNode root = new TreeNode(sc.nextInt());
    List<TreeNode> curTreeNodes = new ArrayList<>();
    curTreeNodes.add(root);
    for (int i = 2; i <= N; i++) {
      List<TreeNode> newTreeNodes = new ArrayList<>();
      for (int j = 0; j < cur; j++) {
        int left = sc.nextInt();
        int right = sc.nextInt();
        if (left == -1 || curTreeNodes.get(j) == null) {
          newTreeNodes.add(null);
          continue;
        }
        TreeNode leftNode = new TreeNode(left);
        TreeNode rightNode = new TreeNode(right);
        
        curTreeNodes.get(j).left = leftNode;
        curTreeNodes.get(j).right = rightNode;
        newTreeNodes.add(leftNode);
        newTreeNodes.add(rightNode);
      }
      curTreeNodes = new ArrayList<>(newTreeNodes);
      cur *= 2;
    }

    sc.close();
    // pw.close();
  }

  public static class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
    @Override
    public String toString() {
      return Integer.toString(val);
    }
  }
}