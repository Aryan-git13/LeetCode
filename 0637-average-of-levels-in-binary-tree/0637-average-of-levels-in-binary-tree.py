# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        ans=[]
        if root is None:
            return ans

        q=deque()
        q.append(root)
        while q:
            n=len(q)
            levelsum=0
            for i in range(0,n):
                node=q.popleft()
                
                levelsum+=node.val
                if(node.left):
                    q.append(node.left)
                if(node.right):
                    q.append(node.right)
            ans.append(float(levelsum)/n)                    
        return ans