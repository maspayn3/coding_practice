from typing import List

def is_subsequence(s: str, t: str):
    s_ptr = 0
    if len(s) == 0:
        return True

    # move s_ptr once we reach the respective char from s
    # in t
    for i in range(len(t)):
        if s[s_ptr] == t[i]:
            s_ptr += 1

        if s_ptr == len(s):
            return True
    return False

def main():
    pass

if __name__ == '__main__':
    main()