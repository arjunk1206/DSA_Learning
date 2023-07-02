#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> vis(m, vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;

        //initial values
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j},0});
                    vis[i][j] = 1;

                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int dr[] = {0,0,1,-1};
        int dc[] = {1,-1,0,0};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();

            dist[r][c] = d;
            //bfs for the neighbours
            for(int i  = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    if(vis[nr][nc] == 0)
                        {
                            vis[nr][nc] = 1;
                            q.push({{nr,nc},d+1});
                        }
                }
            }
        }

        return dist;
        
    }
};