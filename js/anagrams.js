/*
Create a function that checks if two words or phrases are anagrams of each other (contain the same letters rearranged).
*/

function check(toCheck, toCompare){
    let count = 0;
    let word = toCheck.toLowerCase().split('');
    let compare = toCompare.toLowerCase().split('');
    word.forEach((letter)=>{
        if(compare.includes(letter)){
            count += 1;
        }
    })
    return (count == word.length) ? true : false;
}

console.log(check('hi','ih'))
