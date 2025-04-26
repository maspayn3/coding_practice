from typing import List

def split_and_sum_digits(x: int) -> int:
    sum = 0
    x_str = str(x)

    for digit in x_str:
        digit = int(digit)
        sum += digit

    return sum

def count_largest_group(n: int) -> int:
    digit_sums = {}
    
    # n + 1 to include n
    for i in range(1, n + 1):
        sum = split_and_sum_digits(i)

        digit_sums[sum] = digit_sums.get(sum, 0) + 1


    curr_max = 0
    num_largest_groups = 0
    for value in digit_sums.values():
        if value > curr_max:
            curr_max = value
            num_largest_groups = 1

        elif value == curr_max:
            num_largest_groups += 1
    
    return num_largest_groups



def main():
    print(count_largest_group(13))



if __name__ == '__main__':
    main()