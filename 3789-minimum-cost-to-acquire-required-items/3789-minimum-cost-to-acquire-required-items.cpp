class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long one=1LL*costBoth*(max(need1,need2));
        long long two=1LL*cost1*need1+1LL*cost2*need2;
            
        long long x=min(need1,need2);

        long long c = 1LL * costBoth * x
                    + 1LL * cost1 * (need1 - x)
                    + 1LL * cost2 * (need2 - x);
        
        
        return min({one,two,c});
    }
};