class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        temp = -1
        for i in range(len(nums)-2, -1, -1):
            if nums[i] < nums[i+1] : 
                temp = i
                break
        if temp == -1:
            return nums.reverse()
        for i in range(len(nums)-1, temp, -1):
            if nums[temp] < nums[i]:
                nums[temp], nums[i] = nums[i], nums[temp]
                break
        nums[temp+1:] = reversed(nums[temp+1:])