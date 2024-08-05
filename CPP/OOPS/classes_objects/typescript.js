var Car = /** @class */ (function () {
    function Car(brand, model, year) {
        this.brand = brand;
        this.model = model;
        this.year = year;
    }
    Car.prototype.getInfo = function () {
        console.log("Car: ".concat(this.brand, " ").concat(this.model, " ").concat(this.year));
    };
    Car.prototype.accelrate = function () {
        console.log("Car ".concat(this.brand, " ").concat(this.model, " is accelerating"));
    };
    // Getter methods
    Car.prototype.getBrand = function () {
        return this.brand;
    };
    Car.prototype.getModel = function () {
        return this.model;
    };
    Car.prototype.getYear = function () {
        return this.year;
    };
    return Car;
}());
// Creating instances of the class
var car1 = new Car("Toyota", "Corolla", 2019);
var car2 = new Car("Honda", "Civic", 2020);
// Using object methods
car1.getInfo();
car2.accelrate();
// Using getter methods
console.log(car1.getBrand());
console.log(car2.getModel());
console.log(car1.getYear());
