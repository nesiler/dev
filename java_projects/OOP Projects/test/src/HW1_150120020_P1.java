//Mustafa Said Canak	150120020
//This program calculates the cost of driving by taking inputs for driving distance, miles per gallon and price per gallon from the user.

import java.util.Scanner;

public class HW1_150120020_P1 {

	public static void main(String[] args) {
		
		//Take the driving distance, miles per gallon and price per gallon from the user.
		Scanner input = new Scanner(System.in);
		System.out.print("Enter the driving distance: ");
		double distance = input.nextDouble();
		System.out.print("Enter miles per gallon: ");
		double milesPerGallon = input.nextDouble();
		System.out.print("Enter price per gallon: ");
		double pricePerGallon = input.nextDouble();
		
		//Compute the cost of driving
		double costOfDriving = distance / milesPerGallon * pricePerGallon;
		
		//Show the output to the user
		System.out.println("The cost of driving is $" + (int)(costOfDriving * 100) / 100.0);
		input.close();
		

	}

}
