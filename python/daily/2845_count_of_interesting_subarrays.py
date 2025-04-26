from typing import List
from collections import Counter

def count_interesting_subarrays(nums: List[int], modulo: int, k: int) -> int:
    res = 0
    count = [0] * len(nums)


    # need to fill count[i] with the number of elements that 
    # are interesting within the first i elements of nums
    
    # base case (not needed here due to initialization)
    count[0] = 0

    # start at index 1 and check count[i - 1] and build iteratively
    for i in range(1, len(nums)):
        if (nums[i - 1] % modulo) == k:
            prev = count[i - 1]
            count[i] = 1
            count[i] += prev
    
    return count

def count_interesting_optimal(nums, modulo, k):
        n = len(nums)
        cnt = Counter([0])
        res = 0
        prefix = 0
        for i in range(n):
            prefix += 1 if nums[i] % modulo == k else 0
            res += cnt[(prefix - k + modulo) % modulo]
            cnt[prefix % modulo] += 1
        return res

def main():
    nums = [3,2,4]
    print(count_interesting_subarrays(nums, 2, 1))

if __name__ == '__main__':
    main()