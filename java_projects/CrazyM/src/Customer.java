/**
 *Muhammed Enes Diler
 *19120205016
 *Crazy Market Simülatör
 **/
public class Customer {
    int id; //müşteri no
    int arrivalTime;  //geliş zamanı
    int removalTime; //çıkış zamanı
    int totalWaitTime; //toplam beklediği zaman
    boolean checkedArrival = false; //gelenleri yazdırmak için yardımcı değişken

    public Customer(int id, int arrivalTime, int removalTime) { //constructor

        this.id = id;
        this.arrivalTime = arrivalTime;
        this.removalTime = removalTime;
        this.totalWaitTime = removalTime - arrivalTime;

    }

    public void customerInfo() {  //müşteri bilgisi yazdirir

        System.out.print("No: " + id + "  -  AT: " + arrivalTime + "  -  RT: " + removalTime + "  -  Total Wait Time: " + totalWaitTime + "\n");

    }
}
