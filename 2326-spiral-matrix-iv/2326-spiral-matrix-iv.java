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
    public int[][] spiralMatrix(int n, int m, ListNode head) {
            int[][] res = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    res[i][j] = -1;
                }
            }
            List<Integer> list = new ArrayList<>();
            int ii = 0;
            while (head != null) {
                list.add(head.val);
                if (n == 1) res[0][ii++] = head.val;
                else if (m == 1) res[ii++][0] = head.val;
                head = head.next;
            }
            if (n == 1 || m == 1) return res;
            int startRow = 0, startCol = 0, endRow = n - 1, endCol = m - 1;
            int row = 0, col = 0;
            int transitionRow = 0, transitionCol = 0;
            for (int i = 0; i < list.size(); i++) {
                row += transitionRow;
                col += transitionCol;
                if (res[row][col] != -1) {
                    row++;
                    col++;
                    startRow++;
                    startCol++;
                    endRow--;
                    endCol--;
                }
                res[row][col] = list.get(i);
                if (col == endCol && row == startRow) {
                    transitionRow = 1;
                    transitionCol = 0;
                } else if (row == endRow && col == endCol) {
                    transitionRow = 0;
                    transitionCol = -1;
                } else if (col == startCol && row == endRow) {
                    transitionRow = -1;
                    transitionCol = 0;
                } else if (row == startRow && col == startCol) {
                    transitionRow = 0;
                    transitionCol = 1;
                }
            }
            return res;
        }
}