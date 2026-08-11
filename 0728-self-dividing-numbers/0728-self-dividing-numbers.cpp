class Solution {
public:
    bool f(int x){
        int n=x;
        while(n!=0){
            int y=n%10;
            if(y!=0 && x%y==0){
                n/=10;
                continue;
            }
            else return false;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;

        for(int i=left;i<=right;i++){
            int x=i;
            if(f(i))ans.push_back(x);
        }
        return ans;
    }
};