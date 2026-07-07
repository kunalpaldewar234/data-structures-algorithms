# [Smallest sum contiguous subarray](https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1)
## Medium
Given an array arr[]&nbsp;of&nbsp;N&nbsp;integers. Find the contiguous sub-array(containing at least one number) which has the&nbsp;minimum&nbsp;sum and return its sum.
Example 1:
Input: 
arr[] = {3,-4, 2,-3,-1, 7,-5}
Output: -6
Explanation: sub-array which has smallest 
sum among all the sub-array is {-4,2,-3,-1} = -6
Example 2:
Input:
arr[] = {2, 6, 8, 1, 4}
Output: 1
Explanation: sub-array which has smallest
sum among all the sub-array is {1} = 1
Your Task:You don't need to read input or print anything. The task is to complete the function smallestSubarraySum() which takes arr[] and N as input parameters and returns the sum of subarray with minimum sum.
Expected Time Complexity:&nbsp;O(N)Expected Auxiliary Space:&nbsp;O(1)
Constraints:1 ≤ N ≤ 106-107&nbsp;≤ A[i] ≤ 107