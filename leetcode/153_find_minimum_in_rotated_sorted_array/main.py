# Took 42 minutes

from typing import List

# Cases for middle:
# mid < low: min has to be between low and mid
# mid > high: min has to be between mid and high
# low < high: min has to be at low

# mid > low: that means there wasn't a rollover between low and mid: then if low isn't the min, then it has to be between mid and high
# mid < low: there was a rollover between low and mid: min has to be between

# mid > high: there was a rollover between mid and high: min has to be between
# mid < high: no rollover: min has to be between low and mid


class Solution:
    def findMin(self, nums: List[int]) -> int:
        low = 0
        high = len(nums)
        mid = (low + high) // 2
        while low != high - 1:
            mid = (low + high) // 2
            print(f"low: {low} mid: {mid} high: {high}")
            print(f"low val: {nums[low]} mid val: {nums[mid]} high val: {nums[high-1]}")

            if nums[mid] < nums[mid - 1]:
                return nums[mid]
            elif nums[low] <= nums[high - 1]:
                return nums[low]
            elif nums[low] > nums[mid]:
                high = mid + 1
            elif nums[low] < nums[mid]:
                low = mid

        return nums[low]


if __name__ == "__main__":
    sol = Solution()

    # arr = [11, 13, 15, 17]
    # print(sol.findMin(arr))

    # arr = [4, 5, 6, 7, 0, 1, 2]
    # print(sol.findMin(arr))

    arr = [3, 4, 5, 1, 2]
    print(sol.findMin(arr))

    # arr = [1]
    # print(sol.findMin(arr))
