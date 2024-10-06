from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def checkHelper(
        self,
        root: Optional[TreeNode],
        left_bound: int | float,
        right_bound: int | float,
    ) -> bool:
        if root is None or (root.left is None and root.right is None):
            return True

        if root.left is None:
            left_ok = True
        elif root.left.val < root.val and root.left.val > left_bound:
            # print(f"\tChecking left child {root.left.val}")
            left_ok = self.checkHelper(root.left, left_bound, root.val)
        else:
            left_ok = False

        if root.right is None:
            right_ok = True
        elif root.val < root.right.val and root.right.val < right_bound:
            # print(f"\tChecking left child {root.right.val}")
            right_ok = self.checkHelper(root.right, root.val, right_bound)
        else:
            right_ok = False

        return left_ok and right_ok

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        if root is None:
            return False
        return self.checkHelper(root, float("-inf"), float("inf"))


if __name__ == "__main__":
    sol = Solution()
    # root = TreeNode(5, TreeNode(1), TreeNode(4, TreeNode(3), TreeNode(6)))
    root = TreeNode(5, TreeNode(1), TreeNode(7, TreeNode(6), TreeNode(8)))
    # root = TreeNode(2, TreeNode(1), TreeNode(3))
    # root = TreeNode(0, TreeNode(-1))
    # root = TreeNode(5, TreeNode(4), TreeNode(6, TreeNode(3), TreeNode(7)))

    print(sol.isValidBST(root))
