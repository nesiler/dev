package code;

//Mustafa Said Canak	150120020
//This program calculates the compound monthly interest by taking inputs for initial principal in TL, annual interest rate percentage and number of time periods in months. 

import java.util.Scanner;

public class HW1_150120020_P3 {

	public static void main(String[] args) {
		
		//Take the inputs for initial principal in TL(p), annual interest rate percentage(r) and number of time periods in months(t)
		Scanner input = new Scanner(System.in);
		System.out.println("Enter initial principal amount in TL: ");
		double initialPrincipal = input.nextDouble();
		System.out.println("Enter annual interest rate (e.g. 4.55): ");
		double annualInterestRate = input.nextDouble();
		System.out.println("Enter number of time periods in months:");
		double numberOfTimePeriods = input.nextDouble();
		
		//Calculate the monthly interest rate percentage, total compound interest amount in TL, final balance amount in TL
		double monthlyInterestRatePercentage = annualInterestRate / 12;
		double finalBalance = initialPrincipal * (Math.pow(1 + (annualInterestRate / 1200), numberOfTimePeriods));
		double totalCompoundInterestAmount = finalBalance - initialPrincipal;
		
		//Show the output to the user
		System.out.println("Initial principal amount: " + (int)(initialPrincipal * 100) / 100.0	);
		System.out.println("Monthly interest rate: " + (int)(monthlyInterestRatePercentage * 100) / 100.0);
		System.out.println("Total compound interest amount: " + (int)(totalCompoundInterestAmount * 100) / 100.0);
		System.out.println("Final balance amount: " + (int)(finalBalance * 100) / 100.0);
		input.close();
		
		
	}

}
