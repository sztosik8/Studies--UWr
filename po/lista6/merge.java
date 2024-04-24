public class MergeSort<T extends Comparable<T>>
{
   private T[] array;

    MergeSort(T[] array) {
        this.array = array;
    }

    public void sort() {
        Sort(0, array.length - 1);
    }

    private void Sort(int beg, int end) {
        if(beg < end) {
            int mid = (beg + end) / 2;

            // watek sortujacy lewa czesc tablicy
            Thread t_left = new Thread(new Runnable() {
                @Override
                public void run() {
                    Sort(beg,mid);
                }
            });

            // watek sortujacy prawa czesc tablicy
            Thread t_right = new Thread(new Runnable() {
                @Override
                public void run() {
                    Sort(mid + 1, end);
                }
            });

            t_left.start();
            t_right.start();

            try {
                // oczekiwanie na zakonczenie watkow
                t_left.join();
                t_right.join();

                Merge(beg, mid, end);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
    // scalanie tablicy
    public void Merge(int beg, int mid, int end) {
        T[] help = (T[]) new Comparable[end - beg + 1];

        int i = beg;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= end) {
            if (array[i].compareTo(array[j]) < 0) {
                help[k++] = array[i++];
            } else {
                help[k++] = array[j++];
            }
        }

        while (i <= mid) {
            help[k++] = array[i++];
        }

        while (j <= end) {
            help[k++] = array[j++];
        }

        for (int x = 0; x < help.length; x++) {
            array[beg + x] = help[x];
        }
    }

    // wypisywanie tablicy
    public void wypisz() {
        for(int i=0; i< array.length; i++) {
            System.out.println(array[i]);
        }
    }
}