#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>> &image, int sr, int sc, int oc, int color, vector<vector<int>> &ans)
    {   
        int m = image.size();
        int n = image[0].size();
        ans[sr][sc] = color;

        for(int delrow = -1; delrow <= 1; delrow++)
        {
            for(int delcol = -1; delcol <= 1; delcol++)
            {
                if((delrow - delcol)%2)
                {
                    int nrow = sr + delrow;
                    int ncol = sc + delcol;
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n)
                    {
                        if(image[nrow][ncol]== oc && ans[nrow][ncol] != color)
                        {
                            dfs(image,nrow,ncol,oc,color,ans);
                        }
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       vector<vector<int>> ans = image;
       int oc = image[sr][sc];

       dfs(image,sr,sc,oc,color,ans);

       return ans;

    }
};