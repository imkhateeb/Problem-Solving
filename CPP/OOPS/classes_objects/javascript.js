class Car {
  constructor(brand, model, year) {
    this.brand = brand;
    this.model = model;
    this.year = year;
  }

  // Methods
  displayInfo() {
    console.log(`Car: ${this.brand} ${this.model} ${this.year}`);
  }

  accelerate() {
    console.log(`Car ${this.brand} ${this.model} is accelerating`);
  }

  // Getter methods
  getBrand() {
    return this.brand;
  }
  getModel() {
    return this.model;
  }
  getYear() {
    return this.year;
  }
}

// Creating instances of the class
const car1 = new Car("Toyota", "Corolla", 2019);
const car2 = new Car("Honda", "Civic", 2020);

// Using object methods
car1.displayInfo();
car2.accelerate();

// Using getter methods
console.log(car1.getBrand());
console.log(car2.getModel());
