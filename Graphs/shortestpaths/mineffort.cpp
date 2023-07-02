#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> distance(rows, vector<int> (cols, INT_MAX));
        distance[0][0] = 0;
        int dr[] = {0,0,+1,-1};
        int dc[] = {+1,-1,0,0};

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,             greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            int eff = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            if(r == rows-1 && c ==  cols -1)
                return eff;
            pq.pop();

            for(int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                {
                    int u = max(abs(heights[nr][nc] -  heights[r][c]), eff);
                    if( u < distance[nr][nc])
                    {
                        distance[nr][nc] = u;
                        int newEffort = distance[nr][nc];
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }

            return 0;
    }
};