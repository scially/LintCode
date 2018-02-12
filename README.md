# LintCode题解

## 数组、排序

### 464.整数排序

1. 这道题和49字符大小写排序那道题很一样，可以分别使用快排和归并排序
2. 对于快排，要熟练掌握2路排序和3路排序，在后面的题中会用到。

### 31.数组划分

1. 整数ｋ不一定是数组中的元素
2. 因为这道题并没有说完全按照```<k ,==k, >k```的顺序，所以我们可以使用2路排序将其排列为```<k,>=k```的元素即可

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
2. 从第0个数字开始，当我们把这个数字加到r(```vector<int>```)中后，target就要相应变化，然后我们接着从这个数组中找变化之后的target，如果target=0，就结束，否则就一直递归下去。

### [153.数字组合II](http://www.lintcode.com/zh-cn/problem/combination-sum-ii/)

1. 回溯法
2. 基本思路和代码都是和**135数字组合**一样的，不同的地方在于要去重。

### [64.合并排序数组II](http://www.lintcode.com/zh-cn/problem/merge-sorted-array/)

1. 直接用的归并排序的merge函数

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

### [105. 复制带随机指针的链表](http://www.lintcode.com/zh-cn/problem/copy-list-with-random-pointer/)

#### 题目：

给出一个链表，每个节点包含一个额外增加的随机指针可以指向链表中的任何节点或空的节点。返回一个深拷贝的链表.  

#### 分析：

1. 第一次遍历的时候使用一个map（哈希表）来记录旧链表和新链表，然后在遍历一次即可。

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

### [378. 将二叉查找树转换成双链表](http://www.lintcode.com/zh-cn/problem/convert-binary-search-tree-to-doubly-linked-list/)

#### 题目：

将一个二叉查找树按照中序遍历转换成双向链表。

#### 分析：

1. 利用[67. 二叉树的中序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-inorder-traversal/)的迭代版。

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

### [94. 二叉树中的最大路径和](http://www.lintcode.com/zh-cn/problem/binary-tree-maximum-path-sum/)

**题目：** 给出一棵二叉树，寻找一条路径使其路径和最大，路径可以在任一节点中开始和结束（路径和为两个节点之间所在路径上的节点权值之和）.  
**分析：**

