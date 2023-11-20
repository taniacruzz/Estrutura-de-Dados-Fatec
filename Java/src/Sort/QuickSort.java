package Sort;

public class QuickSort{

    
    public void doQuickSort (int[] num, int j, int positionPivot ) {
        int i = j - 1;       
        int reserv;
        int pivot = num[positionPivot];
        while (j <= positionPivot) {
            if (num[j] <= pivot) {
                ++i;
                reserv = num[i];
                num[i] = num[j];
                num[j] = reserv;
            }
            ++j;
        }
        if (i >= 2) {
            doQuickSort(num, 0, i - 1);
        } 
        if (positionPivot - i >= 2) {
            doQuickSort(num, i + 1, positionPivot);
        }
    }
}
