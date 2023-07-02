#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> adjrev[V];
        vector<int> safe;
        vector<int> indegree (V,0);
        queue<int> q;

        for(int i = 0; i < V; i++)
        {
            for(auto it : graph[i])
            {
                adjrev[it].push_back(i);
            }
        }

        

        for(int i = 0; i < V; i++)
        {
            for(auto it: adjrev[i])
            {
                indegree[it]++;
            }
        }

        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            safe.push_back(node);
            q.pop();

            for(auto it: adjrev[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(safe.begin(),safe.end());
        

        return safe;
    }
};