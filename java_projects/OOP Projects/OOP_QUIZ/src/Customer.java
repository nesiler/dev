/*Enes Diler 19120205016
OOP Lab01 - Class definition
 */
public class Customer {
    String name;
    int accountID;
    int balance;


    public Customer(String name, int accountID, int balance) {
        this.name = name;
        this.accountID = accountID;
        this.balance = balance;
    }

    public static void main(String[] args) {
        Customer customer1 = new Customer("Ali",111,3000);
        Customer customer2 = new Customer("Ayse",222,2000);
        System.out.println("Customer A Name: "+customer1.name + " ID: " + customer1.accountID + " Balance: " + customer1.balance);
        System.out.println("Customer B Name: "+customer2.name + " ID: " + customer2.accountID + " Balance: " + customer2.balance);
        System.out.println("Balance difference: " + Math.abs(customer2.balance-customer1.balance));
    }
}
