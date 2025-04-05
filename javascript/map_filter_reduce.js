// Comprehensive Guide to map(), filter(), and reduce()

// 1. map() Method
// Purpose: Transform each element in an array
function mapExamples() {
    // Basic transformation
    const numbers = [1, 2, 3, 4, 5];
    
    // Double each number
    const doubledNumbers = numbers.map(num => num * 2);
    console.log("Doubled numbers:", doubledNumbers);
    // Output: [2, 4, 6, 8, 10]

    // Transform objects
    const users = [
        { name: 'Alice', age: 25 },
        { name: 'Bob', age: 30 }
    ];
    
    // Extract names
    const userNames = users.map(user => user.name);
    console.log("User names:", userNames);
    // Output: ['Alice', 'Bob']
}

// 2. filter() Method
// Purpose: Create a new array with elements that pass a test
function filterExamples() {
    const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    
    // Keep only even numbers
    const evenNumbers = numbers.filter(num => num % 2 === 0);
    console.log("Even numbers:", evenNumbers);
    // Output: [2, 4, 6, 8, 10]

    // Filter objects
    const products = [
        { name: 'Apple', price: 1 },
        { name: 'Banana', price: 0.5 },
        { name: 'Orange', price: 2 }
    ];
    
    // Find expensive products
    const expensiveProducts = products.filter(product => product.price > 1);
    console.log("Expensive products:", expensiveProducts);
    // Output: [{ name: 'Orange', price: 2 }]
}

// 3. reduce() Method
// Purpose: Reduce an array to a single value
function reduceExamples() {
    const numbers = [1, 2, 3, 4, 5];
    
    // Sum all numbers
    const sum = numbers.reduce((accumulator, currentValue) => accumulator + currentValue, 0);
    console.log("Sum of numbers:", sum);
    // Output: 15

    // More complex reduce
    const transactions = [
        { amount: 10 },
        { amount: 20 },
        { amount: 30 }
    ];
    
    // Calculate total amount
    const totalAmount = transactions.reduce((total, transaction) => total + transaction.amount, 0);
    console.log("Total amount:", totalAmount);
    // Output: 60

    // Grouping objects
    const people = [
        { name: 'Alice', age: 25 },
        { name: 'Bob', age: 30 },
        { name: 'Charlie', age: 25 }
    ];
    
    // Group by age
    const groupedByAge = people.reduce((acc, person) => {
        (acc[person.age] = acc[person.age] || []).push(person);
        return acc;
    }, {});
    console.log("Grouped by age:", groupedByAge);
    // Output: { 
    //   '25': [{ name: 'Alice', age: 25 }, { name: 'Charlie', age: 25 }],
    //   '30': [{ name: 'Bob', age: 30 }]
    // }
}

// Demonstrate all methods
function demonstrateArrayMethods() {
    console.log("--- map() Examples ---");
    mapExamples();
    
    console.log("\n--- filter() Examples ---");
    filterExamples();
    
    console.log("\n--- reduce() Examples ---");
    reduceExamples();
}

// Run the demonstration
demonstrateArrayMethods();