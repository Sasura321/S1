/*
**交换
*/
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
**插入排序(升序)
*/
// 从后往前顺序找
// 可以做到稳定
// 时间复杂度：最坏O（n^2）,平均O(n^2),最坏O（n）
void InsetSort(int array[], int size)
{
	int i, j;
	int key;

	for (i = 1; i < size; i++){
		key = array[i];
		for (j = i - 1; j >= 0; j--){
			if (key < array[j]){
				array[j + 1] = array[j];
			}
			else{
				break;
			}
		}
		array[j + 1] = key;
	}
}

void __InsertSort(int array[], int size, int gap)
{
	//分别按组进行插排
	int i, j;
	int key;
	for (i = 0 + gap; i < size; i++){
		key = array[i];
		for (j = i - gap; j >= 0; j -= gap){
			if (key < array[j]){
				array[j + gap] = array[j];
			}
			else{
				break;
			}
		}
		array[j + gap] = key;
	}
}

void InsetSort2(int array[], int size)
{
	__InsertSort(array, size, 1);
}

/*
**shell(希尔)排序
*/
// 不稳定
// 时间复杂度 ：O(n^1.2 - n^1.3)
void ShellSort(int array[], int size)
{
	int g, i, j;
	int gap = size;
	int key;

	// 当 gap 不为 1 时，是预排序，当 gap == 1时，进行最后一次插排
	while (1){
		gap = gap / 3 + 1;

		// 一共排 gap 组
		for (g = 0; g < gap; g++){
			// 分别按组进行排序 
			for (i = g + gap; i < size; i += gap){
				key = array[i];
				for (j = i - gap; j >= 0; j -= gap){
					if (key < array[j]){
						array[j + gap] = array[j];
					}
					else{
						break;
					}
				}
				array[j + gap] = key;
			}
		}
		if(gap == 1){
			break;
		}
	}
}

// 希尔排序的常见写法
void ShellSortNor(int array[], int size)
{
	int gap = size;

	// 当 gap 不为 1 时，是预排序，当 gap == 1时，进行最后一次插排
	while (1){
		gap = gap / 3 + 1;

		__InsertSort(array, size, gap);

		if (gap == 1){
			break;
		}
	}
}

/*
**向下调整
*/
void AdjustDown(int array[], int size, int root)
{
	int left, right;
	int maxChild;

	while (1){
		left = 2 * root + 1;  // 左孩子下标
		right = 2 * root + 2; // 右孩子下标
		if (left >= size){
			//左孩子越界，所以 root 是叶子结点
			return;
		}

		// 确定左右孩子谁是最大的孩子
		maxChild = left;
		if (right<size && array[left] < array[right]){
			maxChild = right;
		}

		if (array[root] >= array[maxChild]){
			//已经满足最大堆的性质
			return;
		}

		Swap(array + root, array + maxChild);
		root = maxChild;
	}
}

/*
**堆排序
*/
// 不稳定
// 时间复杂度  平均/ 最好/ 最坏  O(n*log(n))
void HeapSort(int array[], int size)
{
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}

	for (int j = 0; j < size - 1; j++){
		Swap(&array[0], &array[size - 1 - j]);
		AdjustDown(array, size - j - 1, 0);
	}
}

/*
**选择排序
*/
// 时间复杂度： 最好/ 平均/ 最坏 O(n^2)
// 空间复杂度： O(1)
// 一次选最大的和最小的
void SelectSortOP(int array[], int size)
{
	//左闭右闭
	int minSpace = 0;
	int maxSpace = size - 1;

	// n/2
	while (minSpace < maxSpace){
		int minPos = minSpace;
		int maxPos = minSpace;
		for (int i = minSpace + 1; i <= maxSpace; i++){
			if (array[i] < array[minPos]){
				minPos = i;
			}

			if (array[i]>array[maxPos]){
				maxPos = i;
			}
		}
		//无序区间中找到最大的和最小的，分别放在 [minPos],[maxPos]
		Swap(array + minSpace, array + minPos); // 把找到的最小的数和区间最开始交换
		if (minSpace == maxPos){
			maxPos = minPos;
		}
		Swap(array + maxSpace, array + maxPos); // 把找到的最大的数和区间最尾巴交换

		minSpace++;
		maxSpace--;
	}
}

/*
**快速排序
*/
// 设基准值
void BubbleSort(int array[], int size)
{
	int isOrdered;
	for (int i = 0; i < size - 1; i++){
		isOrdered = 1;  // 假设已经有序了
		for (int j = 0; j < size - 1 - i; j++){
			if (array[j]>array[j + 1]){
				Swap(array + j, array + j + 1);
				isOrdered = 0; //确定无序了
			}
		}

		if (isOrdered == 1){
			break;
		}
	}
}

