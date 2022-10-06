// 1 -> 2 -> 6 -> 9 => 4



class Solution {
public:
    vector<vector<int> > dp; 
    int moves[4][2] = { {-1,0}, {0,-1}, {0,1}, {1,0}};
    
    int fun(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        dp[i][j] = 1;
        for(int k = 0; k<4; k++){
            int ii = i + moves[k][0];
            int jj = j + moves[k][1];
            if(ii < 0 or jj < 0 or ii >= size(matrix) or jj >=size(matrix[0]) or matrix[i][j] >= matrix[ii][jj])
                continue;
            dp[i][j] = max(dp[i][j], 1+fun(matrix, ii, jj));
        }
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp.resize(size(matrix), vector<int>(size(matrix[0])));
        int mx = 1;
        for(int i = 0; i<size(matrix); i++){
            for(int j = 0; j<size(matrix[0]); j++){
                mx = max(mx, fun(matrix, i, j));
            }
        }
        return mx;
    }
};