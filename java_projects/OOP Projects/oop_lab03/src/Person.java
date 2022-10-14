public class Person {
    String id;
    String gender;
    double tChol;
    double hdl;

    public Person(String id, String gender, double tChol, double hdl) {  //cons
        this.id = id;
        this.gender = gender;
        this.tChol = tChol;
        this.hdl = hdl;
    }

    public static void main(String[] args) { //test

        Person enes = new Person("00222123456", "male", 200, 40);
        Person diler = new Person("00333123456", "female", 198, 44);

        enes.printReport();
        System.out.println();
        diler.printReport();


    }

    public double getCholesterolRatio() { //Returns cholesterol ratio.

        return tChol / hdl;

    }

    public boolean hasGoodTotalCholesterol() { //Returns true if total cholesterol smaller than 200.

        return tChol < 200;

    }

    public boolean hasGoodHDL() {  // Compares hdl by gender and returns true if the hdl value is greater than the specified value.

        if (gender.equalsIgnoreCase("FEMALE") && hdl >= 45) return true;

        else return gender.equalsIgnoreCase("MALE") && hdl >= 40;

    }

    public boolean hasGoodCholesterolRatio() { //Compares cholesterol ratio by gender and returns true if the ratio is less than specified ratio.

        if (gender.equalsIgnoreCase("FEMALE") && getCholesterolRatio() <= 4.5) return true;

        else return gender.equalsIgnoreCase("MALE") && getCholesterolRatio() <= 4.5;

    }

    public void printReport() { //Prints the report showing whether the cholesterol values are good or bad.

        System.out.println(id + "'s Report: ");
        System.out.println("Total Cholesterol : " + tChol + (hasGoodTotalCholesterol() ? " (Good)" : " (Bad)"));
        System.out.println("HDL : " + hdl + (hasGoodHDL() ? " (Good)" : " (Bad)"));
        System.out.println("TC/HDL Ratio : " + getCholesterolRatio() + (hasGoodCholesterolRatio() ? " (Good)" : " (Bad)"));

    }
}
