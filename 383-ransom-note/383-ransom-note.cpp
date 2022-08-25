class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> v1(26),v2(26);
        for(auto x : magazine){
            v1[x-'a']++;
        }
        for(auto x : ransomNote){
            v2[x-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(v2[i]>v1[i])
                return false;
        }
        return true;
    }
};