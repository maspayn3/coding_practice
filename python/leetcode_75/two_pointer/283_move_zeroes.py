from typing import List


# first is the slow pointer
# i is the fast pointer
def move_zeroes(nums: List[int]) -> None: 
    first = 0

    if len(nums) == 1:
        return

    for i in range(len(nums)):
        if nums[i] != 0:
            nums[first] = nums[i]
            first += 1

    # now fill rest of array with zeroes
    for j in range(first, len(nums)):
        nums[j] = 0
 
def main():
    print(move_zeroes([0,1,0,3,12]))

if __name__ == '__main__':
    main()