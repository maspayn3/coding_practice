from typing import List

def subset_xor_sum(nums: List[int]):
    def dfs(i, total):
        if i == len(nums):
            return total
        
        dfs(i + 1, total ^ nums[i])  + dfs(i + 1, total) 

    return dfs(0, 0)

def main():
    nums = [5,1,6]
    subset_xor_sum(nums)

if __name__ == '__main__':
    main()