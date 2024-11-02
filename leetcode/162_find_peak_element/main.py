# Took 40 minutes

# Binary search using slopes
# 1. look if middle is a peak. if it is, return middle
# 2. if not, check the slope, contracting in the direction of the increase at mid
# some edge cases, might be able to make things neater
from typing import List


class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        if len(nums) == 2:
            return 0 if nums[0] > nums[1] else 1

        low = 0
        high = len(nums)

        while low != high:
            mid = (low + high) // 2
            print(low, mid, high)
            if mid == len(nums) - 1 and nums[mid - 1] < nums[mid]:
                return mid
            if nums[mid - 1] < nums[mid] and nums[mid + 1] < nums[mid]:
                return mid

            if nums[mid - 1] < nums[mid]:
                low = mid + 1
            else:
                high = mid

        return low


if __name__ == "__main__":
    sol = Solution()

    x = [1, 2, 3, 2]
    print(sol.findPeakElement(x))

    x = [1, 2]
    print(sol.findPeakElement(x))

    x = [1]
    print(sol.findPeakElement(x))

    x = [1, 2, 3, 2, 3, 4, 3]
    print(sol.findPeakElement(x))

    x = [5, 4, 3, 4, 5]
    print(sol.findPeakElement(x))

    x = [1, 2, 3]
    print(sol.findPeakElement(x))

    x = [3, 2, 1]
    print(sol.findPeakElement(x))

    x = [1, 2, 3, 4, 3]
    print(sol.findPeakElement(x))
