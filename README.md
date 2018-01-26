# LintCode题解

## 数组、排序

### 464.整数排序

1. 这道题和49字符大小写排序那道题很一样，可以分别使用快排和归并排序
2. 对于快排，要熟练掌握2路排序和3路排序，在后面的题中会用到。

### 31.数组划分

1. 整数ｋ不一定是数组中的元素
2. 因为这道题并没有说完全按照　<k =k >k的顺序，所以我们可以使用２路排序将其排列为<k >=k的元素即可

### 5.第K大元素

1. 概念问题,第ｋ大元素实际上是从小到大排的话，那就是第ｎ-k+1名元素了
2. 快排求解，对于后面的逆序对用归并求解，这是常见的两个思路
3.　还有一个问题就是在partition后的partition的过程中，ｋ是不变的，不会变成k-p，因为partition传入的索引一直是原数组中的索引。

### 148.颜色分类

1. 这道题要注意的是partition需要严格分<1 =1 >1三种，因此需要三路排序
2. 使用三个索引 lt, i, gt，使得[l,lt] <1 (lt+1,i)=1 [gt,r)>1

### 387.最小差

1. 遍历A中每个元素，然后二分法在B中查找与该元素最接近的元素。
2. 在二分法查找的过程中，对于A[mid]元素要特别注意，当根据mid分区间的过程时，如果A[mid]!=该元素，那么就需要将smallest与mid这个元素与该元素差值进行比较更新，以防止在mid两边的区间中找不到该元素的情况。

### [608.两数和-输入已排序的数组](http://www.lintcode.com/zh-cn/problem/two-sum-input-array-is-sorted/)

1. 因为这道题已经说数组有序了，所以我们在拿到第一个数之后，得到target-num，然后对剩下的数组进行二分查找，这样时间复杂度为O(nlogn)。
2. 此题也可以那哈希表做，我们将每次的target-num放到map集合中，每次都搜寻一下，搜索到了自然就是最后的结果。

### 57.三数之和

