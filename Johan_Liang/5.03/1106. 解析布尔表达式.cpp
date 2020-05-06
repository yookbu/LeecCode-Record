//1106. 解析布尔表达式
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s1;
        stack<char> s2;
        for(int i = 0; i < expression.size(); ++i){
            if(expression[i] == '!' || expression[i] == '|' || expression[i] == '&'){
                s1.push(expression[i]);
            }else if(expression[i] == ')'){
                int t = 0;
                int f = 0;
                while(s2.top()!= '('){
                    if(s2.top() == 't'){
                        t++;
                    }
                    if(s2.top() == 'f'){
                        f++;
                    }
                    s2.pop();
                }
                s2.pop();
                char c = s1.top();
                s1.pop();
                if(c == '!'){
                    if(t){
                        s2.push('f');
                    }
                    if(f){
                        s2.push('t');
                    }
                }

                if(c == '|'){
                    if(t){
                        s2.push('t');
                    }else{
                        s2.push('f');
                    }
                }

                if(c == '&'){
                    if(f){
                        s2.push('f');
                    }else{
                        s2.push('t');
                    }
                }

            }else{
                s2.push(expression[i]);
            }
        }
        if(s2.top() == 't') return true;
        else return false;
    }
};