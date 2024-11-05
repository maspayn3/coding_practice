

def smallerNumbersThanCurrent(nums):
    """
        My solution: create sorted temp array and enumerate then iterate
        over nums:
        `i` will be used to keep track of number of elements smaller than current
        i should always increment, but we don't add the values to the dictionary
        if they already exist, as they are not smaller than the prev element 

        Complexity: 
            Space: O(n)
            Time: Sorting -> O(nlogn)
                  Iteration -> O(n)

                  total: O(nlogn)

    """
    temp = sorted(nums)
    smaller_counts = {}
    result = []

    for i, num in enumerate(temp):
        if num not in smaller_counts:
            smaller_counts[num] = i

    for num in nums:
        result.append(smaller_counts[num]) 

    return result

def main():
    pass

if __name__ == '__main__':
    main()