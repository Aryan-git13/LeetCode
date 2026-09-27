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
    void preorder(TreeNode* root,vector<string>&s,string& p){
        if(root==NULL)return;
        int len=p.size();
        p+=to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            s.push_back(p);
            }

        else{
        p+="->";
        preorder(root->left,s,p);
        preorder(root->right,s,p);
        }
        p.resize(len);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>s;
        if(root->left==NULL && root->right==NULL){
            s.push_back(to_string(root->val));
            return s;
            }
        string p="";
        preorder(root,s,p);
        return s;
    }
};