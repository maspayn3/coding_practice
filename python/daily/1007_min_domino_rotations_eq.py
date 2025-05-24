from typing import List
from collections import Counter

def min_domino_rotations(tops: List[int], bottoms: List[int]) -> int:

    # Idea can be to store the counts of the values found in tops and bottoms
    
    counts_top = Counter(tops)
    counts_bottom = Counter(bottoms)

    # Union operator
    counts_total = counts_top | counts_bottom

    is_equal_row = False
    target = None
    for val, freq in counts_total.items():
        if freq == len(tops):
            is_equal_row = True
            target = val 

    if not is_equal_row:
        return -1
    
    return abs(counts_top[target] - counts_bottom[target])


def main():
    pass


if __name__ == '__main__':
    main()