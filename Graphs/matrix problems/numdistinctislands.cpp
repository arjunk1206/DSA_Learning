//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
        void dfs(int row, int col,vector<vector<int>> &vis, vector<vector<int>>& grid, vector<pair<int,int>> &elements, int row0, int col0)
        {
            int n = grid.size();
            int m = grid[0].size();
            vis[row][col] = 1;
            elements.push_back({row - row0, col - col0});
            
            int dr[] = {0,0,1,-1};
            int dc[] = {-1,1,0,0};
            
            for(int i = 0; i < 4;i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if(nr < n && nr >= 0 && nc < m && nc >= 0)
                {
                    if(!vis[nr][nc] && grid[nr][nc] == 1)
                    {
                        dfs(nr,nc,vis,grid,elements,row0,col0);
                    }
                }
            }
        }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis (n, vector<int> (m,0));
        set<vector<pair<int,int>>> s;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> elements;
                    dfs(i,j,vis,grid,elements,i,j);
                    s.insert(elements);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends