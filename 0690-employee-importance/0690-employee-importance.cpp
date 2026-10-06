/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n=employees.size();
        queue<int>q;
        q.push(id);
        int cnt=0;

        while(!q.empty()){
            int x=q.front();
            q.pop();

            for(auto it:employees){
                if(it->id==x){
                    cnt+=it->importance;

                    for(auto x:it->subordinates){
                        q.push(x);
                    }
                    break;
                }
            }
        }
        return cnt;
    }
};