//  867. Transpose Matrix
//  Given a matrix A, return the transpose of A.
//  The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.
//  https://leetcode.com/problems/transpose-matrix/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        if(A.empty()){
            return {};
        }
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> B(n,vector<int>(m,0));
        for(int i = 0;i<n;++i)
            for(int j = 0;j<m;++j)
                B[i][j] = A[j][i];
        return B;
    }
};