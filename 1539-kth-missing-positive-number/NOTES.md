ans = arr[hi] + more (since hi stops at the prev index between the two in which ans it to be found)
​
ans = arr[hi] + (k - missing)
​
missing = arr[hi] - (hi + 1)
​
using these equations we get, ans = k + lo