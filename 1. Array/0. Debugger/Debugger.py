class Solution:
    def search(self, nums, target):
        left = 0
        right = len(nums) - 1

        while left <= right:
            pivot = left + (right - left) // 2

            if target == nums[pivot]:
                return pivot

            if nums[left] <= nums[pivot]:
                if nums[left] <= target and target < nums[pivot]:
                    right = pivot - 1
                else:
                    left = pivot + 1
            else:
                if nums[right] >= target and target > nums[pivot]:
                    left = pivot + 1
                else:
                    right = pivot - 1

        return -1


solution = Solution()
nums = [4, 5, 6, 7, 0, 1, 2]
target = 0
index = solution.search(nums, target)
if index != -1:
    print(f"Target {target} found at index {index}")
else:
    print(f"Target {target} not found in the array.")
