//Mustafa Said Canak	150120020

//This program shows a date as year/month/day by taking total day from the user.

import java.util.Scanner;

public class HW1_150120020_P2 {

	public static void main(String[] args) {
		
		
		//Take total day from user 
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the total day as positive integer: ");
		int totalDay = input.nextInt();	
		
		//Compute number of year, month, day
		int years = totalDay / 365;
		int remainingTotalDay = totalDay % 365;
		int months = remainingTotalDay / 31;
		remainingTotalDay = remainingTotalDay % 31;
		int days = remainingTotalDay;
		
		//Show the output to the user
		System.out.println("Number of days: " + totalDay);
		System.out.println("Year: " + years +  ", Month: " + months + ", Day: " + days + ".");
		

		input.close();

	}

}
