package Sort;

public class Main {
    public static void main(String[] args) throws Exception {
        int[] num = {8, 5, 2, 3, 0, 4, 6, 7, 1, 18};
        
        QuickSort qs = new QuickSort();
        qs.doQuickSort(num, 0, 9);
        for (int i = 0; i < num.length; i++) {
            System.out.print(num[i]+", ");
        }
        
    }
}
