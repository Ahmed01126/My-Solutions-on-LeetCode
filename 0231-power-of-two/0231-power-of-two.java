class Solution {
    public boolean isPowerOfTwo(int n) {
        byte cnt = 0;
        while (n > 0) {
            if ((n & 1) == 1) {
                cnt++;
            }
            n >>= 1;
        }
        return cnt == 1;
    }
}