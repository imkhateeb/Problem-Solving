class Car {
  private brand: string;
  private model: string;
  private year: number;

  constructor(brand: string, model: string, year: number) {
    this.brand = brand;
    this.model = model;
    this.year = year;
  }

  getInfo(): void {
    console.log(`Car: ${this.brand} ${this.model} ${this.year}`);
  }

  accelrate(): void {
    console.log(`Car ${this.brand} ${this.model} is accelerating`);
  }

  // Getter methods
  getBrand(): string {
    return this.brand;
  }
  getModel(): string {
    return this.model;
  }
  getYear(): number {
    return this.year;
  }
}

// Creating instances of the class
const car1: Car = new Car("Toyota", "Corolla", 2019);
const car2: Car = new Car("Honda", "Civic", 2020);

// Using object methods
car1.getInfo();
car2.accelrate();

// Using getter methods
console.log(car1.getBrand());
console.log(car2.getModel());
console.log(car1.getYear());
