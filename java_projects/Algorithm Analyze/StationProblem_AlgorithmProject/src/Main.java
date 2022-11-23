public class Main {

    public static void main(String[] args) {
        DataReader data = new DataReader();

        int[] distances = data.getDistanceData("on");
        int[] gains = data.getGainsData("on");

        BruteForce bruteForce = new BruteForce(400, distances, gains);

        for (int i = 0; i < distances.length; i++)
            System.out.println("SN: " + (i + 1) + " Distance: " + distances[i] + " Gain: " + gains[i]);

        bruteForce.solve();
        bruteForce.result();
    }
}
