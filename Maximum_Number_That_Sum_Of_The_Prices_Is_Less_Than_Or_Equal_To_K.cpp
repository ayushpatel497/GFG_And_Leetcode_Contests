class Solution {
private:
    int countBits(long long n) {
        int ct = 0;
        while(n) {
            ct++;
            n >>= 1;
        }        
        return ct;
    } 
    long long powerOf2(int i) {
        return 1LL << i;
    }
    long long calc(long long n, int x) {
        int i = countBits(n);        
        long long price = 0;
        n++;                
        while(i) {
            if(i % x == 0)
                price += (n/powerOf2(i)) * (powerOf2(i-1)) + max(0LL, (n % powerOf2(i)) - powerOf2(i-1));        
            i--;
        }        
        return price;
    }
    
public:
    long long findMaximumNumber(long long k, int x) {
        long long low = 1;
        long long high = 1e15;
        while(low <= high) {
            long long mid = (high - low) / 2 + low;
            long long res = calc(mid, x);            
            if(res <= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};