import heapq

def findDisappearedNumbers(nums):
    """
    My solution: build perfect list of nums [1, 2, ..., n]
    Turn nums into set() and iterate over perfect list, adding 
    missing elements to missing_numbers list as we go

    Complexity: O(n) Time
                O(n) Space

    Returns: missing_numbers -> list of missing numbers in nums
    """
    missing_numbers = []

    nums_set = set(nums)
    perfect_list = range(1, len(nums) + 1, 1)

    for num in perfect_list:
        if num not in nums_set:
            missing_numbers.append(num)

    return missing_numbers
    

def main():
    findDisappearedNumbers([4,3,2,7,8,2,3,1])

if __name__ == '__main__':
    main()