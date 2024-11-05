# Variables are dynamically typed
n = 0
print('n =', n)

n = "abc"
print('n =', n)

# multiple assignments
n, m = 0, "abc"

n, m, z = 0.125, "abc", False

# Increment
# good
n = n + 1  

# good
n += 1

#bad 
# n++ interpreter error

# None is null (absence of value)
n = None

# If statements don't need parentheses
# or curly braces
n = 1
if n > 2:
    n -= 1
elif n == 1:
    n *= 2
else:
    n += 2

#  Parentheses needed for multi-line condiations
#  and = &&
#  or = ||
n, m = 1, 2
if ((n > 2 and 
     n != m) or n == m):
    n += 1


# while loops are similar
n = 0
while n < 5:
    print(n)
    n += 1

# Looping from i = 0 to i = 4
for i in range(5):
    print(i)

start = 0
stop = 6
step = 5
range(stop), range(start, stop), range(start, stop, step)
# memory efficient due to not storing all the numbers in memory at once
# returns: a range object
#               -> immutable sequence type
#               -> can be converted into a list
#               -> List: stores all its elements in memory at once
#               -> Range: generates values on the fly, less memory
#               -> cannot be changed after creation

# Starts with start, and goes up until but not including stop
# start is by default 0
# step can be negative

# looping from i = 5 to i = 2
for i in range(5, 1, -1):
    print(i)

# Diviision is decimal by default (uncommon)
# most languages round towrds zero
print(5 / 2) # prints 2.5

# Double slash rounds down 
print(5 // 2)

# CAREFUL: most languages round towards 0
# by default so negative numbrs will round down
print(-3 // 2)


# WORKAROUND: use decimal division and convert to int
print(int(-3 / 2))

# Modding is similar to most lanuages 
print(10 % 3)

# Except for negative values
print(-10 % 3) # prints 2?

# Workaround
import math
print(math.fmod(-10, 3)) # prints -1.0

# more math helpers
print(math.floor(3 / 2))
print(math.ceil(3 / 2))
print(math.sqrt(2))
print(math.pow(2, 3))

# When you want a max/min value
float("inf")
float("-inf")

# Python numbres are infinite so they never overflow
print(math.pow(2, 200))

# Arrays (called lists in python) are dynamic by default
arr = [1, 2, 3]
print(arr)

arr.append(4)
arr.append(5)
print(arr)

arr.pop()
print(arr)

arr.insert(1, 7) # O(n) time operation
print(arr)

# [] are O(1)

#  Initialize arr of size n with default value of 1
n = 5
arr = [1] * n
print(len(arr))

# can use negative indices
arr = [1, 2, 3]
print(arr[-1]) # gets last element

# Sublists (aka slicing)
# last index in non-inclusive
arr = [1, 2, 3, 4]
print(arr[1:3]) # prints [2, 3]

nums = [1, 2, 3]
# looping through arrays
for i in range(len(nums)):
    print(nums[i])


# without index
for n in nums:
    print(n)

# with index and value
for i, n in enumerate(nums):
    print(i, n)

# loop through multiple arrays simultaneously
nums1 = [1, 3, 5]
nums2 = [2, 4, 6]

for n1, n2, in zip(nums1, nums2):
    print(n1, n2)

# reverse
nums = [1, 2, 3]
nums = nums.reverse()
print(nums)

# Sorting, by default does ascending order
arr = [5, 4, 7, 3, 8]
arr.sort()
print(arr)

# can sort to descending order
arr.sort(reverse=True)
print(arr)

# sort list of strings alphabetical
arr = ["bob", "alice", "jane", "does"]
arr.sort()
print(arr)

# Custom sort (by length of string)
arr.sort(key=lambda x: len(x))
print(arr)

# List comprehension
arr = [i for i in range(5)]
print(arr)

# 2-D lists
arr = [[0] * 4 for i in range(4)]

# this wont work for 2-d lists
arr = [[0] * 4] * 4

# creates a shallow copy problem where all 4 rows are the same row 
# thus any chagnes to row 0 change all the rows and so forth

# strings are similar to arrays
s = "abc"
print(s[0:2])

# Strings are immutable (cannot be changed after creation)
# but they can be added to

s += "def" # this creates a new string however, inefficient O(n)
print(s)

# This works as expected
print(int("123") + int("123")) # -> 246
print(str(123) + str(123)) # -> "123123"

# ASCI value of character
print(ord("a"))

# Combine list of strings (with empty string delimitor 
# -> way more efficient appending 
strings = ["ab", "cd", "ef"]
print("".join(strings)) # -> abcdef


from collections import deque
# Queues (double ended queue)
queue = deque()
queue.append(1)
queue.append(2)
print(queue)

queue.popleft(1)
print(queue)

# pops the right side
queue.pop()
print(queue)


# Hash Sets
# allow for O(1) adding and O(1) searching
my_set = set()
my_set.add(1)


# checking for membership
print(1 in my_set)
print(2 in my_set)

# can remove values in comstant time too
my_set.remove(1)
print(1 in my_set)

# list to set
print(set([1, 2, 3]))

# set comprehension
my_set = {i for i in range(5)}


# Hash map (aka dict)
my_map = {}

my_map["alice"] = 88
my_map["bob"] = 77

# check size of map
print(len(my_map))

# check for membership
print("alice" in my_map)
my_map.pop("alice")

my_map = {"alice": 90, "bob": 70}

# Dict comprehension
my_map = {i: 2 * i for i in range(3)}

# looping through maps
my_map = {"alice": 90, "bob": 70}
for key in my_map:
    print(key, my_map[key])

for val in my_map.values():
    print(val)

for key, val in my_map.items():
    print(key, val)


# Tuples are like arrays by immutable (can't modify)
tup = (1, 2, 3)

# lists are not hashable and therefore cannot be keys to maps
# so tuples are very useful for this

# Heaps
import heapq

min_heap = []

heapq.heappush(min_heap, 3)
heapq.heappush(min_heap, 2)
heapq.heappush(min_heap, 5)

print(min_heap[0])

while len(min_heap):
    print(heapq.heappop(min_heap))

# no max heaps but..
# WORKAROUND: use min heap and multiply by -1 when push and pop

max_heap = []

heapq.heappush(min_heap, -3)
heapq.heappush(min_heap, -2)
heapq.heappush(min_heap, -6)

# max is always at index 0
print(-1 * max_heap)

# build heap from initial values
arr = [2, 1, 8, 4, 5]
heapq.heapify(arr)

while arr:
    print(heapq.heappop(arr))


# functions
def my_func(n, m):
    return n * m

# nested functions have access to outer variables

def outer(a, b):
    c = "c"

    def inner():
        return a + b + c
    return inner()

print(outer("a", "b"))

# can modify objects but not reassign value
# unless nonlocal value

# class

class MyClass:
    # Constructor
    def __init__(self, nums):
        pass

    def get_length(self):
        return self.size
    
    def get_double_length(self):
        return 2 * self.get_double_length()