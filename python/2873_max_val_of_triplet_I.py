# note: I believe k should always be the largest number
# IDEAS:
#   Brute Force: Calculate all possible triplet values and return largest
#       - 3 nested loops

def max_triplet_value_bf(nums):
    max_value = 0
    for i, i_val in enumerate(nums):
        for j, j_val  in enumerate(nums[i + 1:], start=i+1):
            for k, k_val in enumerate(nums[j + 1:], start=j+1):
                
                value = (i_val - j_val) * k_val
                if value > max_value:
                    max_value = value
    
    return max_value

# not good enough for ordered triplet II
def max_triplet_value_greedy(nums):
    res = 0
    N = len(nums)
    left = nums[0]
    for j in range(1, N):
        if nums[j] > left:
            left = nums[j]
        for k in range(j + 1, N):
            res = max(res, (left - nums[j])* nums[k])
    return res

# O(n)
def max_triplet_value_II(nums):
    max_diff = 0
    prefix_max = 0
    res = 0

    prefix_max = nums[0]
    for k in range(1, len(nums)):
        temp = max_diff * nums[k]

        if temp > res:
            res = temp

        if nums[k] > prefix_max:
            prefix_max = nums[k]
        
        diff = prefix_max - nums[k]

        if diff > max_diff:
            max_diff = diff

    return res

def main():
    print(max_triplet_value_bf([12,6,1,2,7]))
    print(max_triplet_value_greedy([12,6,1,2,7]))
    print(max_triplet_value_II([12,6,21,20,20]))


if __name__ == '__main__':
    main()