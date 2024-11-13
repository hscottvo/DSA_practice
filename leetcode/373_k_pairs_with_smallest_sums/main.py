# had to look at solutions
# runtime O(klogk)
# space O(|nums1|)?
import heapq
from typing import List


class Pair:
    def __init__(self, x, y, sum_val):
        self.x = x
        self.y = y
        self.sum_val = sum_val

    def __lt__(self, other):
        return self.sum_val < other.sum_val

    def __repr__(self):
        return f"{self.sum_val}"


class Solution:
    def kSmallestPairs(
        self, nums1: List[int], nums2: List[int], k: int
    ) -> List[List[int]]:
        ret = []

        pq = []

        for i in range(len(nums1)):
            heapq.heappush(pq, Pair(i, 0, nums1[i] + nums2[0]))

        for i in range(k):
            pair = heapq.heappop(pq)
            ret.append([nums1[pair.x], nums2[pair.y]])
            if pair.y + 1 < len(nums2):
                new_sum = nums1[pair.x] + nums2[pair.y + 1]
                heapq.heappush(
                    pq,
                    Pair(pair.x, pair.y + 1, new_sum),
                )

        return ret


if __name__ == "__main__":
    sol = Solution()

    nums1 = [1, 7, 11]
    nums2 = [2, 4, 6]
    print(sol.kSmallestPairs(nums1, nums2, 3))

    nums1 = [1, 1, 2]
    nums2 = [1, 2, 3]
    print(sol.kSmallestPairs(nums1, nums2, 2))

    nums1 = [1, 2, 4, 5, 6]
    nums2 = [3, 5, 7, 9]
    print(sol.kSmallestPairs(nums1, nums2, 3))

    x = """
    1 10 10 10 
    1 1  1  20

    k = 5
    1 1, 1 1, 1 1, 10 1, 10 1
    """
