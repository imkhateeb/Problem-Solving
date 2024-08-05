public class Car {
    private String brand;
    private String model;
    private int year;

    // Constructor
    public Car(String brand, String model, int year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }

    // Methods
    public void displayInfo() {
        System.out.println(year + " " + brand + " " + model);
    }
    public void accelerate() {
        System.out.println("The " + brand + " " + model + " is accelerating!");
    }

    // Getter methods
    public String getBrand() { return brand; }
    public String getModel() { return model; }
    public int getYear() { return year; }

    // Main method for demonstration
    public static void main(String[] args) {
        // Creating objects
        Car car1 = new Car("Toyota", "Corolla", 2020);
        Car car2 = new Car("Tesla", "Model 3", 2021);

        // Using object methods
        car1.displayInfo();
        car2.accelerate();

        // Accessing object data through getter methods
        System.out.println("Car 1 is a " + car1.getBrand());
        System.out.println("Car 2 is a " + car2.getYear() + " model");
    }
}