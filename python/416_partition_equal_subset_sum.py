from typing import List

# not fast enough to pass test cases, no cache
def can_partition_bf(nums: List[int]) -> bool:
    nums_sum = sum(nums)

    def dfs(i, subset_sum=0, target=nums_sum):
        if subset_sum == target:
            return True

        if (i >= len(nums)):
            return False
        
        # include nums[i] or skip nums[i]
        return dfs(i + 1,  subset_sum + nums[i], target - nums[i]) or dfs(i + 1, subset_sum, target)
        
    return dfs(0)
        
def can_partition_optimal(nums: List[int]) -> bool:
    if sum(nums) % 2: 
        return False
    
    dp = set()
    dp.add(0)
    target = sum(nums) // 2

    for i in range(len(nums) - 1, -1, -1):
        nextDP = set()
        for t in dp:
            if (t + nums[i]) == target:
                return True
            nextDP.add(t + nums[i])
            nextDP.add(t)
        dp =  nextDP
    return True if target in dp else False

def main():
    print(can_partition_optimal([1,5,11,5]))

if __name__ == '__main__':
    main()