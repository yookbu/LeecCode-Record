//
// Created by Administrator on 2020/5/8 0008.
//

class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.empty()) return "Neither";
        if(IP.find('.') != string::npos){
            int start = 0;
            int i = 0;
            for(; i < 4; ++i){
                int dotIndex = IP.find('.', start);
                string num;
                if(i == 3){
                    if(dotIndex != string::npos) return "Neither";
                    num = IP.substr(start);
                }else{
                    num = IP.substr(start, dotIndex-start);
                }
                cout << num << endl;
                if(num.empty() || (num.size() > 1 && num[0] == '0')) return "Neither";
                unsigned num_ = 0;
                for(char a : num){
                    num_ = num_*10 + (a-'0');
                }
                if(num_ < 0 || num_ > 255) return "Neither";
                start = dotIndex+1;
            }
            if(i!=4) return "Neither";
            return "IPv4";
        }
        if(IP.find(':') != string::npos){
            int start = 0;
            int i = 0;
            for(; i < 8; ++i){
                int index = IP.find(':', start);
                string num;
                if(i == 7){
                    num = IP.substr(start);
                }else{
                    num = IP.substr(start, index-start);
                }

                if(num.empty() || num.size()>4) return "Neither";
                for(auto a : num){
                    if((a >= '0' && a <= '9') || (a>='a' && a<='f') || (a>='A' && a<='F')){
                        continue;
                    }else{
                        return "Neither";
                    }
                }
                start = index+1;
            }
            if(i != 8) return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
};