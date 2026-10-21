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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* r=new TreeNode(val);
            r->left=root;
            return r;
        }
        if(root==NULL)return NULL;
        queue<TreeNode*>q;
        q.push(root);
        int l=1;
        while(!q.empty()){
            int sz=q.size();
                while(sz--){
                    TreeNode* n=q.front();
                    q.pop();
                    if(l==depth-1){
                        TreeNode* lf=new TreeNode(val);
                        TreeNode* rf=new TreeNode(val);
                        lf->left=n->left;
                        rf->right=n->right;
                        n->left=lf;
                        n->right=rf;
                    }
                   else {
                    if(n->left)q.push(n->left);
                    if(n->right)q.push(n->right);
                    }
                }
                if(l==depth-1){
                    break;
                }
                l++;
            }
        return root;
    }
};