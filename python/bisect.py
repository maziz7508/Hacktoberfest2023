# Library usage --. Instead of binary search
from bisect import bisect_left, bisect_right

# Returns the leftmost insertion point for val in sorted list
bisect_left(arr,val)

# Returns rightmost insertion point of x in a sorted list
bisect_right(arr,val)