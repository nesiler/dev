/**
 *Muhammed Enes Diler
 *19120205016
 *Crazy Market Simülatör
 **/
public interface MyQueue<T> extends Iterable<T> {

    /**
     * kuruktaki toplam eleman sayisi
     */
    int size();

    /*
    kuyruk boş mu
     */
    boolean isEmpty();

    /**
     * kuyrugun sonuna item ekler
     */
    boolean enqueue(T item);

    /**
     * kuyrugun basindan eleman cikarir
     */
    T dequeuNext();

    /**
     * tekerleme metnini kullanarak bir sonraki elemani secer
     */
    T dequeuWithCounting(String tekerleme);

    /*verilen indeksteki elemanı döner*/
    T get(int index);

    /*
    kuyruğun tamamını yazdırır
     */
    void printQue();


}
