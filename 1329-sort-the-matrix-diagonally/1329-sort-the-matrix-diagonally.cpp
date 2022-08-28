class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                m[i-j].push(mat[i][j]);
            }
        }
        
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                mat[i][j] = m[i-j].top();
                m[i-j].pop();
            }
        }
        return mat;
    }
};