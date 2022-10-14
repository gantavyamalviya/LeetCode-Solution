class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ct = 0, res = -1;
        queue<vector<int>> q;
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j] > 0) ct++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty()){
            res++;
            int size = q.size();
            for(int i = 0; i<size; i++){
                vector<int> temp = q.front();
                ct--;
                q.pop();
                for(int i = 0; i<4; i++){
                    int x = temp[0] + dir[i][0]; int y = temp[1] + dir[i][1];
                    if(x>=grid.size() or y>=grid[0].size() or x<0 or y<0 or grid[x][y] != 1){
                        continue;
                    }
                    grid[x][y] = 2;
                    q.push({x,y});
                }
            }
        }
        if(ct==0) return max(0,res);
        return -1;
    }
};