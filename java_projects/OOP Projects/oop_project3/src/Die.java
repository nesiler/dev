import java.util.Random;

public class Die {

    int nextRoll() {
        Random random = new Random();
        return random.nextInt(5) + 1;
    }


}
