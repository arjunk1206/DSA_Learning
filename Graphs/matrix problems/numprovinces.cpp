//number of connected components

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
   void dfs(int node, vector<int> &vis, vector<int> adjLS[])
   {
       vis[node] = 1;
       for(auto it: adjLS[node])
       {
           if(!vis[it])
           {
               dfs(it,vis,adjLS);
           }
       }
   }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //no. of nodes
        int V = isConnected[0].size();
        vector<int> adjLS[V];

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                if(isConnected[i][j] == 1 & i!=j)
                {
                    adjLS[i].push_back(j);
                    adjLS[j].push_back(i);
                }
            }
        }

        vector<int> vis(V,0);
        int count = 0;

        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                count++;
                dfs(i,vis, adjLS);
            }
        }

        return count;
        
    }
};