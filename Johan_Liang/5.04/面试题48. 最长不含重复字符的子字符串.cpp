//面试题48. 最长不含重复字符的子字符串
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        map<int, int> m;
        int i = 0, j = i;
        while(i < s.size()){
            if(m.find(s[i]) != m.end()){
                res = res > m.size() ? res : m.size();
                while(j <= m[s[i]]){
                    m.erase(s[j]);
                    ++j;
                }
            }
            m[s[i]] = i;
            i++;
        }
        res = res > m.size() ? res : m.size();
        return res;
    }
};