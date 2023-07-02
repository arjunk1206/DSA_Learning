#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> matrix (n, vector<int> (n, 1e9));

        for (auto it: edges)
        {
            int src = it[0];
            int dst = it[1];
            int wt = it[2];
            
                matrix[src][dst] =  wt;
                matrix[dst][src] = wt;
            
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                    matrix[i][j] = 0;
            }
        }

        for(int val = 0; val < n; val++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0;  j < n; j++)
                {
                    if(matrix[i][val] == 1e9 || matrix[val][j] == 1e9)
                        continue;
                    
                    matrix[i][j] = min(matrix[i][j], matrix[i][val] + matrix[val][j]);
                }
            }
        }

        int cntcity = n;
        int cityno = -1;

        for(int city = 0; city < n; city++)
        {
            int cnt = 0;
            for(int adjcity = 0; adjcity < n; adjcity++)
            {
                if(matrix[city][adjcity] <= distanceThreshold)
                    cnt++;
            }

            if(cnt <= cntcity)
            {
                cntcity = cnt;
                cityno = city;
            }
        }

        return cityno;
    }
};