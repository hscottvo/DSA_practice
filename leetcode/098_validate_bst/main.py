from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def bst_helper(
        self,
        root: Optional[TreeNode],
        left_bound: float | int,
        right_bound: float | int,
    ) -> bool:

        if root is None:
            print("This should never happen")
            return False

        if root.val <= left_bound or root.val >= right_bound:
            return False

        left = False
        if root.left is None or self.bst_helper(root.left, left_bound, root.val):
            left = True

        right = False
        if root.right is None or self.bst_helper(root.right, root.val, right_bound):
            right = True

        return left and right

    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        return self.bst_helper(root, float("-inf"), float("inf"))


if __name__ == "__main__":
    sol = Solution()
    # root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    # print(sol.isValidBST(root))

    root = TreeNode(2, TreeNode(1), TreeNode(3))
    print(sol.isValidBST(root))
