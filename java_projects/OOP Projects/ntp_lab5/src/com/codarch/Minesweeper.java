package com.codarch;

import java.util.Arrays;
import java.util.Random;


public class Minesweeper {

    boolean[][] mineField; // board with mines marked as true
    int rows; // number of rows of the board
    int cols; // number of columns of the board
    int numMines;

    public Minesweeper(int rows, int cols, int numMines) {

        this.rows = rows;
        this.cols = cols;
        this.numMines = numMines;
        mineField = new boolean[rows][cols];
        generateBoard();
    }


    public void generateBoard() {

        Random random = new Random();

        int r = 0;
        int c = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mineField[i][j] = false;
            }
        }

        for (int i = 1; i != numMines + 1; i++) {

            r = random.nextInt(rows);
            c = random.nextInt(cols);

            if (mineField[r][c] != true)
                mineField[r][c] = true;
            else
                i--;

        }
    }

    public int[][] generateClues() {
        int[][] clue = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                clue[i][j] = countMines(i, j);

            }
        }
        return clue;
    }

    public int countMines(int r, int c) {
        int count = 0;
        if (mineField[r][c])
            return -1;
        else {
            for (int i = 0; i < rows; i++)

                for (int j = 0; j < cols; j++)

                    if ((i == r + 1 || i == r - 1 || i == r) && (j == c + 1 || j == c - 1 || j == c))
                        if (mineField[i][j])
                            count++;
        }
        return count;
    }


    public void printClues(int[][] clues) {
        for (int i = 0; i < rows; i++) {
            System.out.println();
            for (int j = 0; j < cols; j++) {
                System.out.print(clues[i][j] + "  ");
            }
        }
    }

    public static void main(String[] args) {
        Minesweeper m = new Minesweeper(6, 6, 3);
        int[][] c = m.generateClues();
        m.printClues(c);

    }

}