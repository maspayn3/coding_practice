from typing import List


# way too slow
def increasingTriplet_bf(nums: List[int]) -> bool:
    if len(nums) < 3: 
        return False
    
    i, j, k = 0, 1, 2

    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            for k in range(j + 1, len(nums)):
                if nums[i] < nums[j] < nums[k]:
                    return True

    return False

def increasing_triplet(nums: List[int]) -> bool:
    if len(nums) < 3:
        return False
    
    # keep track of first and second value
    # where first < second < third
    # search for third and once it's found return true
    first = float("inf")
    second = float("inf")

    for i in range(len(nums)):
        if nums[i] <= first:
            first = nums[i]
        elif nums[i] <= second:
            second = nums[i]
        else: # first < second < num
            return True
    return False


def main():
    increasing_triplet([1,2,3,4,5])

if __name__ == '__main__':
    main()