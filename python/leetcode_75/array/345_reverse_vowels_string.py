def reverse_vowels(s: str) -> str:
    start = 0
    end = len(s) - 1

    s = list(s)
    vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'}

    while start < end:
        if s[start] in vowels and s[end] in vowels:
            temp = s[start]

            s[start] = s[end]
            s[end] = temp

            start += 1
            end -= 1

        elif s[start] in vowels:
            end -= 1
        elif s[end] in vowels:
            start += 1
        else:
            start += 1
            end -= 1

    return ''.join(s)

def main():
    print(reverse_vowels("IceCreAm"))

if __name__ == '__main__':
    main()