1. 思路和[88. 最近公共祖先](http://www.lintcode.com/zh-cn/problem/lowest-common-ancestor/)很一样首先我们还是用分治的思想来想这道题，要求最大路径，我们不妨先在左子树中求一下，然后在在右子树中求一下，当我们在左右子树都求出来后，很有可能答案就在这两个里面。
2. 但是还有一种情况就是某条路径跨越了这个节点，此时我们就需要求一下从左节点开始的最大路径以及从右节点开始的最大路径，结构体中的singlepath既是这个，然后我们将这三种求最大值就是所要求的了。

### [245. 子树](http://www.lintcode.com/zh-cn/problem/subtree/)

**题目：** 有两个不同大小的二叉树：```T1```有上百万的节点； ```T2``` 有好几百的节点。请设计一种算法，判定 ```T2``` 是否为 ```T1```的子树。  
**分析：**

1. 注意子树的概念。
2. 递归。

### [85. 在二叉查找树中插入节点](http://www.lintcode.com/zh-cn/problem/insert-node-in-a-binary-search-tree/)

**题目：** 给定一棵二叉查找树和一个新的树节点，将节点插入到树中。你需要保证该树仍然是一棵二叉查找树。  
**分析：**

1. 递归。

### [11. 二叉查找树中搜索区间](http://www.lintcode.com/zh-cn/problem/search-range-in-binary-search-tree/)

**题目：** 给定两个值 k1 和 k2（k1 < k2）和一个二叉查找树的根节点。找到树中所有值在 k1 到 k2 范围内的节点。即打印所有x (k1 <= x <= k2) 其中 x 是二叉查找树的中的节点值。返回所有升序的节点值。  
**分析：**

1. 二叉搜索树的中序遍历就是升序.

### [95. 验证二叉查找树](http://www.lintcode.com/zh-cn/problem/validate-binary-search-tree/)

#### 题目：

给定一个二叉树，判断它是否是合法的二叉查找树(BST)  
一棵BST定义为：  

1. 节点的左子树中的值要严格小于该节点的值。
2. 节点的右子树中的值要严格大于该节点的值。
3. 左右子树也必须是二叉查找树。
4. 一个节点的树也是二叉查找树。

#### 分析：

1. 我们可以中序遍历判断是否是递增的，注意我们不需要把每个结点的值都保存下来，我们只需要一个上一个遍历到的结点的值和这次根节点比较即可。
2. 分治。

### [73. 前序遍历和中序遍历树构造二叉树](http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-preorder-and-inorder-traversal/)

#### 题目：

根据前序遍历和中序遍历树构造二叉树.

#### 分析：

1. 递归。
2. 对于一个树前序[1 2 4 5 3 6 7]  
            中序[4 2 5 1 6 3 7]  
   首先我们根据中序的4在前序找到4的位置，根据前序的遍历顺序必然可知  
   [4 2 5]是左子树 [6 3 7]是右子数 中序遍历  
   它们对应的前序遍历分别是[2 4 5] [3 6 7]  
   依次递归即可。

### [72. 中序遍历和后序遍历树构造二叉树](http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-inorder-and-postorder-traversal/)

#### 题目：

根据中序遍历和后序遍历树构造二叉树

#### 分析：

1. 递归。和[73. 前序遍历和中序遍历树构造二叉树](http://www.lintcode.com/zh-cn/problem/construct-binary-tree-from-preorder-and-inorder-traversal/)思路一样。

### [86. 二叉查找树迭代器](http://www.lintcode.com/zh-cn/problem/binary-search-tree-iterator/)

#### 题目：

设计实现一个带有下列属性的二叉查找树的迭代器：

1. 元素按照递增的顺序被访问（比如中序遍历）
2. ```next()```和```hasNext()```的询问操作要求均摊时间复杂度是O(1)

#### 分析：

1. 迭代版的中序遍历，参考[68. 二叉树的后序遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-postorder-traversal/)

### [177. 把排序数组转换为高度最小的二叉搜索树](http://www.lintcode.com/zh-cn/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/)

#### 题目：

给一个排序数组（从小到大），将其转换为一棵高度最小的排序二叉树。

#### 分析：

1. 首先要想到有序数组可以是BST的中序遍历，那么数组的中间节点就是根节点，左边是左子树，右边是右子数，迭代即可。
2. 注意这里LintCode有一个bug就是当你的数组范围是[b,e)，即左开右闭取得mid时，LintCode会通不过，LeetCode没问题。

### [106. 排序列表转换为二分查找树](http://www.lintcode.com/zh-cn/problem/convert-sorted-list-to-balanced-bst/)

#### 题目：

给出一个所有元素以升序排序的单链表，将它转换成一棵高度平衡的二分查找树  

#### 分析：

1. 和[177. 把排序数组转换为高度最小的二叉搜索树](http://www.lintcode.com/zh-cn/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/)一样的思路，每次寻找链表的中间节点作为根节点。

### [7. 二叉树的序列化和反序列化](http://www.lintcode.com/zh-cn/problem/binary-tree-serialization/)

#### 题目：

设计一个算法，并编写代码来序列化和反序列化二叉树。将树写入一个文件被称为“序列化”，读取文件后重建同样的二叉树被称为“反序列化”。  
如何反序列化或序列化二叉树是没有限制的，你只需要确保可以将二叉树序列化为一个字符串，并且可以将字符串反序列化为原来的树结构。

#### 分析：

1. 序列化这里就是采用题中的BFS算法，即层序遍历，[69. 二叉树的层次遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/)，空节点用```#```表示，注意最后结点的空节点直接省略。在层序遍历中，我们要注意对空节点的处理。
2. 反序列化中就是将```1```反过来，所以还是要利用一个队列来做，这里要引入一个变量来说明当前是左子树还是右子数，每次在右子数时，就要注意弹出队列后面的结点，让该节点推到队前。
3. 对于c++来说需要实现一个split的函数。

### [71. 二叉树的锯齿形层次遍历](http://www.lintcode.com/zh-cn/problem/binary-tree-zigzag-level-order-traversal/)

#### 题目：

给出一棵二叉树，返回其节点值的锯齿形层次遍历（先从左往右，下一层再从右往左，层与层之间交替进行） 

#### 分析：

1. 一个关键点就在于我如何知道我到了这一层的最后一个结点，我在这里用了一个私有的成员来表示最后一个结点，具体可以看代码注释。

### [201. 线段树的构造](http://www.lintcode.com/zh-cn/problem/segment-tree-build/)

#### 题目：

线段树是一棵二叉树，他的每个节点包含了两个额外的属性start和end用于表示该节点所代表的区间。```start```和```end```都是整数，并按照如下的方式赋值:  

1. 根节点的```start```和```end```由`build`方法所给出。
2. 对于节点`A`的左儿子，有`start=A.left, end=(A.left + A.right) / 2`。
3. 对于节点`A`的右儿子，有`start=(A.left + A.right) / 2 + 1, end=A.right`。
4. 如果`s`tart`等于`end`, 那么该节点是叶子节点，不再有左右儿子。  

实现一个`build`方法，接受`start`和`end`作为参数, 然后构造一个代表区间`[start, end]`的线段树，返回这棵线段树的根。

#### 分析：

1. 递归。

### [202. 线段树的查询](http://www.lintcode.com/zh-cn/problem/segment-tree-query/)

#### 题目：

对于一个有```n```个数的整数数组，在对应的线段树中, 根节点所代表的区间为```0 - n-1```, 每个节点有一个额外的属性```max```，值为该节点所代表的数组区间```start```到```end```内的最大值。  

为```SegmentTree```设计一个```query```的方法，接受3个参数`root`, `start`和`end`，线段树root所代表的数组中子区间`[start, end]`内的最大值。

#### 分析：

1. 分治查询，只需要分清楚`mid`和`start`和`end`的关系即可。

### [247. 线段树查询 II](http://www.lintcode.com/zh-cn/problem/segment-tree-query-ii/)

#### 题目：

对于一个数组，我们可以对其建立一棵`线段树`, 每个结点存储一个额外的值`count`来代表这个结点所指代的数组区间内的元素个数. (数组中并不一定每个位置上都有元素)  

实现一个`query`的方法，该方法接受三个参数`root`, `start`和`end`, 分别代表线段树的根节点和需要查询的区间，找到数组中在区间`[start, end]`内的元素个数

#### 分析：

1. 和[202. 线段树的查询](http://www.lintcode.com/zh-cn/problem/segment-tree-query/)完全一样的思路，但是要注意的是这里既然要统计，就会出现查询范围比数组范围大，或者为`NULL`的情况。
2. 分治，只需要分清楚`mid`和`start`和`end`的关系即可。

### [203. 线段树的修改](http://www.lintcode.com/zh-cn/problem/segment-tree-modify/)

#### 题目：

对于一棵 最大线段树, 每个节点包含一个额外的 max 属性，用于存储该节点所代表区间的最大值。  

设计一个`modify` 的方法，接受三个参数 `root`、 `index` 和 `value`。该方法将 `root` 为根的线段树中 `[start, end] = [index, index]` 的节点修改为了新的 `value` ，并确保在修改后，线段树的每个节点的 `max` 属性仍然具有正确的值。

#### 分析：

和[202. 线段树的查询](http://www.lintcode.com/zh-cn/problem/segment-tree-query/)基本一样的思路，只需要在递归基的时候加一行赋值代码即可。

### [248. 统计比给定整数小的数的个数](http://www.lintcode.com/zh-cn/problem/count-of-smaller-number/)

#### 题目：

给定一个整数数组 （下标由 `0` 到 `n-1`，其中 `n` 表示数组的规模，数值范围由 `0` 到 `10000`），以及一个 查询列表。对于每一个查询，将会给你一个整数，请你返回该数组中小于给定整数的元素的数量。

#### 分析：

这道题实际上就是将线段树综合起来，可以在此重新写一遍线段树的构造，修改，查询。

### [726. 验证满二叉树](http://www.lintcode.com/zh-cn/problem/check-full-binary-tree/)

#### 题目：

如果一棵二叉树所有节点都有零个或两个子节点, 那么这棵树为满二叉树. 反过来说, 满二叉树中不存在只有一个子节点的节点. 

#### 分析：

1. 分治。

### [二分法](http://www.lintcode.com/zh-cn/tag/binary-search/)

### [60.搜索插入位置](http://www.lintcode.com/zh-cn/problem/search-insert-position/)

#### 题目：

给定一个排序数组和一个目标值，如果在数组中找到目标值则返回索引。如果没有，返回到它将会被按顺序插入的位置。
你可以假设在数组中无重复元素。

#### 分析：

基本思路二分法，二分法并不难，但是关键的地方在于当找不到元素的时候如何正确的返回比target大的最小值的元素。在循环过程中不断的向target逼近。

### [61.搜索区间](http://www.lintcode.com/zh-cn/problem/search-for-a-range/)

#### 题目：

给定一个包含 n 个整数的排序数组，找出给定目标值 target 的起始和结束位置。
如果目标值不在数组中，则返回[-1, -1]  

#### 分析：

1. 和60搜索插入位置类似都是二分查找法
2. 要注意的是对于重复元素，这样就只能用60搜索插入位置的版本1来做。

### [28. 搜索二维矩阵](http://www.lintcode.com/zh-cn/problem/search-a-2d-matrix/)

#### 题目：

写出一个高效的算法来搜索 m × n矩阵中的值。这个矩阵具有以下特性：

1. 每行中的整数从左到右是排序的。
2. 每行的第一个数大于上一行的最后一个整数。

#### 分析：

先对行首元素进行一次二分，找到插入位置[60.搜索插入位置](http://www.lintcode.com/zh-cn/problem/search-insert-position/)，然后对该行进行二分。

### [662. 猜数游戏](http://www.lintcode.com/zh-cn/problem/guess-number-game/)

#### 题目：

我们正在玩猜数游戏。 游戏如下：  
我从 1 到 n 选择一个数字。 你需要猜我选择了哪个号码。  
每次你猜错了，我会告诉你这个数字是高还是低。  
你调用一个预定义的接口 `guess(int num)`，它会返回 3 个可能的结果(-1，1或0):  

#### 分析：

二分法，注意这里不能按照往常使用[l,r)，可能会溢出。

### [141. x的平方根](http://www.lintcode.com/zh-cn/problem/sqrtx/)

#### 题目：

实现 `int sqrt(int x)` 函数，计算并返回 x 的平方根

#### 分析：

二分法，注意溢出。

### [62.搜索旋转排序数组](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/)

1. 基本思路仍是二分法，只是现在找出mid后，mid可能只有一边有序，另一边无序了，但是我们可以拿有序那边做判断，因为是有序，很容易判断出target在不在，如果不在就直接将范围缩小到另一端。

### [63.搜索排序旋转数组II](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array-ii/)

#### 题目：

跟进[62.搜索旋转排序数组](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/)，假如有重复元素又将如何？  
是否会影响运行时间复杂度？  
如何影响？  
为何会影响？  
写出一个函数判断给定的目标值是否出现在数组中。

#### 分析：

代码同62搜索旋转排序数组一样

### [159. 寻找旋转排序数组中的最小值](http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array/)

#### 题目：

假设一个旋转排序的数组其起始位置是未知的（比如`0 1 2 4 5 6 7` 可能变成是`4 5 6 7 0 1 2`）。你需要找到其中最小的元素。  
你可以假设数组中不存在重复的元素。

#### 分析：

1. 二分法，思路和[62.搜索旋转排序数组](http://www.lintcode.com/zh-cn/problem/search-in-rotated-sorted-array/)是一样的，我们主要来判断mid这个位置左右是不是均有序的。
2. 关键是如何判断mid左右是否有序，我们直接和最左端和最右端的元素比较就行。

### [160. 寻找旋转排序数组中的最小值 II](http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array-ii/)

#### 题目：

假设一个旋转排序的数组其起始位置是未知的（比如`0 1 2 4 5 6 7` 可能变成是`4 5 6 7 0 1 2`）。你需要找到其中最小的元素。  
数组中可能存在重复的元素。

#### 分析：

1. 二分法，思路和[159. 寻找旋转排序数组中的最小值](http://www.lintcode.com/zh-cn/problem/find-minimum-in-rotated-sorted-array/)是一样的
2. 唯一的不同在31行代码处，加入了去重。

### [76. 最长上升子序列](http://www.lintcode.com/zh-cn/problem/longest-increasing-subsequence/)

#### 题目：

给定一个整数序列，找到最长上升子序列（LIS），返回LIS的长度。

#### 说明：

最长上升子序列的定义：最长上升子序列问题是在一个无序的给定序列中找到一个尽可能长的由低到高排列的子序列，这种子序列不一定是连续的或者唯一的。[WIKI百科](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)

#### 分析：

1. 动态规划。
2. 二分法，实际上就是在循环的过程中我们用到了二分法。这种方法有点类似于贪心，就是我们每次选一个数，让这个数刚刚数组的前一个数，这样可以为后面的数留出更多选择余地，如何选择这个数？就是[60.搜索插入位置](http://www.lintcode.com/zh-cn/problem/search-insert-position/)的思路，我们搜索插入位置，然后将这个位置的数替换掉。

### [617. 最大平均值子数组](http://www.lintcode.com/zh-cn/problem/maximum-average-subarray/)

#### 题目：

给出一个整数数组，有正有负。找到这样一个子数组，他的长度大于等于 k，且平均值最大。

#### 样例：

给出 `nums = [1, 12, -5, -6, 50, 3]`, `k = 3`  
返回 `15.667 // (-6 + 50 + 3) / 3 = 15.667`

#### 分析：

首先最后要找的平均值肯定在这个nums的最小值min和最大值max之间，所以我们是对min和max进行二分，然后每次取到一个mid，就看看这个数组里是否有这样的子数组的平均值大于这个mid，如果大于mid，那我们就在`[mid, max]`之间寻找，否则就在`[min,mid]`寻找。  
然后我们如何在nums里查找是否有其子数组平均值大于mid，此时我们需要用一个新的数组`num[nums.size() + 1]`，然后我们让`num[0]=0`，然后我们遍历nums，每次都让`num[i+1] = num[i] + nums[i] - mid`，这样对于num数组的每个元素都代表了从索引0到当前索引的元素之和与mid的差值，同时`num[i + 1]-num[j]`代表了从i到j子数组的平均值，然后当我们遍历k个数之后，就开始判断这个差值，这个差值大于0的时候，就可以说有这么一个子数组符合条件。  
代码的`minaverage = min(minaverage, array[i + 2 - k]);`是要找到当前位置k个数之前的所有子数组的平均值的最小值，这样我们那当前位置的num[i]减去这个最小值即为当前平均值的最大值。

### [栈](http://www.lintcode.com/problem/?tag=stack)

### [队列](http://www.lintcode.com/problem/?tag=queue)

### [40. 用栈实现队列](http://www.lintcode.com/zh-cn/problem/implement-queue-by-two-stacks/)

#### 题目：

正如标题所述，你需要使用两个栈来实现队列的一些操作。  
队列应支持`push(element)`，`pop()` 和 `top()`，其中`pop`是弹出队列中的第一个(最前面的)元素。  
`pop`和`top`方法都应该返回第一个元素的值。

#### 分析：

我们只需要保存两个stack，用第二个栈来保存第一个栈的依次出栈元素即可。

### [685. 数据流中第一个唯一的数字](http://www.lintcode.com/zh-cn/problem/first-unique-number-in-stream/)

#### 题目：

给一个连续的数据流,写一个函数返回终止数字到达时的第一个唯一数字（包括终止数字）,如果在终止数字前无唯一数字或者找不到这个终止数字, 返回 `-1`.

#### 样例：

给一个数据流 `[1, 2, 2, 1, 3, 4, 4, 5, 6]` 以及一个数字 `5`, 返回 `3`  
给一个数据流 `[1, 2, 2, 1, 3, 4, 4, 5, 6]` 以及一个数字 `7`, 返回 `-1`  

#### 分析：

1. 使用哈希做，我们只需要保存每个数字的出现顺序，直到出现target停止，然后再遍历数组，找到第一个出现一次的数字即可。
2. 队列，暂未实现。

### [423. 有效的括号序列](http://www.lintcode.com/zh-cn/problem/first-unique-number-in-stream/)

#### 题目：

给定一个字符串所表示的括号序列，包含以下字符： `'(', ')'`, `'{', '}'`, `'['` and `']'`， 判定是否是有效的括号序列。

#### 样例：

括号必须依照 `"()"` 顺序表示， `"()[]{}"` 是有效的括号，但 `"([)]"`则是无效的括号。

#### 分析：

1. 栈的简单应用。