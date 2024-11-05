import heapq

def missingNumber(nums) -> int:
    """
    My solution: O(n)
    - find sum of series 0 + 1 + 2 + ... + n
    - compute and return difference of nums sum and perfect sum
    """
    perfect_sum = sum(range(len(nums) + 1))
    real_sum = 0

    for num in nums:
        real_sum += num

    difference = perfect_sum - real_sum
    return difference


def main():
    missingNumber([3,0,1])

if __name__ == '__main__':
    main()