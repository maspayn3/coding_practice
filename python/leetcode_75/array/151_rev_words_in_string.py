
# Time: O(n)
# Space: O(1)
def reverse_words(s: str):
    string_list = s.split()
    rev_string = string_list[::-1]
    return " ".join(rev_string)

# intended method, as it works for most coding languages
# and does not rely on standard Python operations
def reverse_words_two_pointers(s: str):
    string_list = s.split()

    start = 0
    end = len(string_list) - 1

    while start < end:
        temp = string_list[start]
        string_list[start] = string_list[end]
        string_list[end] = temp

        end -= 1
        start += 1

    return " ".join(string_list)

def main():
    s = "the sky is blue"
    print(reverse_words_two_pointers(s))

if __name__ == '__main__':
    main()