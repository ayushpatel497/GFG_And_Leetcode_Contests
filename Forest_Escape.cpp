//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool escapeForest(int n,int m,vector<vector<char>> &grid){
        // Code here
        vector<pair<int,int>> q;
        int a;
        int b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X'){
                    grid[i][j]=0;
                    q.push_back({i,j});
                }else if(grid[i][j]=='M'){
                    a=i;
                    b=j;
                }
            }
        }
        int u=1,d=1,l=1,r=1;
        for(auto it:q){
            int s=it.first;
            int t=it.second;
            if(abs(s)+abs(b-t)<=a)
                u=0;
            if(t+abs(s-a)<=b)
                l=0;
            if(abs(n-s)+abs(t-b)<=n-a)
                d=0;
            if(abs(s-a)+abs(m-t)<=m-b)
                r=0;
        }
        if(u==1 || d==1 || l==1 || r==1)
            return true;
        return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> grid(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        Solution ob;
        if(ob.escapeForest(n,m,grid)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends