# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    prev=None
    def flatten(self, root):
        if root is None:
            return

        self.flatten(root.right)
        self.flatten(root.left)

        root.left=None
        root.right=self.prev
        self.prev=root
        