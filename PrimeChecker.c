//Jackson Frankfurt
//Check Primes
//7/31/2017
//Windows 10, 64-bit
//This should be accurate up to the biggest long double such that it and all smaller numbers do not lose precision == 2^53 == 9,007,199,254,740,992 OR the size of an unsigned long long, whichever is smaller
//^^ according to https://stackoverflow.com/a/1848762

#include <stdio.h>
#include <stdbool.h>
//#include <math.h> //needed if using sqrt()

int main (void){
  unsigned long long PrimeCheck; //this is an unsigned long long because to check divisibility, the input needs to be an integer
  short again = 1; //run the first time
  printf("Input a whole number and I'll tell you if it's prime.\n");
  while (again == 1) { //want to run again?
    bool Checker = true; //resets switches to enable the program to run again.
    bool stop = false; //resets switches to enable the program to run again.
    scanf("%lld", &PrimeCheck);
    //printf("PrimeCheck 1 = %lld\n",PrimeCheck); //test

    if(PrimeCheck <= 1){
      Checker = false;
      printf("Primes must be whole numbers greater than 1.\n");
      //printf("Error 1\n");
    }
    if(PrimeCheck % 2 == 0 && PrimeCheck != 2){
      Checker = false;
      printf("Your number is divisible by 2.\n");
      //printf("Error 2\n");
    }
    else { //only executes if input is not even and not <=1
      unsigned long long i = 3; //when I used a for loop, it asked if input was divisible by 1 the first time around->everything was prime
      do {
        if (PrimeCheck % i == 0){ //checks PrimeCheck's divisibility with the incriment; the incriment will go through every positive odd number except 1
          Checker = false; //Number is not prime
          printf("%lld is divisible by %lld\n", PrimeCheck, i);
          //tests:
          // printf("i = %lld\n", i);
          // printf("PrimeCheck 2 = %lld\n", PrimeCheck );
          stop = true; //ends loop when a factor of PrimeCheck is found
        }
        i = i + 2;
      }
      //while ((long double)(i-2) < (long double)(sqrtl((long double)PrimeCheck)) && stop == false); //sqrt only works with decimal numbers.:/ <-- also works
      while ((long double)(i-2) < (long double)((long double)PrimeCheck/(long double)(i-2)) && stop == false); //incriment steadily approaches sqrt of PrimeCheck. Square roots of primes don't work well with integers.
    }
    if (PrimeCheck == 2) { //two is a prime
      Checker = true;
    }
    if (Checker){
      printf("Your number is prime.\n");
    }
    else {
      printf("Your number is not prime.\n");
    }
    printf("If you would like to enter another number, enter: 1\nOtherwise, enter: 2 to close the program.\n");
    scanf("%hd", &again);
    while (again != 1 && again != 2){
      printf("Error: If you would like to enter another number, enter: 1\nOtherwise, enter: 2 to close the program.\n");
      scanf("%hd", &again);
    }
    if (again == 1){
      printf("Enter a number to check if it's prime.\n");
    }
  }
return 0;
} //end main
