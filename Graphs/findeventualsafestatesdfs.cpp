#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, vector<vector<int>>& graph,  vector<int> &vis, vector<int> &pathvis,    vector<int> &check)
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(dfs(it,graph,vis,pathvis,check))
                {
                    return true;
                }
               
            }

            if(pathvis[it] == 1)
                    return true;
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis (V,0);
        vector<int> pathvis (V,0);
        vector<int> check(V,0);
        vector<int> safe;

        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i,graph,vis,pathvis,check);
                
            }
        }

        for(int i = 0; i < V; i++)
        {
            if(check[i]==1)
            {
                safe.push_back(i);
            }
        }

        return safe;
    }
};