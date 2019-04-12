//  931. Minimum Falling Path Sum
//  Given a square array of integers A, we want the minimum sum of a falling path through A.
//  A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.
//  https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int mymin(int a,int b,int c){
        a=a<b?a:b;
        return a<c?a:c;
    }
    int smallest(vector<int>& A){
        if(A.size()==0)
            return 0;
        int temp = A[0];
        int size = A.size();
        for(int i = 0;i<size;++i)
            temp = temp<A[i]?temp:A[i];
        return temp;
    }
    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size()==0)
            return 0;
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> res(A);
        for(int i = m-2;i>=0;--i){
            for(int j = n-2;j>0;--j){
                res[i][j] = mymin(res[i+1][j-1],res[i+1][j],res[i+1][j+1])+A[i][j];
            }
            res[i][0] = min(res[i+1][0],res[i+1][1])+A[i][0];
            res[i][n-1] = min(res[i+1][n-2],res[i+1][n-1])+A[i][n-1];
        }
        return smallest(res[0]);
    }
};