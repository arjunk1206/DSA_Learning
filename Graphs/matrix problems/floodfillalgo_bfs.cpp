#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> vis(m, vector<int> (n,0));

        int oc = image[sr][sc];

        image[sr][sc] = color;
        vis[sr][sc] = 1;
        queue<pair<int,int>> q;

        q.push({sr,sc});

        //traversal from starting index
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int delrow = -1; delrow <= 1; delrow++)
            {
                for(int delcol = -1; delcol <= 1; delcol++)
                {
                    if((delcol - delrow)%2)
                    {
                        int nrow = row + delrow;
                        int ncol = col + delcol;
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n)
                    {
                        if(!vis[nrow][ncol] && image[nrow][ncol] == oc)
                        {
                            q.push({nrow,ncol});
                            vis[nrow][ncol] = 1;
                            image[nrow][ncol] = color;
                        }
                    }
                    }
                }
            }
        }

        return image;

    }
};