from typing import List

def build_array(nums: List[int]) -> List[int]:
    ans = []

    for i in range(len(nums)):
        ans.append(nums[nums[i]])

    return ans

def main():
    nums = [0,2,1,5,3,4]
    sol = build_array(nums)
    print(sol)

if __name__ == '__main__':
    main()