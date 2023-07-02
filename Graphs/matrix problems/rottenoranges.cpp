#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int vis[m][n];
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }

            }
        }

        int tm = 0;
        int delrow[] = {0 ,-1, 0, +1};
        int delcol[] = {-1, 0, +1, 0};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            tm = max(t,tm);
            q.pop();
            

            for(int i = 0; i < 4; i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if( nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    if(vis[nr][nc] != 2 && grid[nr][nc] == 1)
                    {
                        
                        vis[nr][nc] = 2;
                        q.push({{nr,nc},t+1});
                    }
                }
                
            }

            
            
        }

        

        int rotten = 1;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] != 2 && grid[i][j] == 1)
                    rotten = 0;
            }
        }


        if(rotten)
            return tm;
        else
            return -1;


        
    }
};