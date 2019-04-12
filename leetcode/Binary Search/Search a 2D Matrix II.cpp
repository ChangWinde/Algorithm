//  240. Search a 2D Matrix II
//  Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//  Integers in each row are sorted in ascending from left to right.
//  Integers in each column are sorted in ascending from top to bottom.
//  https://leetcode.com/problems/search-a-2d-matrix-ii/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        int up = 0;
        n--;
        while(n>=0&&up<m){
            if(target>matrix[up][n]){
                up++;
            }else if(target<matrix[up][n]){
                n--;
            }else{
                return true;
            }
        }
        return false;
    }
};
