#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
        dist[0][0] = 1;
        queue<pair<int,pair<int,int>>> q;

        
        if(grid[0][0] != 1)
        {
            if(n == 1)
                 return 1;
            q.push({0,{0,0}});
        }
        else
            return -1;
        
        

        while(!q.empty())
        {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            for(int dr = -1; dr <= 1; dr++)
            {
            for(int dc = -1; dc <= 1; dc++)
            {
                int nr = r + dr;
                int nc = c + dc;

                if(nr < n && nr >= 0 && nc < n && nc >= 0)
                {
                    if(grid[nr][nc] == 0 && d + 1 < dist[nr][nc])
                    {
                        dist[nr][nc] = d + 1;
                        q.push({d + 1,{nr,nc}});
                    }
                }
            }
        }
        }

        if(dist[n-1][n-1] != INT_MAX)
            return dist[n-1][n-1] + 1;
        else
            return -1;
    }
};