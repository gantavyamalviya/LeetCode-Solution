class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i<26; i++){
            uf[i] = i;
        }
        for(auto x : equations){
            if(x[1] == '='){
                uf[find(x[0] - 'a')] = find(x[3]-'a');
            }
        }
        for(auto x : equations){
            if(x[1] == '!' and find(x[0] - 'a') == find(x[3]-'a')){
                return false;
            }
        }
        return true;
    }
    int find(int x){
        if(x!=uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};