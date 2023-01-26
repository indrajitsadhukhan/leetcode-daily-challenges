/*
My Notes: 
1. Basic idea is to compute the distance of all nodes from node1 (dis1[]) and same for node2 as well i.e. distance of all nodes from node2.(dis2[])

2. As there is no edge weight we can use BFS otherwise we would have used Dijkstra.

3. We compute the distances from node1 and node2 in dis1[] and dis2[] 

4. Then we will traverse all the nodes from i=0 to n-1 and take ans=max(dis1[i],dis2[i]) 
ans_node=i. (ans_node is the nearest node of node1,node2)

5. Take the minimum ans and return the corresponding ans_node.
if(ans>max(dis1[i],dis2[i])){
ans=max(dis1[i],dis2[i]);
ans_node=i;
}

6. Return ans_node.
*/
class Solution {
public:
    void computeDistance(int node1,vector<int> &dis1,int n,vector<int>& edges)
    {
        queue<pair<int,int>> q;
        q.push({node1,0});
        vector<int> vis1(n,0);
        dis1[node1]=0;
        while(!q.empty())
        {
            int curr=q.front().first;
            int dis=q.front().second;
            q.pop();
            vis1[curr]=1;
            dis1[curr]=dis;
            int node=edges[curr];
            if(node==-1 || vis1[node]==1)
                continue;
            q.push({node,dis+1});
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
//         We take two distance array dis1 and dis2 corresponding to node1 and node2. Initialize them as INF.
        int n=edges.size();
        vector<int> dis1(n,INT_MAX),dis2(n,INT_MAX);

//      Start BFS for node1.
        computeDistance(node1,dis1,n,edges);
//         Start BFS for node2
        computeDistance(node2,dis2,n,edges);
//       Iterate through all nodes 0 to n-1 and minimize max(dis1[i],dis2[i]);
        int ans=INT_MAX,ans_node=-1;
        for(int i=0;i<n;i++)
        {
            if(ans>max(dis1[i],dis2[i]))
            {
                ans=max(dis1[i],dis2[i]);
                ans_node=i;
            }
        }
        return ans_node;
    }
};