1. 首先对数组按从小到大顺序排序，然后锁定两个数i,j之后，只需要考虑j之后的部分（因为数组有序，所以能与i和j组成0的已经在之前考虑过了。
2. 在j之后进行二分法搜索确定第三个数
3. 去重问题，题中要求不能重复，所以对于(a,b,c)这个三元组来说，若遍历到的i，j与前一个元素相等那么必定是重复的，跳过即可。
4. 参考文献：[两数和、三数和、四数和](https://www.cnblogs.com/eudiwffe/p/6282635.html)

### 59.最接近的三数之和

1. 这道题和上面那道挺像的，但是不需要去重了。
2. 在二分搜索是我借鉴了**387题最小差**的思路。
3. 目前时间复杂度是O(n^2logn)。

### 173.链表插入排序

1. 还是插入排序的思路，但是和数组不同的是，在链表中，因为我们不知道该元素的上一个元素指针，所以我们只能从前向后比较
2. 注意边界问题，尤其是最开始的while循环

### 156.合并区间

1. 先对数组排序，然后从1到n-1个元素开始循环合并区间，这个过程中要注意不断更新end的值
2. 由于是到n-1，所以第n个元素会无法正确比较，最后结果可能是一个空集，所以我们在对排序后的数组的最后加入一个（INT_MAX，INT_MAX）区间。

### 139.最接近零的子数组和

1. 这里只需要给出一组结果即可。
2. 依次遍历数组A，将从0到第i个数的和保存到B中并排序，这样任意B中两个元素相减都是A中的一个子数组和，进而寻找最接近0的。

### 463.整数排序

1. 这里我使用了插入排序
2. 可以进行一下优化，比如对于swap来说，可以只进行一次，在while过程中找到那个没有排好序的索引，将之前的内容往后移，然后将最后一个元素插入到这里。

### 143.拍颜色II

1. 用排序是完全行得通的，只不过时间复杂度高了些
2. 直接遍历数组然后统计每个颜色的种类，然后按序输出即可。
3. 空间复杂度是O(K),需要优化

### 547.两数组的交

1. 哈哈，这道题RTKLIB中也有用到在nextobsf函数中应该
2. 思路很简单就是先对数组排序，然后如果相等就加进去，如果不等，就看看谁大谁小，把小的索引+1，大的索引不动。
3. 注意去重。

### 6.合并排序数组

1. 就是归并排序的merge
2. 可以优化（不会。。。）

### [39.恢复旋转排序数组](http://www.lintcode.com/zh-cn/problem/recover-rotated-sorted-array/)

1. 最暴力的思路就是找出旋转基rotate，然后拷贝一个新数组，然后拷贝。
2. 参考了别人的思路，旋转，从[0,rotate] 和 [rotata,n] 和 [0,n]旋转三次即可。

### [41.最大子数组](http://www.lintcode.com/zh-cn/problem/maximum-subarray/)

1. 使用两个变量max和d，max保存的是到当前遍历的地方为止最大的子数组之和，对于d来说就是保存的从某个位置开始的子数组之和，当这个d小于0的时候，不管下一个数是正是负，这个d都会“拖累”下一个数，所以直接舍弃。
2. 实际上这里的每一步的max都是到当前i为止的一个局部最大值。

### [42.最大子数组II](http://www.lintcode.com/zh-cn/problem/maximum-subarray-ii/)

1. 利用41最大子数组中的第二点，前后遍历两次，分别将到i前后最大值分别存在两个数组中
2. 对最后的结果进行一次遍历，找出最大值即可。

### [44.最小子数组](http://www.lintcode.com/zh-cn/problem/minimum-subarray/)

1. 和41最大子数组思路完全一样。

### [45.最大子数组差](http://www.lintcode.com/zh-cn/problem/maximum-subarray-difference/)

1. 和42最大子数组II思路一样
2. 要注意不一定是左边数组最大而右边数组最小，结果可能在反过来的情况中，所以要都考虑到。

### [60.搜索插入位置](http://www.lintcode.com/zh-cn/problem/search-insert-position/)

1. 基本思路二分法
2. 二分法并不难，但是关键的地方在于当找不到元素的时候如何正确的返回比target大的最小值的元素。在循环过程中不断的向target逼近。

### [61.搜索区间](http://www.lintcode.com/zh-cn/problem/search-for-a-range/)

1. 和60搜索插入位置类似都是二分查找法
2. 要注意的是对于重复元素，这样就只能用60搜索插入位置的版本1来做。

### [62.搜索旋转排序数组](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/)

1. 基本思路仍是二分法，只是现在找出mid后，mid可能只有一边有序，另一边无序了，但是我们可以拿有序那边做判断，因为是有序，很容易判断出target在不在，如果不在就直接将范围缩小到另一端。

### [63.搜索排序旋转数组II](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array-ii/)

1. 代码同62搜索旋转排序数组一样

### [64.合并排序数组II](http://www.lintcode.com/zh-cn/problem/merge-sorted-array/)

1. 直接用的归并排序的merge函数

### [75.寻找峰值](http://www.lintcode.com/zh-cn/problem/find-peak-element/)

1. 首先题目要求时间复杂度为o(logn)，因此还是适用二分法
2. 由于题目中确保了至少存在了一个峰值，所以当`A[mid] < A[mid+1]` 时，我们就能得到在mid的右边是至少存在一个峰值的所以可以直接让数组向右走，反过来，让数组直接想左二分即可。

### [100.删除排序数组中的重复数字](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array/)

1. 维持两个指针i，j,遍历j，每次当nums[j]!=nums[i]的时候，就表明遇到了一个新的不重复的num，此时赋值给nums[++i]即可。最后i+1就是数组的长度。

### [101.删除排序数组中的重复数字 II](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-array-ii/)

1. 和上一题一样，只需加一个计数器即可。

### [77.最长公共子序列](http://www.lintcode.com/zh-cn/problem/longest-common-subsequence/)

1. 对于两个字符串A{A0,A1,A2,...,Am},B{B0,B1,B2,...Bn},字符串Z{Z0,Z1,Z2,...,Zk}是他们的一个公共子序列，那么有： 
    1. 如果Am=Bn,那么Zk=Am=Bn，而且Zk-1也是Am-1和Bn-1的一个LCS
    2. 如果Am!=Bn，那么Zk!=Am，则Zk是Am-1和Bn的一个LCS
    3. 如果Am!=Bn，那么Zk!=Bn，则Zk是Am和Bn-1的一个LCS
2. 根据1可得到一个递推式：  

<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{cases}&space;0,if\,i=0,\,or\,j&space;=&space;0\\&space;c[i-1,j-1]&plus;1,if&space;i,j>0\,and\,Ai=Bi\\&space;max(c[i,j-1],c[i-1,j])if&space;i,j>0\,and\,Ai\neq&space;Bi\\&space;\end{cases}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{cases}&space;0,if\,i=0,\,or\,j&space;=&space;0\\&space;c[i-1,j-1]&plus;1,if&space;i,j>0\,and\,Ai=Bi\\&space;max(c[i,j-1],c[i-1,j])if&space;i,j>0\,and\,Ai\neq&space;Bi\\&space;\end{cases}" title="\begin{cases} 0,if\,i=0,\,or\,j = 0\\ c[i-1,j-1]+1,if i,j>0\,and\,Ai=Bi\\ max(c[i,j-1],c[i-1,j])if i,j>0\,and\,Ai\neq Bi\\ \end{cases}" /></a>

### [116.跳跃游戏](http://www.lintcode.com/zh-cn/problem/jump-game/)

1. 目前用的动态规划，能否跳到最后一个位置也就是dp[n]是否为true，取决于dp[n-1],dp[n-2],...,dp[1]他们是否能跳到，如果能跳到他们的位置，那他们能否跳到最后一个位置，所以我们需要一个dp[n]来保存这些状态

### [124.最长连续序列](http://www.lintcode.com/zh-cn/problem/longest-consecutive-sequenc)

1. 题中要求时间复杂度为O(n)，那很容易想到我们需要一个工具来记录。
2. 我们选择map来记录，当我们遇到一个数字时，首先判断在不在map中，若不在map中，那我们就看下这个数字-1 和 +1 在if不在，然后分别判断，若在，则说明之前已经记录过他们的长度，那我们跟着这个记录很容易回到这个序列的第一个和最后一个，更新记录即可。

### [135.数字组合](http://www.lintcode.com/zh-cn/problem/combination-sum/)

1. 回溯法
2. 从第0个数字开始，当我们把这个数字加到r(vector<int>)中后，target就要相应变化，然后我们接着从这个数组中找变化之后的target，如果target=0，就结束，否则就一直递归下去。

### [153.数字组合II](http://www.lintcode.com/zh-cn/problem/combination-sum-ii/)

1. 回溯法
2. 基本思路和代码都是和**135数字组合**一样的，不同的地方在于要去重。

### [152.组合](http://www.lintcode.com/zh-cn/problem/combinations/)

1. 和**135数字组合一样**都是简单回溯法的应用

### [157.判断字符串是否没有重复字符](http://www.lintcode.com/zh-cn/problem/unique-characters/)

1. 这道题要求不占用额外空间，我见其他人都是直接两重循环做那样复杂度就是O(n2)，如果我先排序(onlogn)，然后在遍历一遍，这样最后是O(nlogn)。

### [172.删除元素](http://www.lintcode.com/zh-cn/problem/remove-element/)

1. 维护两个索引i,j，让j一直遍历，只要不与target相同，就给num[i]赋值，i++，最后i的值就是新的数组的长度

### [189.丢失的第一个正整数](http://www.lintcode.com/zh-cn/problem/first-missing-positive/)

1. 最直观的做法就是对数组排序，然后遍历找出缺失的正整数即可，但是这样的时间复杂度就是o(nlogn)了。
2. 参考[CSDN上一个人的做法](http://blog.csdn.net/wangyuquanliuli/article/details/45749023)，首先要想明白因为是要找最小的正整数，所以我们只需要考虑0-size+1之间的即可，当有一个无穷大的正数时，那它必然占用了一个0-size之间的位置，所以我们遍历数组，将1-size之间的数放在该放的位置，1放在0，2放在1的位置，然后在遍历就能找出这个缺失的数了。
3. 要注意重复情况比如[2,2,2,2]这种，处理不当可能会死循环。

### [363.接雨水](http://www.lintcode.com/zh-cn/problem/trapping-rain-water/)

1. 从题中的图可以看出，数组是先增后减，所以那个最大值的地方就是我们分水岭，相对于左边来说，这个值就是右边的最大值，那我们就从0开始遍历到这个位置，每次都取一个最大值，代表了左边能接到雨水的最大值，依次累积。然后在从右往左遍历即可。

### [383.装最多水的容器](http://www.lintcode.com/zh-cn/problem/container-with-most-water/)

1. 这道题和[363.接雨水](http://www.lintcode.com/zh-cn/problem/trapping-rain-water/)很像
2. 数组左右维护两个指针i,j，要注意的是这里没有“墙壁”的厚度了，所以i,j能接的最大水容量就是min(arr[i],arr[j])*(j-i)，即便i,j之间有比arr[i]和arr[j]更大的“墙壁”也不碍事。
3. 然后保存这个值，移动i,j(若左边的墙壁的高度小于右边的，就++i,否则就++j)。

### [373.奇偶分割数组](http://www.lintcode.com/zh-cn/problem/partition-array-by-odd-and-even/)

1. 和快排的partition操作类似

### [374.螺旋矩阵](http://www.lintcode.com/zh-cn/problem/spiral-matrix/)

1. 找出规律，递归即可
2. 应该要有更简单的方法

### [379.将数组重新](http://www.lintcode.com/zh-cn/problem/reorder-array-to-construct-the-minimum-number/)

1. 这里最关键的应该是排序了，可以将数字变为字符串，然后遍历排序，也可以将他们互相颠倒顺序相加。
2. 要注意数组中0的情况

### [388.第k个排列](http://www.lintcode.com/zh-cn/problem/permutation-sequence/)

1. 很简单的思路就是算一下n个数每个数有几种排列，然后和k比较。
2. 代码的第11行是因为在第20行可能会得出index=1，这种情况，如果没有k-=1这句话的话就会多算一种情况，把k-1，当k<n的时候仍然不会影响。

### [394.硬币排成线](http://www.lintcode.com/zh-cn/problem/coins-in-a-line/)

1. 这个题一个前提假设就是每个人都在为自己争取最大的利益。
2. 第一种解法:就是动态规划，实际上对于1个硬币，第一个人肯定赢，对于2两个硬币，第二个人也能赢，对于3个硬币呢，我们看1个硬币和2个硬币第一个人都能赢，这也就意味着当到3个硬币的时候，第一个人能拿走第一个硬币或者前两个硬币，不管是这两种那哪种情况，第二个人都可以一下全部收走，这样递推下去就行。
3. 第二种思路参考CSDN上的，就是判断 ```n%3!=0``` 就行，因为要想让第二个人赢，只有当剩3个硬币的时候第二个人才可以赢。

### [395.硬币排成线II](http://www.lintcode.com/zh-cn/problem/coins-in-a-line-ii)

1. 这道题最开始我一直想着从前向后做，可是这样发现，每次我想拿到第i个值的状态，他都和后面未拿到的值的状态有关，于是反过来思考。
2. 因为是要拿到最大值，所以每个硬币第一个人都是有可能拿到的，所以我们这么想，当我们在第i个硬币的位置时，我们可以拿一个硬币，也可以拿两个硬币，当我们拿一个硬币时，第二个人可能拿一个，也可能拿两个，这道题实际上暗示了一个假设就是每个人都在为自己争取最大的利益，所以第二个人不管是拿一个还是拿两个，最终目的都是为了让自己利益最大，反过来也就是让第一个人利益最小，此时我们就有了一个状态转移方程：  

<a href="https://www.codecogs.com/eqnedit.php?latex=dp[i]=values[i]&space;&plus;&space;min(dp[i&plus;2],dp[i&plus;3])" target="_blank"><img src="https://latex.codecogs.com/gif.latex?dp[i]=values[i]&space;&plus;&space;min(dp[i&plus;2],dp[i&plus;3])" title="dp[i]=values[i] + min(dp[i+2],dp[i+3])" /></a>  
式中dp[i+2]代表着第二个人拿了一个硬币，那我们就要从第i+2个硬币开始拿。

3. 类比于上式，我们可以得到最终的状态转移方程:  

<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{cases}&space;values[i],\&space;if\&space;i&space;=&space;size-1\&space;(size\&space;from\&space;0\&space;to\&space;size-1)&space;\\values[i-1]&plus;values[i],\&space;if\&space;i=size-2&space;\\max(values[i]&plus;min(dp[i&plus;2],dp[i&plus;3]),values[i]&plus;values[i&plus;1]&plus;min(dp[i&plus;3],dp[i&plus;4])),\&space;if\&space;i<=size-3&space;\end{cases}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{cases}&space;values[i],\&space;if\&space;i&space;=&space;size-1\&space;(size\&space;from\&space;0\&space;to\&space;size-1)&space;\\values[i-1]&plus;values[i],\&space;if\&space;i=size-2&space;\\max(values[i]&plus;min(dp[i&plus;2],dp[i&plus;3]),values[i]&plus;values[i&plus;1]&plus;min(dp[i&plus;3],dp[i&plus;4])),\&space;if\&space;i<=size-3&space;\end{cases}\right." title="\begin{cases} values[i],\ if\ i = size-1\ (size\ from\ 0\ to\ size-1) \\values[i-1]+values[i],\ if\ i=size-2 \\max(values[i]+min(dp[i+2],dp[i+3]),values[i]+values[i+1]+min(dp[i+3],dp[i+4])),\ if\ i<=size-3 \end{cases}\right." /></a>  

4. 最终我们求得的dp[0]就是第一个人能拿到的最大硬币值，让所有硬币值减去第一个人的就是第二个人拿到的，两个值比较就可得出输赢。

### [397.最长上升连续子序列](http://www.lintcode.com/zh-cn/problem/longest-increasing-continuous-subsequence/)

1. 动态规划的简单应用。dp[i]表示到i个数字为止，最长上升子序列的长度，其动态转移方程为：

<a href="https://www.codecogs.com/eqnedit.php?latex=dp[i]=\begin{cases}&space;1,\&space;if\&space;values[i-1]\geq&space;values[i]\&space;or\&space;i=&space;0&space;\\dp[i-1]&plus;1,\&space;if\&space;values[i-1]&space;<&space;values[i]&space;\end{cases}\right." target="_blank"><img src="https://latex.codecogs.com/gif.latex?dp[i]=\begin{cases}&space;1,\&space;if\&space;values[i-1]\geq&space;values[i]\&space;or\&space;i=&space;0&space;\\dp[i-1]&plus;1,\&space;if\&space;values[i-1]&space;<&space;values[i]&space;\end{cases}\right." title="dp[i]=\begin{cases} 1,\ if\ values[i-1]\geq values[i]\ or\ i= 0 \\dp[i-1]+1,\ if\ values[i-1] < values[i] \end{cases}\right." /></a>

2. 因为题目要求从右向左也是可以的，所以我们反过来再算一次，求出所有```dp[i]```的最大值即可。

### [402连续子数组求和](http://www.lintcode.com/zh-cn/problem/continuous-subarray-sum/)

1. 这道题和有一道动态规划很像，等找到了补上去
2. 因为要求是连续子数组，所以我们从0开始依次累加，当我们的```sum<0```时，这个i就是新的分割点，因为```sum<0```，所以我们不管加一个什么值都会比sum小，这时可以在拿max与sum比较更新索引。

### [406.和大于S的最小子数组](http://www.lintcode.com/zh-cn/problem/minimum-size-subarray-sum/)

1. 因为要求是连续子数组，所以我们从0开始，每个元素我们加一次，然后更新最短距离就好。
2. 还可以说当我们的子数组和大于target时，我们可以让left+1，让right以此向右，然后直到子数组和在此小于target时更新最短距离。

### [407.加一](http://www.lintcode.com/zh-cn/problem/plus-one/)

1. 注意一点就是最后一位需要进位的情况。

### [539.移动零](http://www.lintcode.com/zh-cn/problem/move-zeroes/)

1. 两根指针

### [633.寻找重复的数](http://www.lintcode.com/zh-cn/problem/find-the-duplicate-number/)

1. 因为不能修改数组，所以不能使用排序
2. 这道题用了很经典的[二分法的思路](http://blog.csdn.net/apie_czx/article/details/49278447)我们只要把left和right当做是重复值的下上界限就能别有洞天。接着开展二分搜索中的搜索过程：mid取中值，那么nums中的数就被分成了```[left , mid - right]```两端了。然后我们遍历一遍nums，统计所有<=mid的值count，如果```count > right - left + 1```，说明```[ left - mid ]```段的数字中存在重复（重复值为其区间的值），所以令```right = mid```。反之就是```[ mid - right ]```的数字，所以令```left = mid + 1```

## [链表](http://www.lintcode.com/problem/?tag=linked-list)

### [35.翻转链表](http://www.lintcode.com/zh-cn/problem/reverse-linked-list/)

1. 我们把每一个结点指向反过来，最后最后一个结点就是头结点。
2. 注意最后边界问题。

### [36.翻转链表II](http://www.lintcode.com/zh-cn/problem/reverse-linked-list-ii/)

1. 和上一题一样的思路，但是这里需要先找到前一个结点和后一个结点
2. 注意head问题。

### [48.主元素III](http://www.lintcode.com/zh-cn/problem/majority-number-iii/)

1. 这道题我用的哈希表做的，只是简单统计即可。

### [96.划分链表](http://www.lintcode.com/zh-cn/problem/partition-list/)

1. 对于链表来说，这里我们常常引入一个dummy结点，让```dumm->next = head```作为哨兵结点，为什么？因为对于类似的```head=node```这样的赋值来说，是不能改变链表的走向的，我们只能说```dummy->next=node```才可以改变链表。
2. 本来用的是快排的partition操作，可是题中要求不能改变相对顺序，于是加入两个头结点，从head开始遍，分别将小于k和大于k的指向两个结点，最后将两个结点汇总到一起。

### [98.链表排序](http://www.lintcode.com/zh-cn/problem/sort-list/)

1. 快排，我尝试用快排做了，但是快排是平均复杂度是O(nlogn),所以按照最简单的快排来做的话，是出现LTE，就只能每次先随机选择一个数，但是链表不支持随机访问，这样会很复杂，就没有往下做。
2. 第二种就是归并了，对于链表来说，归并好做，但是很多小细节要注意：   
    1. 如何找中间节点，这里就是利用快慢节点关系，快结点每次走两个结点，慢节点每次走1个结点，这样相同的时间，当快结点到终点时，慢节点就恰好在中间节点的位置上，但是这里对偶数结点，最终是偏左还是偏右和代码的第71行的初值有关。
    2. 就是边界问题要考虑清楚。

### [99.重排链表](http://www.lintcode.com/zh-cn/problem/reorder-list/)

**题目：** 给定一个单链表L:L0->L1->L2->...->Ln-1->Ln,重新排列后为：L0→Ln→L1→Ln-1→L2→Ln-2->... ,必须在不改变结点值的情况下进行原地操作。例如给出链表 1->2->3->4->null，重新排列后为1->4->2->3->null  
**分析：**

1. 因为不能改变结点值，且原地操作，所以我们首先想到先找到mid结点，然后将mid结点一直到end翻转一下，然后将这个新链表插入到前半个链表即可。
2. 这里要注意```node = next```和```node->next = next```的区别。

### [102.带环链表](http://www.lintcode.com/zh-cn/problem/linked-list-cycle/)
**题目：** 给定一个链表，判断它是否有环。  
**分析：**

1. 最直观的思路就是一直遍历下去，然后对每个结点标记，如果一旦遍历到标记过的结点，那就代表该链表有环。
2. 另一种思路就是将这道题看做为追及问题，A和B分别以v和2v的速度在n米操场跑步，那么他们必然在n/v时第一次相遇。那我们就可以拿两个指针，一个每次走一个结点，一个走两个结点，这样一旦他们相等，则必然有环。

### [103.带环链表II](http://www.lintcode.com/zh-cn/problem/linked-list-cycle-ii/)

**题目：** 给定一个链表，如果链表中存在环，则返回到链表中环的起始节点，如果没有环，返回null。例如：给出 -21->10->4->5, tail connects to node index 1，返回10。   
**分析：**

1. 首先利用[102.带环链表](http://www.lintcode.com/zh-cn/problem/linked-list-cycle/)的思路判断链表是否有环，然后将快慢指针分别保存下来。
2. 我们假设链表长度为l，从起点到环的第一个结点共有m个结点，那当快慢指针第一次相遇时，我们假设所用时间为t，快指针一定比慢指针多跑了一圈，所用就有如下方程

```math
2t-l-(t-l)=(l-m)
t=l-m
```

所用此时慢指针已经跑了```l-m```个结点，也就是一个环，那我们再让他跑```m```个结点，就跑了l个结点，此时应该刚好回到环的开始，而```m```个结点的距离刚好又是从链表起点到环开始的距离，所用我们就在用一个```start```指针，让他们同时跑，最后相遇时，就是环的起始结点。

### [104.合并k个排序链表](http://www.lintcode.com/zh-cn/problem/merge-k-sorted-lists/)

**题目：** 合并k个排序链表，并且返回合并后的排序链表。尝试分析和描述其复杂度。例如给出3个排序链表```[2->4->null,null,-1->null]```，返回 ```-1->2->4->null```.  
**分析：**

1. 直接两个两个merge即可，应该会有其他方法。
2. 这样做时间复杂度是o(n2)

### [112.删除排序链表中的重复元素](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list/)

**题目：** 给定一个排序链表，删除所有重复的元素每个元素只留下一个。例如给出 ```1->1->2->3->3->null```，返回 ```1->2->3->null```  
**分析：**

1. 这道题目很简单，我们只需要遍历一遍链表即可。

### [113.删除排序链表中的重复元素II](http://www.lintcode.com/zh-cn/problem/remove-duplicates-from-sorted-list-ii/)

**题目：** 给定一个排序链表，删除所有重复的元素只留下原链表中没有重复的元素。例如：给出```1->2->3->3->4->4->5->null```，返回 ```1->2->5->null```  
**分析：**

1. 遍历链表，我们在while循环在加一个while循环用来跳过重复元素，然后到一个新的元素后，我们判断他和后面的是不是相同，如果相同则继续进入while，如果不同，则加入到新的链表中去。
2. 此题的一个需要注意的地方就是开头结点可能删去，所以我们加一个dummyhead结点，这也是链表题常用的做法。

### [165.合并两个排序链表](http://www.lintcode.com/zh-cn/problem/merge-two-sorted-lists/)

**题目：** 将两个排序链表合并为一个新的排序链表。例如：给出 ```1->3->8->11->15->null，2->null```， 返回 ```1->2->3->8->11->15->null```。  
**分析：**

1. 和数组的归并排序中的merge操作是一样的，这里要简化的一步就是当某个链表走到头的时候，我们直接退出循环，将另外一个链表追加上即可。

### [166. 链表倒数第n个节点](http://www.lintcode.com/zh-cn/problem/nth-to-last-node-in-list/)

**题目：** 找到单链表倒数第n个节点，保证链表中节点的最少数量为n。例如：给出链表 ```3->2->1->5->null```和```n = 2```，返回倒数第二个节点的值1.  
**分析：**

1. 最直接的思路就是遍历求得链表长度，然后循环即可。
2. 对于链表找结点，通常就是构造两个特殊的一快一慢指针，控制他们的速度，差距。对于本题来说，我们只需让快结点领先慢结点```n```个结点，然后开始遍历，当快结点走到最后时，慢结点的位置就是要找的的结点。  

### [167.链表求和](http://www.lintcode.com/zh-cn/problem/add-two-numbers/)

**题目：** 假定用一个链表表示两个数，其中每个节点仅包含一个数字。假设这两个数的数字 **相反** 排列，请设计一种方法将两个数相加，并将其结果表现为链表的形式。例如：给给出两个链表 ```3->1->5->null```和 ```5->9->2->null```，返回 ```8->0->8->null```  
**分析：**

1. 保存一个add变量用来记录每次相加后进位结果。
2. 特别要注意的两种情况：
    1. 两个链表加完之后，仍需进位。
    2. 一个链表用完后，另一个链表还有数字。

### [221. 链表求和 II](http://www.lintcode.com/zh-cn/problem/add-two-numbers-ii/)

**题目：** 假定用一个链表表示两个数，其中每个节点仅包含一个数字。假设这两个数的数字 **顺序** 排列，请设计一种方法将两个数相加，并将其结果表现为链表的形式。例如：给出 ```6->1->7 + 2->9->5```。即，617 + 295。返回 ```9->1->2```。即，912。    
**分析：**

1. 思路和上一题一样，但是首先要将链表反转，然后保存一个add变量用来记录每次相加后进位结果。
2. 特别要注意的两种情况：
    1. 两个链表加完之后，仍需进位。
    2. 一个链表用完后，另一个链表还有数字。

### [170. 旋转链表](http://www.lintcode.com/zh-cn/problem/rotate-list/)

**题目：** 给定一个链表，旋转链表，使得每个节点向右移动k个位置，其中k是一个非负数。例如：给出链表```1->2->3->4->5->null```和```k=2```,返回```4->5->1->2->3->null```.  
**分析：**

1. 首先确定链表长度，然后找到翻转点，反过来即可。
2. 要注意的是：
    1. 当```k==0```时
    2. 当```k>=length```时

### [174. 删除链表中倒数第n个节点](http://www.lintcode.com/zh-cn/problem/remove-nth-node-from-end-of-list/)

**题目：** 给定一个链表，删除链表中倒数第n个节点，返回链表的头节点。例如：给出链表```1->2->3->4->5->null```和 ```n = 2```。删除倒数第二个节点之后，这个链表将变成```1->2->3->5->null```.  
**分析：**

1. 首先按照[166. 链表倒数第n个节点](http://www.lintcode.com/zh-cn/problem/nth-to-last-node-in-list/)的思路找到倒数第n+1个结点，然后让```n->next = n->next->next```即可。
2. 这里要注意当最后删除的结点是第一个结点的情况，为了让整个循环统一，我们可以用一个哨兵结点。

### [223. 回文链表](http://www.lintcode.com/zh-cn/problem/palindrome-linked-list/)

**题目：** 设计一种方式检查一个链表是否为回文链表。例如： ```1->2->1``` 就是一个回文链表。  
**分析：**

1. 从中间结点将链表断开，将右边的链表反转，然后比较。
2. 注意当链表长度是奇数时，我们从中间向右一个的结点断开，然后反转后开始比较，当右边链表结束时即可。

### [372. 在O(1)时间复杂度删除链表节点](http://www.lintcode.com/zh-cn/problem/delete-node-in-the-middle-of-singly-linked-list/)

**题目：** 给定一个单链表中的一个等待被删除的节点(**非表头或表尾**)。请在在O(1)时间复杂度删除该链表节点。例如：Linked list is ```1->2->3->4```, and given node ```3```, delete the node in place ```1->2->4```。  
**分析：**

1. 我们让这个结点变为下个结点的值，然后直接指向下下个结点就可以了。

### [380. 两个链表的交叉](http://www.lintcode.com/zh-cn/problem/intersection-of-two-linked-lists/)

**题目：** 请写一个程序，找到两个单链表最开始的交叉节点。  
**分析：**

1. 我们将两个链表连接在一起，如果链表交叉结点，那么新的链表必然有环。
2. 最终问题转化为[链表是否有环](http://www.lintcode.com/zh-cn/problem/linked-list-cycle-ii/)的问题。

### [450. K组翻转链表](http://www.lintcode.com/zh-cn/problem/reverse-nodes-in-k-group/)

**题目：** 给你一个链表以及一个k,将这个链表从头指针开始每k个翻转一下。链表元素个数不是k的倍数，_最后剩余的不用翻转_。例如：给出链表 ```1->2->3->4->5``` 和```k = 2```, 返回```2->1->4->3->5```.  
**分析：**

1. 就是维护一个fast和slow指针，让fast领先slow指针n个节点，然后依次翻转，向前推进即可。

### [451. 两两交换链表中的节点](http://www.lintcode.com/zh-cn/problem/swap-nodes-in-pairs/)

**题目：** 给一个链表，两两交换其中的节点，然后返回交换后的链表。例如：给出 ```1->2->3->4```, 你应该返回的链表是 ```2->1->4->3```。  
**分析：**

1. 遍历链表，两两交换```head```和```head->next```即可，若剩余1个节点也无需考虑，因为我们交换两个节点并不改变链表的全局顺序。

### [452. 删除链表中的元素](http://www.lintcode.com/zh-cn/problem/remove-linked-list-elements/)

**题目：** 删除链表中等于给定值val的所有节点。例如：出链表 ```1->2->3->3->4->5->3```, 和 ```val = 3```, 你需要返回删除3之后的链表：```1->2->4->5```。  
**分析：**

1. 注意当删除的元素是第一个节点时的情况。

### [466. 链表节点计数](http://www.lintcode.com/zh-cn/problem/count-linked-list-nodes/)

**题目：** 计算链表中有多少个节点.例如：给出 ```1->3->5```, 返回 ```3```。  
**分析：**

1. 链表的简单遍历。

### [511. 交换链表当中两个节点](http://www.lintcode.com/zh-cn/problem/swap-two-nodes-in-linked-list/)

**题目：** 给你一个链表以及两个权值```v1```和```v2```，交换链表中权值为```v1```和```v2```的这两个节点。保证链表中节点权值各不相同，如果没有找到对应节点，那么什么也不用做。例如：给出链表```1->2->3->4->null``` ，以及```v1 = 2```， ```v2 = 4```，返回结果```1->4->3->2->null```。  
**分析：**

1. 分两种情况：
    1. 当两个结点相邻时
    2. 不相邻时
2. 注意有结点在head的位置时，需要增加哨兵结点处理

## [二叉树](http://www.lintcode.com/problem/?tag=binary-tree)

### [66. 二叉树的前序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal/)

**题目：** 给出一棵二叉树，返回其节点值的前序遍历。  
**分析：**

1. 递归
2. 对于迭代遍历，我们可以自己先手动遍历下，会发现一个规律，其实前序遍历就是从根节点开始一直沿着左节点往下遍历，然后在从叶子节点向上遍历右节点，此时我们可以用一个栈，来保存从上而下遍历时的右子节点。

### [67. 二叉树的中序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal/)

**题目：** 给出一棵二叉树，返回其节点值的中序遍历。  
**分析：**

1. 递归
2. 和[66. 二叉树的前序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal/)思路一样，我们发现中序遍历是从左侧自底向上，所以我们仍然用一个栈来保存我们经历的各个节点，然后依次弹出。

### [68. 二叉树的后序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-postorder-traversal/)

**题目：** 给出一棵二叉树，返回其节点值的后序遍历。
**分析：**

1. 递归
2. 和[66. 二叉树的前序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-preorder-traversal/)思路一样，我们仍然是从左子数根部开始，但是此时我们需要加一个上次访问的结点，来判断根节点是否要加入，因为在到根节点时，如果根节点有右子数，但是我们循环如果不判断的话，是会死循环的。

### [632. 二叉树的最大节点](http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-node/)

**题目：** 在二叉树中寻找值最大的节点并返回。  
**分析：**

1. 递归, 可分别将三种非递归版本的遍历在实现一遍。

### [69. 二叉树的层次遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/)

**题目：** 给出一棵二叉树，返回其节点值的层次遍历（逐层从左往右访问）。  
**分析：**

1. 递归(DFS)[Binary Tree Level Order Traversal II](http://blog.csdn.net/eastmount/article/details/48359685)。
2. 队列(BFS)。只用一个队列，我们同样每次保存一个每一层最右边的节点，当到这个节点时我们就把```vector<int>```加入到```vector<vector<int>>```。

### [70. 二叉树的层次遍历 II](http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal-ii/)

**题目：** 给出一棵二叉树，返回其节点值从底向上的层次序遍历（按从叶节点所在层到根节点所在的层遍历，然后逐层从左往右遍历）.  
**分析：**

1. 就是将[69. 二叉树的层次遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/)的答案reverse一下，还有其他方法么？

### [97. 二叉树的最大深度](http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/)

**题目：** 给定一个二叉树，找出其最大深度。二叉树的深度为根节点到最远叶子节点的距离。  
**分析：**

1. 分治。
2. 二叉树中常用的思想就是分治或者递归，实际上分治也利用了递归。

### [155. 二叉树的最小深度](http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/)

**题目：** 给定一个二叉树，找出其最小深度。二叉树的最小深度为根节点到最近叶子节点的距离。  
**分析：**

1. 递归。

### [175. 翻转二叉树](http://www.lintcode.com/zh-cn/problem/invert-binary-tree/)

**题目：** 翻转一棵二叉树。就是镜像对称。  
**分析：**

1. 递归。
2. 非递归，使用栈。

### [375. 克隆二叉树](http://www.lintcode.com/zh-cn/problem/clone-binary-tree/)

**题目：** 深度复制一个二叉树。给定一个二叉树，返回一个他的```克隆品```。  
**分析：**

1. 递归。
2. 因为二叉树的特殊结构，所以二叉树实现递归较多。

### [376. 二叉树的路径和](http://www.lintcode.com/zh-cn/problem/binary-tree-path-sum/)

**题目：** 给定一个二叉树，找出所有路径中各节点相加总和等于给定```目标值```的路径。一个有效的路径，指的是从根节点到叶节点的路径。  
**分析：**

1. 递归。

### [480. 二叉树的所有路径](http://www.lintcode.com/zh-cn/problem/binary-tree-paths/)

**题目：** 给一棵二叉树，找出从根节点到叶子节点的所有路径。  
**分析：**

1. 递归,和[376. 二叉树的路径和](http://www.lintcode.com/zh-cn/problem/binary-tree-path-sum/)思路一样

### [453. 将二叉树拆成链表](http://www.lintcode.com/zh-cn/problem/flatten-binary-tree-to-linked-list/)

**题目：** 将一棵二叉树按照前序遍历拆解成为一个```假链表```。所谓的假链表是说，用二叉树的```right```指针，来表示链表中的```next```指针。  
**分析：**

1. 递归,每次交换左右节点，将右节点放在左节点的最右子节点上，将最新的左节点放到右节点上。

### [93. 平衡二叉树](http://www.lintcode.com/zh-cn/problem/balanced-binary-tree/)

**题目：** 给定一个二叉树,确定它是高度平衡的。对于这个问题,一棵高度平衡的二叉树的定义是：一棵二叉树中每个节点的两个子树的深度相差不会超过1。  
**分析：**

1. 分治，不过这里在分治的时候我们既需要保存是否是平衡树也需要知道最大深度，所以使用一个结构体。

### [88. 最近公共祖先](http://www.lintcode.com/zh-cn/problem/lowest-common-ancestor/)

**题目：** 给定一棵二叉树，找到两个节点的最近公共父节点(LCA)。最近公共祖先是两个节点的公共的祖先节点且具有最大深度。注意：假设给出的两个节点都在树中存在。  
**分析：**

1. 这道题可以这样想，既然要找最近公共祖先，那我不妨先在左子树中寻找，如果一旦在左子树中寻找，然后在右子树寻找，如果找到就返回。
2. 但是有一种特殊情况就是两个节点分布在左右子树中，此时很明显他们的最近公共祖先就是root，所以当我们在左子树中寻找时，我们只要碰到一个结点，我们就返回这个节点，右子树也这样处理。
3. 又因为两个节点是一定存在的，所以当我们右子树返回的```NULL```（即右子树一个节点也没找到）那说明两个节点都在左子数中，那我们在左子树中碰到的第一个节点就是他们的最近公共祖先，同理右子树也是这样。
4. 当左右子树分别返回一个节点时，那很显然他们的最近公共祖先就是root。