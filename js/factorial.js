/*
Question: 
  Write a function that calculates the factorial of a given number. The factorial of a non-negative integer n is the product of all positive integers less than or equal to n.
  */
  
function factorial(num){
    let result = 1;
    for(i=1;i<=num;i++){
        result *= i;
    }
    return result;
}

console.log(factorial(3));
