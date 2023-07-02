#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> vis (numCourses,0);
        vector<int> pathvis(numCourses,0);
        vector<int> adjLS[numCourses];

        for(int i = 0; i < prerequisites.size();i++)
        {
            adjLS[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        int V = numCourses;

        vector<int> indegree(V,0);

        for(int i = 0; i < V; i++)
        {
            for(auto it: adjLS[i])
            {
                indegree[it]++;
            }
        }

        vector<int> topo;
        queue<int> q;

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
            q.pop();
            topo.push_back(node);
            for(auto it : adjLS[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        vector<int> null;
        if(topo.size() == V)
            return topo;
        else
            return null ;


    }
};