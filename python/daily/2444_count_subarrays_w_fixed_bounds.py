from typing import List
import math
def count_subarrays(nums: List[int], minK: int, maxK: int) -> int:    
    is_maxK = False
    is_minK = False
    left = 0
    right = 0
    res = 0
    # check if numbers are minK and maxK are present at all
    for num in nums:
        if num == maxK:
            is_maxK = True
        if num == minK:
            is_minK = True

    if is_minK and is_maxK:
        # Idea right now is to find windows where contstrain is true
        # and calculate number of subarrays possible
        # then move left pointer if window is broken
        # track current min and max until we are in bound
        left_val = nums[left]
        curr_min = math.inf
        curr_max = -1

        while right < len(nums):
            if nums[left] < minK or nums[left] > maxK:
                left += 1
                right = left
                continue

            if nums[right] > curr_max:
                curr_max = nums[right]
            if nums[right] < curr_min:
                curr_min = nums[right]

            # we are in bounds
            if curr_max == maxK and curr_min == minK:
                res += 1

    else:
        return 0
def count_subarrays_bf(nums: List[int], minK: int, maxK: int) -> int:    
    count = 0
    for i in range(len(nums)):
        mini = float('inf')
        maxi = float('-inf')
        for j in range(i, len(nums)):
            mini = min(mini, nums[j])
            maxi = max(maxi, nums[j])
            if mini == minK and maxi == maxK:
                count += 1
    return count

def count_subarrays_sliding_window(nums: List[int], minK: int, maxK: int) -> int:    
    count = 0
    start = -1
    mini = -1
    maxi = -1
    for i in range(len(nums)):
        if nums[i] < minK or nums[i] > maxK:
            start = i
        if nums[i] == maxK:
            maxi = i
        if nums[i] == minK:
            mini = i
        valid = max(0, min(mini, maxi) - start)
        count += valid
    return count

def main():
    nums = [1,3,5,2,7,5]
    minK = 1
    maxK = 5
    count_subarrays(nums, minK, maxK)

if __name__ == '__main__':
    main()