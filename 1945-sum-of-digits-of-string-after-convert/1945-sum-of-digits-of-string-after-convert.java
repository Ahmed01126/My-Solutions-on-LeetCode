class Solution {
    public int getLucky(String s, int k) {
        StringBuilder newS = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            newS.append(s.charAt(i) - 'a' + 1);
        }
        s = newS.toString();
        int sum = 0;
        while (k > 0) {
            sum = 0;
            for (int i = 0; i < s.length(); i++) {
                sum += s.charAt(i) - '0';
            }
            s = String.valueOf(sum);
            k--;
        }
        return sum;
    }
}