public:
    int convertInteger(int A, int B) {
        int c=A^B;
        int cnt=0;
        for(int i=0;i<32;i++){
            if((c>>i)&1){
                cnt+=1;
            }
        }
        return cnt;
    }
};

# 面试题48
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 先转置矩阵
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //再反转每一行。
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
};
