def count_symmetric_integers(low: int, high: int) -> int:
    res = 0
    for num in range(low, high + 1):
        num_string = str(num)
        N = len(num_string)

        if  N % 2 == 0:
            slice_index = (N // 2)
            first_half = num_string[:slice_index]
            second_half = num_string[slice_index:]

            first_sum = 0
            for digit in first_half:
                first_sum += int(digit)

            second_sum = 0
            for digit in second_half:
                second_sum += int(digit)

            if first_sum == second_sum: 
                res += 1

    return res   


def main():
    res = count_symmetric_integers(1, 100)
    print(res)


if __name__ == '__main__':
    main()