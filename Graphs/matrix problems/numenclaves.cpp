#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));

        int all1s = 0;

        for(int i = 0 ; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 1)
                    all1s++;
            }
        }

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++)
        {
            if(grid[0][i]==1)
                {
                    vis[0][i] = 1;
                    q.push({0,i});
                    
                }

            if(grid[m-1][i]==1)
            {
                vis[m-1][i] = 1;
                q.push({m-1,i});
                
            }
        }

        for(int i = 0; i < m; i++)
        {
            if(grid[i][0]==1)
                {
                    vis[i][0] = 1;
                    q.push({i,0});
                    
                }

            if(grid[i][n-1]==1)
            {
                vis[i][n-1] = 1;
                q.push({i,n-1});   
            }
        }

        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};

        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr < m && nr >= 0 && nc < n && nc >=0)
                {
                    if(vis[nr][nc] == 0 && grid[nr][nc] == 1)
                    {   
                        vis[nr][nc] = 1;
                        q.push({nr,nc});
                    }
                }
            }
        }

        int con1s = 0;

         for(int i = 0 ; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 1)
                    con1s++;
            }
        }

        return all1s - con1s;




        
    }
};