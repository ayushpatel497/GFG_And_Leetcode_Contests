//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int candyShop(int n, vector<int> &candies) {
        // code here
        vector<int> counter(1001);
        for(auto& x : candies) {
            counter[x]++;
        }
        
        int unique = 0;
        for(int i=1;i<=1000;++i) 
            if (counter[i] > 0) 
                unique += 1;
        int cur = 0;
        int curval = 0;
        int ans = 1e9;
        counter.assign(1001, 0);
        for(int r=0, l=0;r<n;++r) {
            if (counter[candies[r]] == 0) ++cur;
            counter[candies[r]]++;
            curval += candies[r];
            while(l <= r and counter[candies[l]] > 1) {
                counter[candies[l]]--;
                curval -= candies[l];
                l++;
            } 
            if (cur == unique) ans = min(ans, curval);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> candies(n);
        Array::input(candies,n);
        
        Solution obj;
        int res = obj.candyShop(n, candies);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends