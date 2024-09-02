import static java.lang.Math.abs;
class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return abs(date_to_int(date2) - date_to_int(date1));
    }
    int date_to_int(String date){
        int year = Integer.parseInt(date.substring(0, 4));
        int month = Integer.parseInt(date.substring(5, 7));
        int day = Integer.parseInt(date.substring(8, 10));

        int cnt = 0;
        for(int y = 1971; y < year; ++y) cnt += is_leap_year(y) ? 366 : 365;
        for(int m = 1; m < month; ++m) cnt += days_in_month(m, year);
        return cnt + day;
    }

    boolean is_leap_year(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    int days_in_month(int m, int year) {
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
        if (m == 2) return is_leap_year(year) ? 29 : 28;
        return 30;
    }
}