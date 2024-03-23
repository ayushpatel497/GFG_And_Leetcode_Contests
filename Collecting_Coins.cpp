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
    int collectingCoins(int N, vector<vector<int>> &Coins) {
        // code here
        vector<int>hori(N+1,0);
        vector<int>vert(N+1,0);
        vector<int>posSlope((2*N)+1,0);
        vector<int>negSlope((2*N),0);
        int maxi=0;
        for(int i = 0; i < Coins.size(); i++)
        {
            int x = Coins[i][0], y = Coins[i][1];
            hori[x]++;
            vert[y]++;
            maxi = max(maxi, max(hori[x],vert[y]));
            posSlope[x+y]++;
            negSlope[x-y+N]++;
            maxi = max(maxi, max(posSlope[x+y],negSlope[x-y+N]));
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<vector<int>> Coins(N, vector<int>(2));
        Matrix::input(Coins,N,2);
        
        Solution obj;
        int res = obj.collectingCoins(N, Coins);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends