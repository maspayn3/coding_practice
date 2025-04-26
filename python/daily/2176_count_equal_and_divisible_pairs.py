def count_pairs_bf(nums, k):
    res = 0

    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):

            if nums[i] == nums[j] and (i * j) % k == 0:
                res += 1 
    
    return res

def main():
    print("Result:", count_pairs_bf([1,2,3,4], 1))

if __name__ == '__main__':
    main()