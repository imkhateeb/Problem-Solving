// ES6 class syntax (underneath it's still prototype-based)
class Animal {
  makeSound() {
    console.log("Some sound");
  }
}

// Traditional prototype-based approach
// function Animal() {}
// Animal.prototype.makeSound = function () {
//   console.log("Some sound");
// };

let dog = new Animal();
dog.makeSound();
