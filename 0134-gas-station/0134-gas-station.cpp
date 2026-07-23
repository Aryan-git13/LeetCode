class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gs=0,cs=0;

        for(auto it:gas){
            gs+=it;
        }
        for(auto it:cost){
            cs+=it;
        }

        if(gs<cs)return -1;

        int start=0;
        int css=0;

        for(int i=0;i<gas.size();i++){
            css+=gas[i]-cost[i];
            if(css<0){
                start=i+1;
                css=0;
            }
        }
        return start;
    }
};