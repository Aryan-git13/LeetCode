# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        ans=[]

        if root is None:
            return ans

        q=deque()
        q.append(root)

        while q:
            n=len(q)
            maxi = float('-inf')
            while n>0:
                node=q.popleft()
                

                if(node.left):
                    q.append(node.left)
                if(node.right):
                    q.append(node.right)

                if(node.val>maxi):
                    maxi=node.val
                n-=1
            ans.append(maxi)

        return ans
