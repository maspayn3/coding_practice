def containsDuplicate(nums) -> bool:
    """
    Bad solution O(n^2) check every element against 
    Good solution O(n): build a set and check for membership

    Neat Solution O(n): build a set and check it's length against len(nums)
    
    
    """
    if len(nums) == len(set(nums)):
        return False
    else:
        return True


def main():
    print(containsDuplicate([1,1,1,3,3,4,3,2,4,2]))
    

if __name__ == '__main__':
    main()