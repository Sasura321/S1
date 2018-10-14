//3. 使用递归实现快速排序(Java实现) 
public class QuickSort
{
    public static void main(String[] args){
        int[] array = {6, 5, 1, 2, 4, 3, 9, 7, 8};
        int low = 0;
        Sort(array,low,8);
        PrintSort(array,low,8);
    }

    public static int Quick(int[] array,int low,int high){
        int pivot = array[high];
        int div = low;
        int cur = low;
        int tmp = 0;
        for (cur = low; cur <= high; cur++){
            if (array[cur] < pivot){
                tmp = array[cur];
                array[cur] = array[div];
                array[div]= tmp;
                div++;
            }
        }

        tmp = array[high];
        array[high] = array[div];
        array[div]= tmp;

        return div;
    }

    public static void Sort(int[] array,int low,int high){
         if (low == high){
        return;
        }
        if (low > high){
            return;
        }

        int mid = Quick(array, low, high);
        Sort(array, low, mid-1);
        Sort(array, mid+1, high);
    }

    public static void PrintSort(int[] array, int low, int high){
        int i = 0;
        for(i=low; i<=high; i++){
            System.out.print(array[i]+"  ");
        }
    }
}

