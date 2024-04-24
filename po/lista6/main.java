/*
 * Katrzyna Trzos
 * Lista 6 zadanie 4
 */
public class Main {
    public static void main(String[] args)
    {
        Comparable[] arr = new Comparable[]{9, -82, -2, 51, -38, 0, 15, -28, 41, 1, 8};
        MergeSort sort = new MergeSort(arr);

        sort.sort();
        sort.wypisz();
    }
}