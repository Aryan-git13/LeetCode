class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        int i=1;
        int cnt=1;

        while(i<ratings.size()){
            if(ratings[i]==ratings[i-1]){cnt+=1;i++;continue;}

            int x=1;
            while(i<n && ratings[i]>ratings[i-1]){
                x++;cnt+=x;i++;
            }
            int y=1;

            while(i<n && ratings[i]<ratings[i-1]){
                cnt+=y;i++;y++;
            }
            if(y>x)cnt+=y-x;
        }
        return cnt;
    }
};