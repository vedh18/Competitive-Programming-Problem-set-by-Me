<h1>MaxOr Subarray</h1>
<p>Given an array a of length $n$ and an index $k$, find the number of elements in the smallest subarray containing the index $k$ which has the maximum possible <a href = "https://en.wikipedia.org/wiki/Bitwise_operation#OR">bitwise OR</a></p>
<h2>Input</h2>
<p>The first line of each test case contains two integers $n$ $(1 ≤ n ≤ 10^5)$ and $q$ $(1 ≤ q ≤ 10^5)$ the length of the array and the number of queries to be answered.

The second line contains n integers &ndash;&ndash;&ndash; elements of the array $a$ $(0 ≤ a_i ≤ 10^9)$  where i is the index ${i = 0, 1, 2 .. n-1}$.

Then $q$ lines follow. Each line contains the value of index $k$ for the corresponding query. </p>
<h2>Output</h2>
<p>For each query, output the size of the corresponding subarray.</p>

<div class="sample-tests"><h3 class="section-title">Examples</h3><div class="sample-test"><div class="input"><div class="title">Input</div><pre id="id006097218622379819">5 5
59 85 60 57 72
0
1
2
3
4
</pre></div><div class="output"><div class="title">Output</div><pre id="id006300938261719449">2
2
3
4
5
</pre></div><div class="input"><div class="title">Input</div><pre id="id0008275294803799005">5 2
4 2 1 8 4
3
1
</pre></div><div class="output"><div class="title">Output</div><pre id="id0045611112930186004">4
4
</pre></div></div></div>

