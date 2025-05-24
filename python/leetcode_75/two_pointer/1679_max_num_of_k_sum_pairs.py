from typing import List


def maxOperations(nums: List[int], k: int) -> int:
    nums.sort()

    left = 0
    right = len(nums) - 1
    res = 0

    while left < right:
        curr_sum = nums[left] + nums[right]

        if curr_sum == k:
            left += 1
            res += 1
            right -= 1
        elif curr_sum < k:
            left += 1
        else:
            right -= 1
    
    return res


def main():
    print(maxOperations(nums = [1,2,3,4], k = 5))

if __name__ == '__main__':
    main()