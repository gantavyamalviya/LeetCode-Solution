class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        stack<int>s;
      
        for(int i=0;i<n;i++){
           int largest=arr[i];
            while(!s.empty()&&arr[i]<s.top())
                largest=max(largest,s.top()),s.pop();
           
            s.push(largest);
        }
        return s.size();
    }
};