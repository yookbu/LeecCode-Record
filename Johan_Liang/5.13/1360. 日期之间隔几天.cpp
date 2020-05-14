//1360. 日期之间隔几天
// Created by Administrator on 2020/5/14 0014.
//

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        string year1s(date1.begin(), date1.begin()+4);
        string year2s(date2.begin(), date2.begin()+4);
        string month1s(date1.begin()+5, date1.begin()+7);
        string month2s(date2.begin()+5, date2.begin()+7);
        string day1s(date1.begin()+8, date1.end());
        string day2s(date2.begin()+8, date2.end());
        int year1 = atoi(year1s);
        int year2 = atoi(year2s);
        int month1 = atoi(month1s);
        int month2 = atoi(month2s);
        int day1 = atoi(day1s);
        int day2 = atoi(day2s);
        return abs(daysCount(year1, month1, day1) - daysCount(year2, month2, day2));
    }

    int daysCount(int year, int month, int day){
        int res = day;
        vector<int> months = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        month--;
        while(month != 0){
            res += months[month];
            if(month == 2 && isRun(year)){
                res += 1;
            }
            month--;
        }
        res += (year-1971)*365;
        res += (year-1)/4 - 1971/4;
        res -= (year-1)/100 - 1971/100;
        res += (year-1)/400 - 1971/400;
        return res;
    }

    bool isRun(int year){
        if((year%4 == 0 && year%100 != 0 )|| year%400 == 0) return true;
        else return false;
    }

    int atoi(string str){
        int n = 0;
        for(char c : str){
            n = n*10 + (c - '0');
        }
        return n;
    }
};