/**
*Muhammed Enes Diler
*19120205016
*Crazy Market Simülatör
**/
import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Random;

public class CrazyMarket implements MyQueue<Customer> {
    public static final String ANSI_RESET = "\u001B[0m"; //çıktı için renk kodları
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_BLUE = "\033[1;94m";

    public static String tekerleme = "O piti piti karamela sepeti " //default tekerleme
            + "\nTerazi lastik jimnastik " + "\nBiz size geldik bitlendik Hamama gittik temizlendik";

    public int size; //anlık durumu yazdırmak için tutucu değişkenler
    public int done;

    Node<Customer> head; //liste başının tanımı

    public CrazyMarket(int numberOfCustomer) { //tekerleme olmadan kuyruk simulasyonu için constructor

        done = 0; //tamamlanan müşteri sayısı
        int arrivalT = 0;
        int removalT = 0;
        int currentTime = 0; //simulasyon saati
        int i = 0; //while değişkeni
        done = 0;
        CrazyIterator iterator = new CrazyIterator(); //iterator tanımı
        Random random = new Random(); //rastgele sayılar için random tanımı

        System.out.println(ANSI_BLUE + "============================================================================================" + ANSI_RESET);
        System.out.println(ANSI_BLUE + "============================= Normal Kuyruk Simülasyonu Başladı ============================" + ANSI_RESET);
        System.out.println(ANSI_BLUE + "============================================================================================" + ANSI_RESET);

        while (done < numberOfCustomer) { //numberOfCustomer kadar müşteri getirecek en kapsamlı while

            time(currentTime); //her döngüde simulasyon saatini yazar

            arrivalT += random.nextInt(3); //geliş zamanları her seferinde 0-2 arasında değer alarak artar
            if (i < 1) { //ilk eleman için zaman tanımları
                removalT = arrivalT + (random.nextInt(3) + 1); //çıkış zamanı
                enqueue(new Customer(i + 1, arrivalT, removalT)); //kuyruğa yeni müşteri ekler
                printArrival(currentTime); //gelen müşterileri yazar
                ++i;
            } else { //sonraki bütün elemanlar için zamanlar
                removalT += (random.nextInt(3) + 1);  //rastgele sayı üretip önveki müşterinin çıkış zamanına ekler
                enqueue(new Customer(i + 1, arrivalT, removalT));
                printArrival(currentTime);
                ++i;
            }

            while (true) { //çıkış zamanı gelen müşterileri çıkarmak için döngü
                if (iterator.hasNext() && get(0).removalTime <= currentTime) {
                    System.out.println(ANSI_RED + "----------------------Sıranın Başından Müşteri Çıkarılıyor----------------------\n" + ANSI_YELLOW + "Çıkarılan Müşteri Bilgileri: ");
                    dequeuNext().customerInfo(); //currenttime çıkış zamanına geldiyse kuyruktan siler ve yazdırır
                } else {
                    break; //çıkış zamanı gelen müşteri yoksa döngü biter
                }
            }
            currentTime++; //simulasyon zamanı artar
        }
        time(currentTime);
        printQue(); //simulasyon bittikten sonra kalan kuyruğu yazdırır
    }