// Hover / 左右指针
// 左闭右闭区间
// 选的基准值放在最右边，所以要要先懂 begin
int Partion_1(int array[], int left, int right)
{
	int pivot = array[right];
	int begin = left;
	// end 需要是 right，反例是 [已经有序的序列]
	int end = right;

	// begin 和 end 停下来
	while (begin < end) {
		// 需要在条件里判断 begin 和 end 的关系
		// 反例是 [已经有序的序列]
		while (begin < end && array[begin] <= pivot) {
			begin++;
		}
		if (begin == end) {
			break;
		}
		while (begin < end && array[end] >= pivot) {
			end--;
		}
		if (begin == end) {
			break;
		}
		Swap(array + begin, array + end);
	}

	Swap(array + begin, array + right);

	return begin;
}
// 挖坑法
// 左闭右闭区间
// 选的基准值放在最右边，所以需要先动 begin
int Partion_2(int array[], int left, int right)
{
	int pivot = array[right];
	int begin = left;
	int end = right;

	while (begin < end){
		while (begin < end && array[begin] <= pivot){
			begin++;
		}
		if (begin == end){
			break;
		}

		array[end] = array[begin];
		while (begin < end && array[end] >= pivot){
			end--;
		}
		if (begin == end){
			break;
		}

		array[begin] = array[end];
	}

	array[begin] = pivot;

	return 0;
}

// 前后指针法
// 左闭右闭区间
// 选的基准值放在最右边，所需要先动 begin
int Partion_3(int array[], int left, int right)
{
	int pivot = array[right];
	int div = left;
	int cur = left;
	for (cur = left; cur <= right; cur++){
		if (array[cur] < pivot){
			Swap(array + cur, array + div);
			div++;
		}
	}

	Swap(array + right, array + div);

	return div;
}

// 左闭右闭区间[left,rigth]
void __QuickSort(int array[], int left, int right)
{
	if (left == right){
		// 区间内只有一个数，有序，不需要再排序
		return;
	}

	if (left > right){
		// 区间内没有数了，所以不需要排序
		return;
	}

	int pivot = array[right];// 选最右边的一个作为基准值
	int div = Partion_3(array, left, right);	// [div] 放基准值
	__QuickSort(array, left, div - 1);
	__QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size)
{
	__QuickSort(array, 0, size - 1);
}

/*
**归并排序
*/
// 合并两个有序数组
// [left, mid+1) [mid+1, right)
// O(n)
void Merge(int array[], int left, int mid, int right, int extra[])
{
	int left_i = left;
	int right_i = mid;
	int extra_i = left;

	while (left_i < mid && right_i < right){
		if (array[left_i] < array[right_i]){
			extra[extra_i] = array[left_i];
			extra_i++;
			left_i++;
		}
		else{
			array[extra_i] = array[right_i];
			extra_i++;
			right_i++;
		}
	}
	
	//赋值剩余的数过来
	while (left_i < mid){
		extra[extra_i++] = array[left_i++];
	}

	while (right_i < right){
		extra[extra_i++] = array[right_i++];
	}

	memcpy(array + left, extra + left, sizeof(int)*(right - left));
}

void __MergeSort(int array, int left,int right, int extra[])
{
	// [0,1)
	if (left == right - 1) {
		// 只剩一个数，一定有序
		return;
	}

	if (left >= right) {
		//区间内没有数了
		return;
	}

	int mid = left + (left + right) / 2;
	// [left, mid)
	// [mid, right)
	// 为什么要把 mid 放右边

	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);
	// 得到两个有序数组
	Merge(array, left, mid, right, extra);
}

// 时间复杂度	O(nlog(n))
// 空间复杂度	O(n)
// 稳定
// 外部排序
void MergeSort(int array[], int size)
{
	int *extra = (int *)malloc(size * sizeof(int));

	// [left, right)
	__MergeSort(array, 0, size - 1, extra);
	free(extra);
}

void MergeSortLoop(int array[], int size)
{
	int *extra = (int *)malloc(sizeof(int)*size);
	//size == 10

	for (int i = 1; i < size; i *= 2){
		for (int j = 0; j < size; j += 2 * i){
			int left = j;
			int mid = j + i;
			int right = j + i + i;

			if (mid >= size){
				continue;
			}

			if (right >= size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}

	free(extra);
}