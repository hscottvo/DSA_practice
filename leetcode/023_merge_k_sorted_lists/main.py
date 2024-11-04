# Took 25 minutes
# Time complexity: O(nlogn) where n is the total number of nodes across all lists
# - nlogn for pushing and popping all the nodes. n total for pushing to the final solution
import heapq
from typing import Optional, Sequence


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Node:
    def __init__(self, node: ListNode):
        self.node = node

    def __lt__(self, other):
        return self.node.val < other.node.val


class Solution:
    def mergeKLists(self, lists: Sequence[Optional[ListNode]]) -> Optional[ListNode]:
        if len(lists) == 0:
            return None

        pq = []
        for node in lists:
            if node is None:
                continue

            heapq.heappush(pq, Node(node))

        head = None
        tail = None
        while len(pq) != 0:
            node = heapq.heappop(pq).node
            if node is None:
                continue

            next_node = node.next
            if tail is None:
                head = node
                tail = head
            else:
                tail.next = node
                tail = node

            if next_node is not None:
                heapq.heappush(pq, Node(next_node))
        return head


def make_list(
    in_list: Sequence[Optional[Sequence[int]]],
) -> Sequence[Optional[ListNode]]:
    ret = []
    for i in in_list:
        if i is None or len(i) == 0:
            ret.append(None)
        else:
            head = ListNode(i[0])
            tail = head
            for j in i[1:]:
                new_node = ListNode(j)
                tail.next = new_node
                tail = new_node
            ret.append(head)

    return ret


if __name__ == "__main__":
    sol = Solution()

    lists = [[1, 4, 5], [1, 3, 4], [2, 6]]
    in_list = make_list(lists)
    ret = sol.mergeKLists(in_list)
    print("Test 1")
    while ret is not None:
        print(ret.val)
        ret = ret.next

    print("Test 2")
    lists = []
    in_list = make_list(lists)
    ret = sol.mergeKLists(in_list)
    while ret is not None:
        print(ret.val)
        ret = ret.next

    print("Test 3")
    lists = [[]]
    in_list = make_list(lists)
    ret = sol.mergeKLists(in_list)
    while ret is not None:
        print(ret.val)
        ret = ret.next
