#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;
//判断闰年
bool leap_year(int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
//足年天数
inline int profit_of_year(int year) {
    return 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * 31 + 2 * 30 + 2 * 31 + 30 + 2 * 31 + leap_year(year);
}
//求前半段
int pro_sum(int year, int month, int day) {
    int res = 0;
    int i = 0;
    if (leap_year(year) && month > 2) {
        i = 1;
    }
    if (month == 1) {
        res = 2 * day;
    }
    else if (month == 2) {
        res = 2 * 31 + day;
    }
    else if (month == 3) {
        res = 2 * 31 + 28 + day;
    }
    else if (month == 4) {
        res = 2 * 31 + 28 + 31 + 2 * day;
    }
    else if (month == 5) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + day;
    }
    else if (month == 6) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * day;
    }
    else if (month == 7) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + day;
    }
    else if (month == 8) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * day;
    }
    else if (month == 9) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * 31 + 2 * day;
    }
    else if (month == 10) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * 31 + 2 * 30 + 2 * day;
    }
    else if (month == 11) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * 31 + 2 * 30 + 2 * 31 + day;
    }
    else if (month == 12) {
        res = 2 * 31 + 28 + 31 + 2 * 30 + 31 + 2 * 30 + 31 + 2 * 31 + 2 * 30 + 2 * 31 + 30 + 2 * day;
    }
    return res + i;
}
int main() {
    int year1, month1, day1;
    int year2, month2, day2;
    int sum = 0;
    while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2) {
        sum = 0;
        day1 -= 1;
        if (year1 == year2) {
            sum = pro_sum(year2, month2, day2) - pro_sum(year1, month1, day1);
        }
        else {
            sum += profit_of_year(year1) - pro_sum(year1, month1, day1);
            sum += pro_sum(year2, month2, day2);
            ++year1;
            while (year1 != year2) {
                sum += profit_of_year(year1);
                ++year1;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
