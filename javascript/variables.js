// differences between var, let, and const: SCOPE
// Scope of Variables in JavaScript

// 1. var: Function-scoped or globally-scoped
function varScopeExample() {
    if (true) {
        var x = 10; // Function-scoped, not block-scoped
    }
    console.log(x); // Outputs 10 (var is accessible outside the block)
}

// Hoisting example with var
function varHoistingExample() {
    console.log(y); // Outputs undefined, not an error
    var y = 20;
    // Equivalent to:
    // var y;
    // console.log(y); // undefined
    // y = 20;
}

// 2. let: Block-scoped
function letScopeExample() {
    if (true) {
        let z = 30; 
        // z is only accessible within this block
    }
    // console.log(z); // Would cause a ReferenceError
}

// Demonstrating block scope with let
function blockScopeDemo() {
    let a = 40;
    {
        let a = 50; // This is a different variable
        console.log(a); // Outputs 50
    }
    console.log(a); // Outputs 40
}

// 3. const: Block-scoped with immutable binding
function constScopeExample() {
    const PI = 3.14159;
    // PI = 3; // This would cause a TypeError

    // However, for objects and arrays, the reference is constant
    const person = { name: "Alice" };
    person.name = "Bob"; // This is allowed
    // person = { name: "Charlie" }; // This would cause a TypeError
}

// Practical comparison
function scopeComparison() {
    // var: Function-scoped, hoisted, can be redeclared
    var x = 1;
    var x = 2; // Allowed

    // let: Block-scoped, not hoisted, cannot be redeclared in same scope
    let y = 1;
    // let y = 2; // This would cause a SyntaxError

    // const: Block-scoped, not hoisted, cannot be redeclared or reassigned
    const z = 1;
    // z = 2; // This would cause a TypeError
    // const z = 3; // This would cause a SyntaxError
}

// Best Practices:
// 1. Use const by default
// 2. Use let only when you know the value will change
// 3. Avoid var in modern JavaScript