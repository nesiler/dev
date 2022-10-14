public interface DiePlayer {

    /*
    * myScore: score of the current player
    * turnTotal: accumulated score in the current turn
    * maxScore: the maximum score among all players
    * rolls: number of times the player has rolled in the current turn
    * */

    boolean isRolling(int myScore, int turnTotal, int maxScore, int rolls);
}
