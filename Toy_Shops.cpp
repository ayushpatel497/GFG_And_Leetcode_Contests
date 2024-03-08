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
                scanf("%d ",&A[i][j]);
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
  public:
    int minimumDifference(int N, int M, vector<vector<int>> &toys) {
        // code here
        vector<pair<int, int>> v;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                v.push_back({toys[i][j], i});
            }
        }
        sort(v.begin(), v.end());
        vector<int> vis(N, 0);
        int count = 0, ans = INT_MAX;
        int j=0; 
        for(int i=0; i<v.size(); i++){
            vis[v[i].second]++;
            if(vis[v[i].second]==1){
                count++;
            }
            while(count == N){
                ans = min(ans, v[i].first-v[j].first);
                vis[v[j].second]--;
                if(vis[v[j].second]==0){
                    count--;
                }
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int M;
        scanf("%d",&M);
        
        
        vector<vector<int>> toys(N, vector<int>(M));
        Matrix::input(toys,N,M);
        
        Solution obj;
        int res = obj.minimumDifference(N, M, toys);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends