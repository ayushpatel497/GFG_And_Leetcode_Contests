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
// User function Template for C++
class Solution
{
public:
    int ans, tw, th;
    pair<int, int> count(vector<vector<int>> &adj, vector<int> &values, int par, int gpar)
    {
        int two = 0, three = 0;
        if (values[par] == 2)
        two = 1;
        else if (values[par] == 3)
        three = 1;
        for (auto child : adj[par])
        {
            if (child == gpar)
            continue;
            pair<int, int> p = count(adj, values, child, par);
            if ((tw - p.first) && (th - p.second) && (p.first) && (p.second))
            ans++;
            two += p.first;
            three += p.second;
        }
        return {two, three};
    }
    int splittingEdges(int n, vector<int> &values, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> adj(n);
        int m = edges.size();
        for (int i = 0; i < m; i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int two = 0, three = 0;
        for (int i = 0; i < n; i++)
        {
            if (values[i] == 2)
            two++;
            if (values[i] == 3)
            three++;
        }
        if (!two || !three)
        return 0;
        ans = 0;
        tw = two;
        th = three;
        count(adj, values, 0, -1);
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        int N;
        scanf("%d",&N);
        
        vector<int> Values(N);
        
        for(int i = 0;i < N; i++)
        {
            cin >> Values[i];
        }
        
        vector<vector<int>> Edges(N-1, vector<int>(2));
        Matrix::input(Edges,N-1,2);
        
        Solution obj;
        int res = obj.splittingEdges(N, Values, Edges);
        
        cout<<res<<endl;
    }
}
// } Driver Code Ends