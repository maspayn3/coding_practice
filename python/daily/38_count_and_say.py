from typing import List

def count_and_say(n: int):
    res = "1"
    for _ in range(n - 1):
        res = describe(res)
    return res

     
def describe(s: str) -> str:
    result = []
    count = 1

    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            count += 1
        else:
            result.append(f"{count}{s[i - 1]}")
            count = 1

    result.append(f"{count}{s[-1]}")
    return "".join(result)


def main():
    print(count_and_say(3))

if __name__ == '__main__':
    main()