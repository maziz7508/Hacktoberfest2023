/*
Write a function that takes an array as input and returns a new array with only the unique elements (removing duplicates).
*/

function refine(arr){
    let refined = [];
    arr.forEach((elem)=>{
        if(!refined.includes(elem)){
            refined.push(elem);
        }
    })
    return refined;
}

console.log(refine(["Hello","Hi","Hello"]))
