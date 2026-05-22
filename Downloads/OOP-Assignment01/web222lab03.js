function addDollars(numbers){
	return numbers.map(num => `$${num}`);
}
console.log(addDollars([1,2,3,4]));
