public class ZombieCounter {
    private int count = 0;
    private int killed = 0;


    void zombieEntered() {
        count++;
    }

    void zombieKilled() {
        count--;
        killed++;
    }

    boolean tooManyZombiesInTheRoom() {
        return count > 100;
    }

    boolean killed100Zombies() {

        return killed > 100;

    }

    boolean zombiesExist() {
        return count > 0;
    }

    int getKilledCount() {
        return killed;
    }

    int getInTheRoomCount() {
        return count;
    }
}
