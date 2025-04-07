from typing import List

def largest_divisible_subset_bf(nums: List[int]) -> List[int]:

    # sort first
    # keep track of current index and the previous num added to res

    nums.sort()
    cache = {}

    def dfs(i, prev):
        if i == len(nums):
            return []
        
        if (i, prev) in cache:
            return cache[(i, prev)]
        
        res = dfs(i + 1, prev) # don't include
        if nums[i] % prev == 0:
            tmp = [nums[i]] + dfs(i + 1, nums[i]) # include 
            res = tmp if len(tmp) > len(res) else res

        cache[(i, prev)] = res
        return res
    
    return dfs(0, 1)


    





def main():
    pass

if __name__ == '__main__':
    main()