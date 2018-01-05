# LintCode题解
### 464整数排序
1. 这道题和49字符大小写排序那道题很一样，可以分别使用快排和归并排序
2. 对于快排，要熟练掌握２路排序和３路排序，在后面的题中会用到。
### 31数组划分
1. 整数ｋ不一定是数组中的元素
2. 因为这道题并没有说完全按照　<k =k >k的顺序，所以我们可以使用２路排序将其排列为<k >=k的元素即可
### 5第K大元素
1. 概念问题,第ｋ大元素实际上是从小到大排的话，那就是第ｎ-k+1名元素了
2. 快排求解，对于后面的逆序对用归并求解，这是常见的两个思路
3.　还有一个问题就是在partition后的partition的过程中，ｋ是不变的，不会变成k-p，因为partition传入的索引一直是原数组中的索引。
### 148颜色分类
1. 这道题要注意的是partition需要严格分<1 =1 >1三种，因此需要三路排序
2. 使用三个索引 lt, i, gt，使得[l,lt] <1 (lt+1,i)=1 [gt,r)>1
### 387最小差
1. 遍历A中每个元素，然后二分法在B中查找与该元素最接近的元素。
2. 在二分法查找的过程中，对于A[mid]元素要特别注意，当根据mid分区间的过程时，如果A[mid]!=该元素，那么就需要将smallest与mid这个元素与该元素差值进行比较更新，以防止在mid两边的区间中找不到该元素的情况。
### 57三数之和
1. 首先对数组按从小到大顺序排序，然后锁定两个数i,j之后，只需要考虑j之后的部分（因为数组有序，所以能与i和j组成0的已经在之前考虑过了。
2. 在j之后进行二分法搜索确定第三个数
3. 去重问题，题中要求不能重复，所以对于(a,b,c)这个三元组来说，若遍历到的i，j与前一个元素相等那么必定是重复的，跳过即可。
4. 参考文献：[两数和、三数和、四数和](https://www.cnblogs.com/eudiwffe/p/6282635.html)
### 59最接近的三数之和
1. 这道题和上面那道挺像的，但是不需要去重了。
2. 在二分搜索是我借鉴了**387题最小差**的思路。
3. 目前时间复杂度是`$O(n^2logn)$`。
### 173链表插入排序
1. 还是插入排序的思路，但是和数组不同的是，在链表中，因为我们不知道该元素的上一个元素指针，所以我们只能从前向后比较
2. 注意边界问题，尤其是最开始的while循环
### 156合并区间
1. 先对数组排序，然后从1到n-1个元素开始循环合并区间，这个过程中要注意不断更新end的值
2. 由于是到n-1，所以第n个元素会无法正确比较，最后结果可能是一个空集，所以我们在对排序后的数组的最后加入一个（INT_MAX，INT_MAX）区间。
### 139最接近零的子数组和
1. 这里只需要给出一组结果即可。
2. 依次遍历数组A，将从0到第i个数的和保存到B中并排序，这样任意B中两个元素相减都是A中的一个子数组和，进而寻找最接近0的。
### 463整数排序
1. 这里我使用了插入排序
2. 可以进行一下优化，比如对于swap来说，可以只进行一次，在while过程中找到那个没有排好序的索引，将之前的内容往后移，然后将最后一个元素插入到这里。
### 143拍颜色II
1. 用排序是完全行得通的，只不过时间复杂度高了些
2. 直接遍历数组然后统计每个颜色的种类，然后按序输出即可。
3. 空间复杂度是O(K),需要优化
### 547两数组的交
1. 哈哈，这道题RTKLIB中也有用到在nextobsf函数中应该
2. 思路很简单就是先对数组排序，然后如果相等就加进去，如果不等，就看看谁大谁小，把小的索引+1，大的索引不动。
3. 注意去重。
### 6合并排序数组
1. 就是归并排序的merge
2. 可以优化（不会。。。）
### [39恢复旋转排序数组](http://www.lintcode.com/zh-cn/problem/recover-rotated-sorted-array/)
1. 最暴力的思路就是找出旋转基rotate，然后拷贝一个新数组，然后拷贝。
2. 参考了别人的思路，旋转，从[0,rotate] 和 [rotata,n] 和 [0,n]旋转三次即可。
### [41最大子数组](http://www.lintcode.com/zh-cn/problem/maximum-subarray/)
1. 使用两个变量max和d，max保存的是到当前遍历的地方为止最大的子数组之和，对于d来说就是保存的从某个位置开始的子数组之和，当这个d小于0的时候，不管下一个数是正是负，这个d都会“拖累”下一个数，所以直接舍弃。
2. 实际上这里的每一步的max都是到当前i为止的一个局部最大值。
### [42最大子数组II](http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/)
1. 利用41最大子数组中的第二点，前后遍历两次，分别将到i前后最大值分别存在两个数组中
2. 对最后的结果进行一次遍历，找出最大值即可。
### [44最小子数组](http://www.lintcode.com/zh-cn/problem/minimum-subarray/)
1. 和41最大子数组思路完全一样。
### [45最大子数组差](http://www.lintcode.com/zh-cn/problem/maximum-subarray-difference/)
1. 和42最大子数组II思路一样
2. 要注意不一定是左边数组最大而右边数组最小，结果可能在反过来的情况中，所以要都考虑到。
### [60搜索插入位置](http://www.lintcode.com/zh-cn/problem/search-insert-position/)
1. 基本思路二分法
2. 二分法并不难，但是关键的地方在于当找不到元素的时候如何正确的返回比target大的最小值的元素。在循环过程中不断的向target逼近。
### [61搜索区间](http://www.lintcode.com/zh-cn/problem/search-for-a-range/)
1. 和60搜索插入位置类似都是二分查找法
2. 要注意的是对于重复元素，这样就只能用60搜索插入位置的版本1来做。
### [62搜索旋转排序数组](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/)
1. 基本思路仍是二分法，只是现在找出mid后，mid可能只有一边有序，另一边无序了，但是我们可以拿有序那边做判断，因为是有序，很容易判断出target在不在，如果不在就直接将范围缩小到另一端。
### [63搜索排序旋转数组II](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array-ii/)
1. 代码同62搜索旋转排序数组一样
### [64合并排序数组II](http://www.lintcode.com/zh-cn/problem/merge-sorted-array/)
1. 直接用的归并排序的merge函数
### [75寻找峰值](http://www.lintcode.com/zh-cn/problem/find-peak-element/)
1. 首先题目要求时间复杂度为o(logn)，因此还是适用二分法
2. 由于题目中确保了至少存在了一个峰值，所以当`A[mid] < A[mid+1]` 时，我们就能得到在mid的右边是至少存在一个峰值的所以可以直接让数组向右走，反过来，让数组直接想左二分即可。
### [100删除排序数组中的重复数字](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array/)
1. 维持两个指针i，j,遍历j，每次当nums[j]!=nums[i]的时候，就表明遇到了一个新的不重复的num，此时赋值给nums[++i]即可。最后i+1就是数组的长度。
### [101删除排序数组中的重复数字 II](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array-ii/)
1. 和上一题一样，只需加一个计数器即可。
### [77最长公共子序列](http://www.lintcode.com/zh-cn/problem/longest-common-subsequence/)
1. 对于两个字符串A{A0,A1,A2,...,Am},B{B0,B1,B2,...Bn},字符串Z{Z0,Z1,Z2,...,Zk}是他们的一个公共子序列，那么有： 
    1. 如果Am=Bn,那么Zk=Am=Bn，而且Zk-1也是Am-1和Bn-1的一个LCS
    2. 如果Am!=Bn，那么Zk!=Am，则Zk是Am-1和Bn的一个LCS
    3. 如果Am!=Bn，那么Zk!=Bn，则Zk是Am和Bn-1的一个LCS
2. 根据1可得到一个递推式：  
<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{cases}&space;0,if\,i=0,\,or\,j&space;=&space;0\\&space;c[i-1,j-1]&plus;1,if&space;i,j>0\,and\,Ai=Bi\\&space;max(c[i,j-1],c[i-1,j])if&space;i,j>0\,and\,Ai\neq&space;Bi\\&space;\end{cases}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{cases}&space;0,if\,i=0,\,or\,j&space;=&space;0\\&space;c[i-1,j-1]&plus;1,if&space;i,j>0\,and\,Ai=Bi\\&space;max(c[i,j-1],c[i-1,j])if&space;i,j>0\,and\,Ai\neq&space;Bi\\&space;\end{cases}" title="\begin{cases} 0,if\,i=0,\,or\,j = 0\\ c[i-1,j-1]+1,if i,j>0\,and\,Ai=Bi\\ max(c[i,j-1],c[i-1,j])if i,j>0\,and\,Ai\neq Bi\\ \end{cases}" /></a>

### [116跳跃游戏](http://www.lintcode.com/zh-cn/problem/jump-game/)
1. 目前用的动态规划，能否跳到最后一个位置也就是dp[n]是否为true，取决于dp[n-1],dp[n-2],...,dp[1]他们是否能跳到，如果能跳到他们的位置，那他们能否跳到最后一个位置，所以我们需要一个dp[n]来保存这些状态
### [124最长连续序列]
1. 题中要求时间复杂度为O(n)，那很容易想到我们需要一个工具来记录。
2. 我们选择map来记录，当我们遇到一个数字时，首先判断在不在map中，若不在map中，那我们就看下这个数字-1 和 +1 在不在，然后分别判断，若在，则说明之前已经记录过他们的长度，那我们跟着这个记录很容易回到这个序列的第一个和最后一个，更新记录即可。