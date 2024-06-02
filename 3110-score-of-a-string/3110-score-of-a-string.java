import static java.lang.Math.abs;
class Solution {
    public int scoreOfString(String s) {
        int sum = 0;
        for (int i = 1; i < s.length(); i++) {
            sum += abs(s.charAt(i) - s.charAt(i-1));
        }
        return sum;
    }
}