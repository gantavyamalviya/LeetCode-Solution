class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        for(auto x : prerequisites){
            graph[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0) 
                q.push(i);
        }
        int counter = 0;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            counter++;
            for(auto x : graph[t]){
                if(--indegree[x] == 0)
                    q.push(x);
            }
        }
        return counter == numCourses;
    }
};