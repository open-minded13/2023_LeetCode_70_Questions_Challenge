class Solution:
    def containsDuplicate(self, nums):
        seen = set()
        for num in nums:
            if num in seen:
                print(num)
                return True
            else:
                seen.add(num)
        return False


sol = Solution()
nums = [1, 6, 3, 3, 5]
result = sol.containsDuplicate(nums)
