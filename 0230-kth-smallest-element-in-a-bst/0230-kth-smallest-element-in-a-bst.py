# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        self.ans=0
        self.cnt=0
    def inorder(self,root,k):
        if root is None:
            return
        self.inorder(root.left,k)
        self.cnt+=1

        if self.cnt==k:
            self.ans=root.val
            return

        self.inorder(root.right,k)
    def kthSmallest(self, root, k):
        cnt=0
        ans=0
        self.inorder(root,k)
        return self.ans
      
        