/* 
Implement a function that reverses a string without using the built-in `reverse` method.
*/

function reverse(str){
    let input = str.split('');
    let reverseInput = "";
    input.forEach((letter)=>{
        reverseInput = letter + reverseInput;
    })
    console.log(reverseInput)
}

reverse("Hello")
