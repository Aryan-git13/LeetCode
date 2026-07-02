# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def search(self,inorder,left,right,val):
        for i in range(left,right+1):
            if inorder[i]==val:
                return i
        return -1
    
    def helper(self,inorder,postorder,left,right):
        if left>right:
            return None

        root=TreeNode(postorder[self.psidx])
        idx=self.search(inorder,left,right,root.val)
        self.psidx-=1

        root.right=self.helper(inorder,postorder,idx+1,right)
        root.left=self.helper(inorder,postorder,left,idx-1)
        return root


    def buildTree(self, inorder, postorder):
        self.psidx=len(postorder)-1

        return self.helper(inorder,postorder,0,len(postorder)-1)
        