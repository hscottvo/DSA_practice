from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def pathSumHelper(
        self,
        root: Optional[TreeNode],
        ret: List[List[int]],
        node_list: List[int],
        path_sum: int,
        targetSum: int,
    ) -> None:
        if root is None:
            print("This should never happen")
            return
        if (
            root.left is None
            and root.right is None
            and path_sum + root.val == targetSum
        ):
            print(f"Visiting leaf node {root.val}")
            node_list.append(root.val)
            ret.append(node_list.copy())
            node_list.pop()
            return

        node_list.append(root.val)
        print(f"Visiting node {root.val}")
        print(f"\tcurrent sum without current val: {path_sum}")
        print(f"\tcurrent list with current val: {node_list}")
        if root.left is not None:
            self.pathSumHelper(
                root.left, ret, node_list, path_sum + root.val, targetSum
            )
        if root.right is not None:
            self.pathSumHelper(
                root.right, ret, node_list, path_sum + root.val, targetSum
            )

        print(f"On node {root.val}, have list {node_list} after recursive calls")
        node_list.pop()

        return

    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if root is None:
            return []
        ret = list(list())
        starting_node_list = []
        self.pathSumHelper(root, ret, starting_node_list, 0, targetSum)
        return ret


if __name__ == "__main__":
    sol = Solution()
    # root = TreeNode(
    #     5,
    #     TreeNode(4, TreeNode(11, TreeNode(7), TreeNode(2))),
    #     TreeNode(8, TreeNode(13), TreeNode(4, TreeNode(5), TreeNode(1))),
    # )
    # ret = sol.pathSum(root, 22)

    # root = TreeNode(1, TreeNode(2), TreeNode(3))
    # ret = sol.pathSum(root, 3)

    ret = sol.pathSum(None, 3)

    print(ret)
