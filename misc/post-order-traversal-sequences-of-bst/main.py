from typing import List, clear_overloads

# 5 7 6 9 11 10 8
# 0 1 2 3 4  5  6


def check_tree(
    array: List[int], idx: int, left_bound: int | float, right_bound: int | float
) -> int:

    # if the subtree reaches the end of the array, return that index
    if idx < 0:
        return idx

    # otherwise, try doing the current subtree, starting from the right subtree
    # because we go on the right side, we tighten the left bound to the current root. right bound is unchanged
    if array[idx] < array[idx - 1]:
        idx = check_tree(array, idx - 1, array[idx], right_bound)

    # if there's anything left to check, check the left subtree next
    # because we go on the left side, we tighten the right bound to the current root. left bound is unchanged
    if idx > 0 and array[idx - 1] < array[idx]:
        idx = check_tree(array, idx - 1, left_bound, array[idx])

    return idx


def check_post_order_traversal(array: List[int]) -> bool:
    idx = len(input_list) - 1
    left_bound = float("-inf")
    right_bound = float("inf")
    if check_tree(array, idx, left_bound, right_bound) < 0:
        return True
    return False


if __name__ == "__main__":

    input_list = [5, 7, 6, 9, 11, 10, 8]
    # input_list = [1, 2, 3, 4, 5]
    # input_list = [2, 1, 4, 5, 3]
    # input_list = [7, 4, 6, 5]
    idx = len(input_list) - 1

    print(check_post_order_traversal(input_list))
