class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         Graph with (node,distance) as pairs.
        vector<pair<int,int>> graph[n];
        int r=flights.size();
        for(int i=0;i<r;i++)
        {
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
//         Implement Dijkstra algorithm to find distance between src and dest with the constraint to not allow more than k intermediate nodes.
//      Priority queue with pairs of ((distance,intermediate),node) 
        priority_queue<pair<pair<int,int>,int>> pq;
        int INF=1e8;
        vector<pair<int,int>> dis(n,{INF,0});
        pq.push({{0,0},src});
        dis[src]={0,0};
        while(!pq.empty())
        {
            int curr=pq.top().second;
            pq.pop();
            
            for(auto node: graph[curr])
            {
                int next=node.first;
                int distance=node.second;
                if(dis[curr].second<=k && dis[next].first>(dis[curr].first+distance))
                {
                    dis[next].first=dis[curr].first+distance;
                    dis[next].second=dis[curr].second+1;
                    pq.push({dis[next],next});
                }
            }
        }
        return (dis[dst].first==INF)?-1:dis[dst].first;
    }
};