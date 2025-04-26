from typing import List


# NOT INTENDED: NOT SUPPOSED TO USE DIVISION
def product_except_self(nums: List[int]):
    prefix_product = 1
    answers = []
    zero_count = 0
    zero_index = None

    for i in range(len(nums)):
        if nums[i] == 0:
            zero_count += 1
            zero_index = i
        else:
            prefix_product *= nums[i]


    if zero_count == 1:
        answers = [0] * len(nums)
        answers[zero_index] = prefix_product

    elif zero_count > 1:
        answers = [0] * len(nums)
    else:
        for j in range(len(nums)):
            product = prefix_product // nums[j]
            answers.append(product)

    return answers

def calculate_left_product_array(nums: List[int]):
    curr_product = 1
    res = []
    for i in range(len(nums)):
        res.append(curr_product)
        curr_product *= nums[i]

    return res
        

def product_except_self_no_division(nums: List[int]):
    # need an array to track the left products of i
    # make an array where nums[i] is the product of all 
    # elements nums[i - 1]

    left_product_array = calculate_left_product_array(nums)
    
    # now with the left products, we can iterate backwards and 
    # build up the right_product as we go
    curr_product = 1
    for i in range(len(nums) - 1, -1, -1):
        left_product = left_product_array[i]
        product = curr_product * left_product

        curr_product *= nums[i]

        nums[i] = product

    return nums



def main():
    nums = [1, 2, 3, 4, 5]
    print(product_except_self_no_division(nums))

if __name__ == '__main__':
    main()