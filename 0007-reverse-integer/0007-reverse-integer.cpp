class Solution {
public:
    int reverse(int x) {
        int n=0;
        int sign=1;

        while(x!=0){

            int y=x%10;
            x/=10;

            if(n>INT_MAX/10 || (n==INT_MAX/10 && y>7))return 0;
            if(n<INT_MIN/10 || (n==INT_MIN/10 && y<-8))return 0;
            n=n*10+y;
        }
        return sign*n;
    }
};