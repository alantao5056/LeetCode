public class Merge {

  public static void main(String[] args) {
    ListNode[] list = new ListNode[3];

    ListNode one = new ListNode(1);
    one.next = new ListNode(4);
    one.next.next = new ListNode(5);
    list[0] = one;

    ListNode two = new ListNode(1);
    two.next = new ListNode(3);
    two.next.next = new ListNode(4);
    list[1] = two;

    ListNode three = new ListNode(2);
    three.next = new ListNode(6);
    list[2] = three;

    mergeKLists(list);
  }

  public static ListNode mergeKLists(ListNode[] lists) {
    ListNode result = new ListNode();
    ListNode cur = result;
    while (true) {
      int min = Integer.MAX_VALUE;
      int minIdx = -1;
      for (int i = 0; i < lists.length; i++) {
        if (lists[i] != null) {
          if (lists[i].val < min) {
            min = lists[i].val;
            minIdx = i;
          }
        }
      }

      if (minIdx == -1) {
        break;
      }

      cur.next = new ListNode();
      cur = cur.next;
      cur.val = min;

      if (lists[minIdx].next == null) {
        lists[minIdx] = null;
      } else {
        lists[minIdx] = lists[minIdx].next;
      }
    }

    return result.next;
  }

  private static class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
}