import java.util.Scanner;

public class UserDiePlayer implements DiePlayer {
    @Override
    public boolean isRolling(int myScore, int turnTotal, int maxScore, int rolls) {

        System.out.println("Your score on this tour: " + myScore);

        Scanner scanner = new Scanner(System.in);
        System.out.println("Roll or Hold?");

        String isRolling = scanner.nextLine();

        if (isRolling.isEmpty())
            return true;

        else
            return false;

    }


}
