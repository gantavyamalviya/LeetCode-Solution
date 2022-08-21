class Solution {
public:
    vector<int> ans;
    int stars, n, m;
    vector<int> movesToStamp(string stamp, string target) {
        stars = 0, n = size(target), m = size(stamp);
        vector<bool> vis(n,false);
        while(stars < n){
            bool replaced = false;
            for(int i = 0; i<=n-m and stars < n; i++){
                if(!vis[i]) 
                    replaced = solve(target, i, stamp), vis[i] = replaced;
            }
            if(!replaced) return {};
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
    bool solve(string& target, int &start, string &stamp){
        for(int i = 0; i<m; i++){
            if(target[i+start] != '*' and target[i+start] != stamp[i]) return false;
        }
        ans.push_back(start);
        for(int i = start; i-start < m; i++){
            stars+=(target[i]!='*'), target[i] = '*';
        }
        return true;
    }
};


