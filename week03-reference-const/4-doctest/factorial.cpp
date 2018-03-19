/**
 * Implementation of factorial function
 */

int factorial(int number) { 
	return number <= 1 ? number : factorial(number - 1) * number; 
}

