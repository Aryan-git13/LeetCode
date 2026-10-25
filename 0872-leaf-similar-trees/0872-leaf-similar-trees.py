# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def dfs(self,root,arr):
        if root is None:
            return 

        if(root.left is None and root.right is None):
            arr.append(root.val)

        self.dfs(root.left,arr)
        self.dfs(root.right,arr)
    def leafSimilar(self, root1, root2):

        a=[]
        b=[]

        self.dfs(root1,a)
        self.dfs(root2,b)

        if(len(a)!=len(b)):
            return False
        for i in range(len(a)):
            if(a[i]!=b[i]):
                return False

        return True

        