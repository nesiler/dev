import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

public class DataReader {

    public int[] getDistanceData(String dataSize) {

        String distDataPath = "resources\\Dist_";
        String fe = ".csv";
        distDataPath = distDataPath + dataSize + fe;
        String line = "";

        try {
            BufferedReader distanceReader = new BufferedReader(new FileReader(distDataPath));

            while ((line = distanceReader.readLine()) != null) {
                String[] distanceValues = line.split(",");
                return stringToArray(distanceValues);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    public int[] getGainsData(String dataSize) {

        String gainsDataPath = "resources\\Kar_";
        String fe = ".csv";
        String line = "";
        gainsDataPath = gainsDataPath + dataSize + fe;

        try {
            BufferedReader gainReader = new BufferedReader(new FileReader(gainsDataPath));

            while ((line = gainReader.readLine()) != null) {
                String[] gainValues = line.split(",");
                return stringToArray(gainValues);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    public int[] stringToArray(String[] data) {

        int[] intarray = new int[data.length];

        int i = 0;
        for (String str : data) {
            intarray[i] = Integer.parseInt(str);//Exception in this line
            i++;
        }
        return intarray;
    }

}

