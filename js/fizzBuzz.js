/*
Question:
     Write a program that prints numbers from 1 to 100. But for multiples of 3, print "Fizz" instead of the number, and for multiples of 5, print "Buzz." For numbers which are multiples of both 3 and 5, print "FizzBuzz.
 */
 
 for(i=1;i<=100;i++){
     if(i%3==0){
         console.log("Fizz");
     }else if(i%5==0){
         console.log("Buzz");
     }else{
         console.log(i);
     }
 }
