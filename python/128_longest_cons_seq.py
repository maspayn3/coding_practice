import heapq


# this was my immediate solution
# not optimal
# despite the heap it still sorts
# so uses O(nlogn) ?
def longestConsecutive(nums) -> int:
    if not nums:
        return 0
    
    nums = list(set(nums))
    heapq.heapify(nums)

    # Keep track if we are in a sequence currently while popping top element
    curr_longest_seq = 1
    max_longest_seq = 0
    prev_num = heapq.heappop(nums)
    while nums:
        curr_num = heapq.heappop(nums)

        if curr_num == prev_num + 1:
            curr_longest_seq += 1
        else:
            curr_longest_seq = 1

        max_longest_seq = max(max_longest_seq, curr_longest_seq)
        prev_num = curr_num

    return max_longest_seq


# More optimal idea
# convert list into a set to check membership
def longest_consecutive_optimal(nums):
    nums_set = set(nums)
    max_seq_len = 0

    for num in nums:
        if (num - 1) not in nums_set:
            curr_seq_len = 0
            while (num + curr_seq_len) in nums_set:
                curr_seq_len += 1
            max_seq_len = max(max_seq_len, curr_seq_len)
    
    return max_seq_len



def main():
    nums = [0,3,7,2,5,8,4,6,0,1]
    print(longestConsecutive(nums))

if __name__ == '__main__':
    main()