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
    int dfs(vector<Employee*> employees,int x){
        for(auto it:employees){
            if(it->id==x){
                int ans=it->importance;

                for(auto y:it->subordinates){
                    ans+=dfs(employees,y);
                }
                return ans;
            }
        }
        return 0;
    }
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees,id);
    }
};