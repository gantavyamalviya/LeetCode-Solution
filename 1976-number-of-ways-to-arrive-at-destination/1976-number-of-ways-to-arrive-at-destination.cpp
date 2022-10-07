#define ll long long
class Solution {
public:
    ll mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<ll,ll>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,1e18), ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                ll adjNode = it.first;
                ll adjW = it.second;
                if(dis + adjW < dist[adjNode]){
                    dist[adjNode] = dis + adjW;
                    pq.push({dis + adjW, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dis + adjW == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};