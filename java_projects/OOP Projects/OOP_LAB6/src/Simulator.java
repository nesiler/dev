public class Simulator {

    public static void main(String[] args) {
        DoorMan[] doormen;
        Slayer slayer;
        ZombieCounter zc = new ZombieCounter();
        slayer = new Slayer(zc);
        int n = Integer.parseInt(args[0]);
        doormen = new DoorMan[n];

        for (int i = 0; i < n; i++) {
            doormen[i] = new DoorMan(zc);
        }

        for (int i = 0; i < n; i++) {
            doormen[i].start();
        }
        slayer.start();

        try {
            slayer.join();
            for (int i = 0; i < n; i++) {
                doormen[i].join();
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("Killed zombies: " + zc.getKilledCount());
        System.out.println("Zombies in the room: " + zc.getInTheRoomCount());

        if (zc.tooManyZombiesInTheRoom()) {
            System.out.println("You Lost!");
        } else if (zc.killed100Zombies()) {
            System.out.println("You Won!");
        }

    }

}
