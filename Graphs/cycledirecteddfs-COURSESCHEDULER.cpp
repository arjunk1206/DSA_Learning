#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node,vector<int> adjLS[], vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it: adjLS[node])
        {
            if(!vis[it])
            {
                if(dfs(it,adjLS,vis,pathvis))
                {
                    return true;
                }
            }

            if(pathvis[it] == 1)
            {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis (numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<int> adjLS[numCourses];

        for(int i = 0; i < prerequisites.size();i++)
        {
            adjLS[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adjLS,vis,pathvis))
                    return false;
            }
        }

        return true;

        

        

        
        
    }
};