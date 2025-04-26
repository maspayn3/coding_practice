from typing import List
from collections import deque

# we can try to use the sliding window technique to check
# contiguous subarrays

def count_complete_subarrays(nums: List[int]) -> int:
    res = 0
    start = 0
    end = 1
    sub_array = set()
    num_distinct_elements = len(set(nums))

    if len(nums) == 1:
        return 1

    while start < end:
        sub_array.add(nums)

def solution_lc(nums: List[int]) -> int:
    res = 0
    cnt = {}
    n = len(nums)
    right = 0
    distinct = len(set(nums))

    for left in range(n):
        if left > 0:
            remove = nums[left - 1]
            cnt[remove] -= 1

            if cnt[remove] == 0:
                cnt.pop(remove)

        while right < n and len(cnt) < distinct:
            add = nums[right]
            cnt[add] = cnt.get(add, 0) + 1
            right += 1

        if len(cnt) == distinct:
            res += n - right + 1

    return res


def main():
    pass

if __name__ == '__main__':
    main()