    public CrazyMarket(int numberOfCustomer, String tekerleme) {

        done = 0; //tamamlanan müşteri sayısı
        int arrivalT = 0;
        int removalT = 0;
        int currentTime = 0; //simulasyon saati
        int i = 0; //while değişkeni
        done = 0;
        CrazyIterator iterator = new CrazyIterator(); //iterator tanımı
        Random random = new Random(); //rastgele sayılar için random tanımı

        System.out.println(ANSI_BLUE + "============================================================================================" + ANSI_RESET);
        System.out.println(ANSI_BLUE + "============================= Crazy Kuyruk Simülasyonu Başladı =============================" + ANSI_RESET);
        System.out.println(ANSI_BLUE + "============================================================================================" + ANSI_RESET);

        while (done < numberOfCustomer) { //numberOfCustomer kadar müşteri getirecek en kapsamlı while

            time(currentTime); //her döngüde simulasyon saatini yazar

            if (i < 1) { //ilk eleman için zaman tanımları
                arrivalT += random.nextInt(3);
                removalT = arrivalT + (random.nextInt(3) + 1); //çıkış zamanı
                enqueue(new Customer(i + 1, arrivalT, removalT)); //kuyruğa yeni müşteri ekler
                printArrival(currentTime); //gelen müşterileri yazar
                ++i;
            } else { //gelecek müşteriler için zaman tanımları
                arrivalT += random.nextInt(3);
                removalT += (random.nextInt(3) + 1); //rastgele sayı üretip önceki müşterinin çıkış zamanına ekler
                enqueue(new Customer(i + 1, arrivalT, removalT));
                printArrival(currentTime);
                ++i;
            }

            while (true) { //çıkış zamanı gelen müşterileri çıkarmak için döngü
                if (iterator.hasNext() && get(0).removalTime <= currentTime) {
                    if (get(0).totalWaitTime >= 10) { //toplam bekleme süresi 10 dan büyükse baştan müşteri çıkarır
                        System.out.println(ANSI_RED + "----------------------Sıranın Başından Müşteri Çıkarılıyor----------------------\n" + ANSI_YELLOW + "Çıkarılan Müşteri Bilgileri: ");
                        get(0).removalTime = currentTime; //çıkış yapan müşterinin bilgileri güncellenir
                        get(0).totalWaitTime = get(0).removalTime - get(0).arrivalTime;
                        dequeuNext().customerInfo();
                    } else { //10 dan küçükse tekerleme ile seçim yapar ve seçilen müşteriyi çıkarır
                        if (chooseCustomer().arrivalTime <= currentTime) { //seçilen müşterinin gelme zamanı kontrol edilir -aksi taktirde bug oluyor
                            removalIncreaser((vowelCounter(tekerleme) % size())); //seçilen müşteriye kadar olan müşterilere ek bekleme süresi
                            System.out.println(ANSI_RED + "----------------------Tekerleme ile Müşteri Çıkarılıyor----------------------\n" + ANSI_YELLOW + "Çıkarılan Müşteri Bilgileri: ");
                            chooseCustomer().removalTime = currentTime;
                            chooseCustomer().totalWaitTime = chooseCustomer().removalTime - chooseCustomer().arrivalTime; //tekerleme ile seçilen müşterinin bilgilerinin güncellenmesi
                            dequeuWithCounting(tekerleme).customerInfo();
                        }
                        break;
                    }
                } else {
                    break;
                }
            }
            currentTime++;
        }
        time(currentTime);
        printQue();
    }

    public static void main(String[] args) {
        CrazyMarket normal;
        CrazyMarket crazy;
        normal = new CrazyMarket(25);
        crazy = new CrazyMarket(50, tekerleme);
    }

    public void removalIncreaser(int index) { //tekerleme ile seçilirken sırası kaynayan müşterilere +1 bekleme süresi

        for (int i = 0; i < index; i++) {
            get(i).removalTime++;
            get(i).totalWaitTime = get(i).removalTime - get(i).arrivalTime; //toplam bekleme süresi yeniden tanımlanır
        }
    }

    public void time(int time) { //zaman yazdırır
        System.out.print(ANSI_PURPLE + "\n---Time:" + time + " ---Sıradaki Müşteri Sayısı:" + size + " ---Hizmet Gören Müşteri Sayısı:" + done + "\n" + ANSI_YELLOW);
    }

    public boolean printArrival(int currentTime) { //gelen müşterileri yazdirir

        for (int i = 0; i <= size(); i++) {
            if (get(i).arrivalTime <= currentTime && !get(i).checkedArrival) {
                get(i).checkedArrival = true; //bir kez yazılanı bir daha yazmamak için değişken
                System.out.print(ANSI_GREEN + "+++++++++++++++++++++++++ " + get(i).id + " No'lu Müşteri Sıraya Girdi +++++++++++++++++++++++++" + ANSI_YELLOW + "\nMüşteri Bilgileri -> ");
                get(i).customerInfo();
                size++;
            } else {
                continue;
            }
        }
        return true;
    }

