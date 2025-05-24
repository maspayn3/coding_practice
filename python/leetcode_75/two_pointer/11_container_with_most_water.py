from typing import List

def max_area(height: List[int]) -> int:
    max_area = -1
    curr_area = 0

    left = 0
    right = len(height) - 1

    while left < right:
        min_height = min(height[left], height[right])
        width = right - left

        curr_area = width * min_height
        if max_area < curr_area:
            max_area = curr_area


        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_area



def main():
    print(max_area([1,8,6,2,5,4,8,3,7]))

if __name__ == '__main__':
    main()