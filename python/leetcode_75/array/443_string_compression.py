from typing import List
from collections import deque

# Time: O(n)
# Space: O(1)
def compress(chars: List[str]) -> int:
    res = 0
    num_chars = len(chars)
    curr_group_size = 1
    i = 0

    while i < num_chars:
        curr_char = chars[i]
        j = i + 1

        while j < len(chars) and chars[j] == curr_char:
            curr_group_size += 1
            j += 1
            
        if curr_group_size > 1:
            if curr_group_size > 9: 
                char_str = str(curr_group_size)
                for k in range(len(char_str)):
                    chars[res + 1 + k] = char_str[k]

                chars[res] = curr_char
                res += len(char_str) + 1

            else: 
                chars[res] = curr_char
                chars[res + 1] = str(curr_group_size)
                res += 2
        else:
            chars[res] = curr_char
            res += 1

        curr_group_size = 1
        i = j

    return res

def compress_lc_solution(chars: List[str]):
    i = 0
    res = 0
    while i < len(chars):
        group_length = 1
        while (i + group_length < len(chars) 
               and chars[i + group_length] == chars[i]):
            group_length += 1

        chars[res] = chars[i]
        res += 1

        if group_length > 1:
            #  way cleaner and more pythonic way to handle the lengths
            str_repr = str(group_length)
            # can just swap a range of a list, crazy!!
            chars[res:res+len(str_repr)] = list(str_repr)
            res += len(str_repr)
        i += group_length
    return res

def main():
    chars = ["a","a","a","a","a","b"]
    print(compress(chars))

if __name__ == '__main__':
    main()