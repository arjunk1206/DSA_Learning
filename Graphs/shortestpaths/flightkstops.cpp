#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        vector<int> dist (n,INT_MAX);
        dist[src] = 0;

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if(stops > k)
                continue;
            for(auto iter : adj[node])
            {
                int adjnode = iter.first;
                int wt =  iter.second;
                if(cost + wt < dist[adjnode] && stops <= k)
                {
                    dist[adjnode] = cost + wt;
                    q.push({stops+1,{adjnode,dist[adjnode]}});
                }
            }
        }

        if(dist[dst] != INT_MAX)
            return dist[dst];
        else
           return -1;

    }
};