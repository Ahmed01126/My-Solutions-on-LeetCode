/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
        public ListNode[] splitListToParts(ListNode head, int k) {
            List<ListNode> list = new ArrayList<>();
            while (head != null) {
                list.add(head);
                head = head.next;
            }
            ListNode[] res = new ListNode[k];
            int sizeOfMostParts = list.size() / k;
            if (list.size() >= k) {
                int reminder = list.size() % k;
                res[0] = list.get(0);
                list.clear();
                for (int l = 0; l < k; l++) {
                    int x = sizeOfMostParts - 1;
                    x+=(reminder-- > 0)? 1:0;
                    ListNode node = res[l];
                    while (x > 0) {
                        x--;
                        node = node.next;
                    }
                    if (l + 1 < k) {res[l + 1] = node.next;
                    node.next = null;
                                   }
                }
            } else {
                for (int i = 0; i < list.size(); i++) {
                    res[i] = list.get(i);
                    res[i].next = null;
                }
            }
            return res;
        }
}