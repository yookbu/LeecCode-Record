//28. 实现 strStr()
// Created by Administrator on 2020/5/11 0011.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        else if(haystack.empty()) return -1;
        int len = needle.size();
        if(len > haystack.size()) return -1;
        for(int i = 0; i <= haystack.size()-len; ++i){
            string s(haystack.begin()+i, haystack.begin()+i+len);
            if(s == needle) return i;
        }
        return -1;
    }
};