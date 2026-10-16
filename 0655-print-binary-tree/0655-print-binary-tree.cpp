/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root==NULL)return 0;

        return 1+max((height(root->left)),(height(root->right)));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int n=height(root);
        int m=pow(2,n)-1;

        vector<vector<string>>ans(n,vector<string>(m,""));

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,(m-1)/2}});
        ans[0][(m-1)/2]=to_string(root->val);

        while(!q.empty()){
            auto it=q.front();
            TreeNode* x=it.first;
            int r=it.second.first;
            int c=it.second.second;
            q.pop();

            if(x->left){
                ans[r+1][c-pow(2,n-r-2)]=to_string(x->left->val);
                q.push({x->left,{r+1,c-pow(2,n-r-2)}});
            }
            if(x->right){
                ans[r+1][c+pow(2,n-r-2)]=to_string(x->right->val);
                q.push({x->right,{r+1,c+pow(2,n-r-2)}});
            }
        }
        return ans;
    }
};