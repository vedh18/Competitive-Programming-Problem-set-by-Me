# MaxOr Subarray

Given an array of N integers, and an index q, find the number of elements in the smallest subarray containing the index i which has the maximum possible OR.

## Input Format:

The first line of each test case contains 2 numbers, N (0<=N<=1e5) and Q (0<=Q<=1e5), the number of elements in the array and the total number of queries to be answered.

The next Q lines contain one index each (based on 0 indexing)

## Output Format:
For each of the queries output the corresponding answer.

### Sample Input Output

#### Input
5 5

1 2 3 4 5

0

1

2

3

4


#### Output

4

3

2

2

3


The max OR posible is 7 which is achieved in the following ways for the given queries:

1 | 2 | 3 | 4 

2 | 3 | 4

3 | 4 

3 | 4

3 | 4 | 5


