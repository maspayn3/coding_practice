from typing import List

def can_place_flowers(flowerbed: List, n: int) -> bool:
    prev = 0
    for i in range(len(flowerbed)):
        if flowerbed[i] == 1 and prev == 1:
            n += 1
            continue

        if flowerbed[i] == 0 and prev == 0 and n != 0:
            prev = 1
            n -= 1

        elif flowerbed[i] == 1:
            prev = 1

        else: 
            prev = 0

    if n == 0:
        return True
    return False


def can_place_flowers_clean(flowerbed, n):
    if n == 0:
        return True
    
    for i in range(len(flowerbed)):
        if flowerbed[i] == 0 and (i == 0 or flowerbed[i-1] == 0) and (i == len(flowerbed) - 1 or flowerbed[i + 1] == 0):
            flowerbed[i] = 1
            n -= 1
            
            if n == 0:
                return True
    return False


def main():
    flowerbed = [0,0,1,0,0]
    n = 1

    print(can_place_flowers(flowerbed, n))
     

if __name__ == '__main__':
    main()