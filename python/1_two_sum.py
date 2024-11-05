import heapq

def twoSum(nums, target):
    nums_needed = {}
    result = []

    for i, num in enumerate(nums):
        if target - num in nums_needed:
            result.append(i)
            result.append(nums_needed[target - num])
            return result
            
        if num not in nums_needed:
            nums_needed[num] = i



def main():
    twoSum([3,2,4],  6)

if __name__ == '__main__':
    main()