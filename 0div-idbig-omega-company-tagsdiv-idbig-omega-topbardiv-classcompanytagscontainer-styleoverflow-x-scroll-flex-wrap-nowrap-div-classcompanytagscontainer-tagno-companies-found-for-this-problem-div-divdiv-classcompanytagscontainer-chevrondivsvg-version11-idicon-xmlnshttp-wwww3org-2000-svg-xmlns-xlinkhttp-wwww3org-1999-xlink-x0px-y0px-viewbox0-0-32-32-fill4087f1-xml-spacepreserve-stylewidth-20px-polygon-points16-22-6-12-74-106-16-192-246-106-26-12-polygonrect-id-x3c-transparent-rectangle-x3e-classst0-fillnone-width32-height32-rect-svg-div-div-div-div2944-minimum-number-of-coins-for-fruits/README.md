<h2><a href="https://leetcode.com/problems/minimum-number-of-coins-for-fruits/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag">No companies found for this problem</div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>2944. Minimum Number of Coins for Fruits</a></h2><h3>Medium</h3><hr><div><p>You are at a fruit market with different types of exotic fruits on display.</p>

<p>You are given a <strong>1-indexed</strong> array <code>prices</code>, where <code>prices[i]</code> denotes the number of coins needed to purchase the <code>i<sup>th</sup></code> fruit.</p>

<p>The fruit market has the following offer:</p>

<ul>
	<li>If you purchase the <code>i<sup>th</sup></code> fruit at <code>prices[i]</code> coins, you can get the next <code>i</code> fruits for free.</li>
</ul>

<p><strong>Note</strong> that even if you <strong>can</strong> take fruit <code>j</code> for free, you can still purchase it for <code>prices[j]</code> coins to receive a new offer.</p>

<p>Return <em>the <strong>minimum</strong> number of coins needed to acquire all the fruits</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> prices = [3,1,2]
<strong>Output:</strong> 4
<strong>Explanation:</strong> You can acquire the fruits as follows:
- Purchase the 1<sup>st</sup> fruit with 3 coins, you are allowed to take the 2<sup>nd</sup> fruit for free.
- Purchase the 2<sup>nd</sup> fruit with 1 coin, you are allowed to take the 3<sup>rd</sup> fruit for free.
- Take the 3<sup>rd</sup> fruit for free.
Note that even though you were allowed to take the 2<sup>nd</sup> fruit for free, you purchased it because it is more optimal.
It can be proven that 4 is the minimum number of coins needed to acquire all the fruits.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> prices = [1,10,1,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> You can acquire the fruits as follows:
- Purchase the 1<sup>st</sup> fruit with 1 coin, you are allowed to take the 2<sup>nd</sup> fruit for free.
- Take the 2<sup>nd</sup> fruit for free.
- Purchase the 3<sup>rd</sup> fruit for 1 coin, you are allowed to take the 4<sup>th</sup> fruit for free.
- Take the 4<sup>t</sup><sup>h</sup> fruit for free.
It can be proven that 2 is the minimum number of coins needed to acquire all the fruits.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= prices.length &lt;= 1000</code></li>
	<li><code>1 &lt;= prices[i] &lt;= 10<sup>5</sup></code></li>
</ul>
</div>