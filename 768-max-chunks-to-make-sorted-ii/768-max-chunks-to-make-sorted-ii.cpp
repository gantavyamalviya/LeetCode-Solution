class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
        for(auto x : arr){
            int largest = s.empty() ? x : max(s.top(), x);
            while(!s.empty() and x < s.top()){
                s.pop();
            }
            s.push(largest);
        }
        return s.size();
    }
};