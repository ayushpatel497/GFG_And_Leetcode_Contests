//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin>>A[i][j];
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int N, int currentCoins, int& maxCoins) {
        if (i < 0 || j < 0 || i >= N || j >= N || visited[i][j] || grid[i][j] == 0) return;
        
        visited[i][j] = true;
        currentCoins += grid[i][j];
        maxCoins = max(maxCoins, currentCoins);
        
        dfs(grid, visited, i + 1, j, N, currentCoins, maxCoins);
        dfs(grid, visited, i - 1, j, N, currentCoins, maxCoins);
        dfs(grid, visited, i, j + 1, N, currentCoins, maxCoins);
        dfs(grid, visited, i, j - 1, N, currentCoins, maxCoins);
        
        visited[i][j] = false;
    }
public:
    int maximumCoins(int N, vector<vector<int>> &grid) {
        int maxCoins = 0;
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
             
                if ((i + j) % 2 == 1 && grid[i][j] > 0) {
                    dfs(grid, visited, i, j, N, 0, maxCoins);
                }
            }
        }
        return maxCoins;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<vector<int>> grid(N, vector<int>(N));
        Matrix::input(grid,N,N);
        
        Solution obj;
        int res = obj.maximumCoins(N, grid);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends