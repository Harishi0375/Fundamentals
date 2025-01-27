from typing import List, Tuple

def longest_ordered_subarray(arr):
    n = len(arr)
    dp = [1] * n
    # previndex array to help reconstruct
    prev = [-1] * n
    
    for i in range(1, n):
        for j in range(i):
            if arr[j] < arr[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                prev[i] = j
    
    # find index of max in dp
    max_index = max(range(n), key=lambda i: dp[i])
    # reconstruct longest ordered subarray
    longest_subarray = []
    while max_index != -1:
        longest_subarray.append(arr[max_index])
        max_index = prev[max_index]
    
    longest_subarray.reverse()
    
    return longest_subarray


'''
12.2 b

The general time complexity of this algorithm would be O(height * width)
this is because for initing the array we need an H * W matrix to store the result
and we need to itter through each value in the tree as seen in the nested for loop
because this is asymptotic we get rid of the constants and are left with O(height * width)
'''
def sum_in_triangle(triangle: List[List[int]]) -> Tuple[int, List[int]]:
    if not triangle:
        return 0, []

    n = len(triangle)
    dp = [[0] * len(row) for row in triangle]
    dp[0][0] = triangle[0][0]
    
    for i in range(1, n):
        for j in range(len(triangle[i])):
            left_above = dp[i-1][j-1] if j > 0 else float('-inf')
            directly_above = dp[i-1][j] if j < len(triangle[i-1]) else float('-inf')
            dp[i][j] = max(left_above, directly_above) + triangle[i][j]
    
    # find max in last row
    max_sum = max(dp[-1])
    max_index = dp[-1].index(max_sum)
    
    # reconstruct the path
    path = []
    for i in range(n-1, -1, -1):
        path.append(triangle[i][max_index])
        # determine the next index to trace back to
        if i > 0:  
            if max_index > 0 and dp[i-1][max_index-1] + triangle[i][max_index] == dp[i][max_index]:
                max_index -= 1

    path.reverse()
    return max_sum, path