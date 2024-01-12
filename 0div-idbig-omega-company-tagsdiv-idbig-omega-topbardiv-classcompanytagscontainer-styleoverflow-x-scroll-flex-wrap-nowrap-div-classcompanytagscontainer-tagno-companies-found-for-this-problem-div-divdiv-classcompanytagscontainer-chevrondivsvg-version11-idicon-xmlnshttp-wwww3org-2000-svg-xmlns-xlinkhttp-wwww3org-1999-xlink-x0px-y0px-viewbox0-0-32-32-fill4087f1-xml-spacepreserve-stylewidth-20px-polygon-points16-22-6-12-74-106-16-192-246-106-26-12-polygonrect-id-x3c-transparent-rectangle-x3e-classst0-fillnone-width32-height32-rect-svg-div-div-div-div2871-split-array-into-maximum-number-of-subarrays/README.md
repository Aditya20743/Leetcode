<h2><a href="https://leetcode.com/problems/split-array-into-maximum-number-of-subarrays/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2871. Split Array Into Maximum Number of Subarrays</a></h2><h3>Medium</h3><hr><div><p>You are given an array <code>nums</code> consisting of <strong>non-negative</strong> integers.</p>

<p>We define the score of subarray <code>nums[l..r]</code> such that <code>l &lt;= r</code> as <code>nums[l] AND nums[l + 1] AND ... AND nums[r]</code> where <strong>AND</strong> is the bitwise <code>AND</code> operation.</p>

<p>Consider splitting the array into one or more subarrays such that the following conditions are satisfied:</p>

<ul>
	<li><strong>E</strong><strong>ach</strong> element of the array belongs to <strong>exactly</strong> one subarray.</li>
	<li>The sum of scores of the subarrays is the <strong>minimum</strong> possible.</li>
</ul>

<p>Return <em>the <strong>maximum</strong> number of subarrays in a split that satisfies the conditions above.</em></p>

<p>A <strong>subarray</strong> is a contiguous part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [1,0,2,0,1,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> We can split the array into the following subarrays:
- [1,0]. The score of this subarray is 1 AND 0 = 0.
- [2,0]. The score of this subarray is 2 AND 0 = 0.
- [1,2]. The score of this subarray is 1 AND 2 = 0.
The sum of scores is 0 + 0 + 0 = 0, which is the minimum possible score that we can obtain.
It can be shown that we cannot split the array into more than 3 subarrays with a total score of 0. So we return 3.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5,7,1,3]
<strong>Output:</strong> 1
<strong>Explanation:</strong> We can split the array into one subarray: [5,7,1,3] with a score of 1, which is the minimum possible score that we can obtain.
It can be shown that we cannot split the array into more than 1 subarray with a total score of 1. So we return 1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>6</sup></code></li>
</ul>
</div>