def binary_search(arr, target):
  l,r = 0, len(arr)

  while l<=r:
    m = (l+r)//2
    if arr[m] == target:
      return m
    elif arr[m] < target:
      l = m+1
    else:
      r = m-1
  return -1