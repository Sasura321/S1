/*
**����
*/
void Swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/*
**��������(����)
*/
// �Ӻ���ǰ˳����
// ���������ȶ�
// ʱ�临�Ӷȣ��O��n^2��,ƽ��O(n^2),�O��n��
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
	//�ֱ�����в���
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
**shell(ϣ��)����
*/
// ���ȶ�
// ʱ�临�Ӷ� ��O(n^1.2 - n^1.3)
void ShellSort(int array[], int size)
{
	int g, i, j;
	int gap = size;
	int key;

	// �� gap ��Ϊ 1 ʱ����Ԥ���򣬵� gap == 1ʱ���������һ�β���
	while (1){
		gap = gap / 3 + 1;

		// һ���� gap ��
		for (g = 0; g < gap; g++){
			// �ֱ���������� 
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

// ϣ������ĳ���д��
void ShellSortNor(int array[], int size)
{
	int gap = size;

	// �� gap ��Ϊ 1 ʱ����Ԥ���򣬵� gap == 1ʱ���������һ�β���
	while (1){
		gap = gap / 3 + 1;

		__InsertSort(array, size, gap);

		if (gap == 1){
			break;
		}
	}
}

/*
**���µ���
*/
void AdjustDown(int array[], int size, int root)
{
	int left, right;
	int maxChild;

	while (1){
		left = 2 * root + 1;  // �����±�
		right = 2 * root + 2; // �Һ����±�
		if (left >= size){
			//����Խ�磬���� root ��Ҷ�ӽ��
			return;
		}

		// ȷ�����Һ���˭�����ĺ���
		maxChild = left;
		if (right<size && array[left] < array[right]){
			maxChild = right;
		}

		if (array[root] >= array[maxChild]){
			//�Ѿ��������ѵ�����
			return;
		}

		Swap(array + root, array + maxChild);
		root = maxChild;
	}
}

/*
**������
*/
// ���ȶ�
// ʱ�临�Ӷ�  ƽ��/ ���/ �  O(n*log(n))
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
**ѡ������
*/
// ʱ�临�Ӷȣ� ���/ ƽ��/ � O(n^2)
// �ռ临�Ӷȣ� O(1)
// һ��ѡ���ĺ���С��
void SelectSortOP(int array[], int size)
{
	//����ұ�
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
		//�����������ҵ����ĺ���С�ģ��ֱ���� [minPos],[maxPos]
		Swap(array + minSpace, array + minPos); // ���ҵ�����С�����������ʼ����
		if (minSpace == maxPos){
			maxPos = minPos;
		}
		Swap(array + maxSpace, array + maxPos); // ���ҵ�����������������β�ͽ���

		minSpace++;
		maxSpace--;
	}
}

/*
**��������
*/
// ���׼ֵ
void BubbleSort(int array[], int size)
{
	int isOrdered;
	for (int i = 0; i < size - 1; i++){
		isOrdered = 1;  // �����Ѿ�������
		for (int j = 0; j < size - 1 - i; j++){
			if (array[j]>array[j + 1]){
				Swap(array + j, array + j + 1);
				isOrdered = 0; //ȷ��������
			}
		}

		if (isOrdered == 1){
			break;
		}
	}
}

// Hover / ����ָ��
// ����ұ�����
// ѡ�Ļ�׼ֵ�������ұߣ�����ҪҪ�ȶ� begin
int Partion_1(int array[], int left, int right)
{
	int pivot = array[right];
	int begin = left;
	// end ��Ҫ�� right�������� [�Ѿ����������]
	int end = right;

	// begin �� end ͣ����
	while (begin < end) {
		// ��Ҫ���������ж� begin �� end �Ĺ�ϵ
		// ������ [�Ѿ����������]
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
// �ڿӷ�
// ����ұ�����
// ѡ�Ļ�׼ֵ�������ұߣ�������Ҫ�ȶ� begin
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

// ǰ��ָ�뷨
// ����ұ�����
// ѡ�Ļ�׼ֵ�������ұߣ�����Ҫ�ȶ� begin
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

// ����ұ�����[left,rigth]
void __QuickSort(int array[], int left, int right)
{
	if (left == right){
		// ������ֻ��һ���������򣬲���Ҫ������
		return;
	}

	if (left > right){
		// ������û�����ˣ����Բ���Ҫ����
		return;
	}

	int pivot = array[right];// ѡ���ұߵ�һ����Ϊ��׼ֵ
	int div = Partion_3(array, left, right);	// [div] �Ż�׼ֵ
	__QuickSort(array, left, div - 1);
	__QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size)
{
	__QuickSort(array, 0, size - 1);
}

/*
**�鲢����
*/
// �ϲ�������������
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
	
	//��ֵʣ���������
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
		// ֻʣһ������һ������
		return;
	}

	if (left >= right) {
		//������û������
		return;
	}

	int mid = left + (left + right) / 2;
	// [left, mid)
	// [mid, right)
	// ΪʲôҪ�� mid ���ұ�

	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);
	// �õ�������������
	Merge(array, left, mid, right, extra);
}

// ʱ�临�Ӷ�	O(nlog(n))
// �ռ临�Ӷ�	O(n)
// �ȶ�
// �ⲿ����
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