import java.util.LinkedList;
import java.util.List;

public class BruteForce {

    List<Integer> list1 = new LinkedList<Integer>();
    List<Integer> list2 = new LinkedList<Integer>();
    int x; //100,500,1000
    int[] dist;
    int[] gain;

    public BruteForce(int x, int[] dist, int[] gain) {
        this.x = x;
        this.dist = dist;
        this.gain = gain;
    }

    public void solve() {
        int max = 0, distance = 0, total = 0;
        for (int j = 0; j <= dist.length - 1; j++) {
            for (int i = j; i <= dist.length - 1; i++) {
                while (i <= dist.length - 1) {
                    System.out.println("while in i:" + i);
                    distance += dist[i];
                    System.out.println("distance: " + distance);

                    if (distance >= x) {
                        list1.add(i);
                        break;
                    }
                    i++;
                }
                distance = 0;
            }
        }
    }

    public void result() {

        for (int i = 0; i < list1.size(); i++) {
            System.out.println(list1.get(i));
        }
    }

    public void compare(){

    }


}