    public Customer chooseCustomer() { // :)
        Node temp;
        int index = vowelCounter(tekerleme) % size(); //tekerleme hesabı -mod- ile
        if (index == 0) { //tekerleme sonucu ilk eleman ise
            return head.data;
        } else {
            Node n = head;
            Node n1 = null;
            for (int i = 0; i < index - 1; i++) {
                n = n.next;
            }
            n1 = n.next;
            return (Customer) n1.data; //çıkarılanı döner(bilgilerin yazdırılması için)
        }
    }

    public int vowelCounter(String tekerleme) { //tekerlemedeki sesli harfleri hesaplar
        int vowels = 0;
        tekerleme = tekerleme.toLowerCase();
        for (int i = 0; i < tekerleme.length(); ++i) {
            char ch = tekerleme.charAt(i);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                ++vowels;
            }
        }
        return vowels; //sesli harf sayısı
    }

    @Override
    public int size() {
        int queuesize = 1;

        if (head == null) {
            return 0;
        } else { //listenin en sonuna eleman ekler
            Node n = head;
            while (n.next != null) { //sonuna kadar gider
                n = n.next;
                queuesize++;
            }
        }
        return queuesize;

    }

    @Override
    public boolean isEmpty() {
        return size() == 0;
    }

    @Override
    public boolean enqueue(Customer item) {
        Node node = new Node(); //node tanımı
        node.data = item;
        node.next = null;

        if (head == null) {
            head = node;
        } else { //listenin en sonuna eleman ekler
            Node n = head;
            while (n.next != null) { //sonuna kadar gider
                n = n.next;
            }
            n.next = node;
        }
        //size++;
        return false; // :(
    }

    @Override
    public Customer dequeuNext() { //listenin başından eleman çıkarır
        Node temp;
        temp = head;
        head = head.next;
        size--;
        done++;
        return (Customer) temp.data;
    }

    @Override
    public Customer dequeuWithCounting(String tekerleme) { //tekerleme ile seçilen elemanı listeden çıkarır
        Node temp;
        int index = vowelCounter(tekerleme) % size(); //tekerleme hesabı -mod- ile
        if (index == 0) { //tekerleme sonucu ilk eleman ise
            temp = head;
            head = head.next;
            size--;
            done++;
            return (Customer) temp.data;

        } else {
            Node n = head;
            Node n1 = null;
            for (int i = 0; i < index - 1; i++) {
                n = n.next;
            }
            n1 = n.next;
            n.next = n1.next;
            temp = n1; //çıkarılan elemanı dönmesi için geçici değişken
            n1 = null;
            size--;
            done++;
            return (Customer) temp.data; //çıkarılanı döner(bilgilerin yazdırılması için)
        }
    }

    @Override
    public Customer get(int index) {
        Iterator<Customer> iterator = new CrazyIterator(); //iterator tanımı
        for (int i = 0; i < index - 1 && iterator.hasNext(); i++) { //verilen indekse kadar ilerler
            iterator.next();
        }
        return iterator.next();
    }

    @Override
    public void printQue() {
        Iterator<Customer> iterator = new CrazyIterator(); //listede ilerlemek için iterator
        System.out.println(ANSI_CYAN + "*******************************************************************************");
        while (iterator.hasNext()) {
            iterator.next().customerInfo();
        }
        System.out.println("*******************************************************************************" + ANSI_RESET);
    }

    @Override
    public Iterator<Customer> iterator() {
        return new CrazyIterator();
    }

    public class CrazyIterator implements Iterator<Customer> { //custom iterator implementi

        Node<Customer> current = null; //listede gezmek için node

        @Override
        public boolean hasNext() { //sonrasında eleman var mı?

            if (current == null && head != null) {
                return true;
            } else if (current != null) {
                return current.next != null;
            }
            return false;
        }

        @Override
        public Customer next() { //sonraki elemana gider
            if (current == null && head != null) {
                current = head;
                return head.data;
            } else if (current != null) {
                current = current.next;
                return current.data;
            }
            throw new NoSuchElementException(); //eleman yoksa hata fırlat
        }
    }
}