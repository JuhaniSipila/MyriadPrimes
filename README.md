# Linear Myriad Prime Number Sieve

A relatively simple linear time complexity prime sieving algorithm implemented in JS & C++. 

## Myriad Prime Number Sieve

The Myriad prime number sieve utilizes the modular result stating that all primes >3 can be expressed as 6n±1. Based on this, a generator function G(k) is constructed giving the k:th number of this form. The generator function and its inverse function are used to generate a composite index generating function I(x,y) which is used in sieving.

The implementations were tested against implementations of the sieve of Eratosthenes and the sieve of Atkin and observed to be faster both in JS and C++. Faster and more optimized implementations exist (atleast) in C++.

For higher than 10^9 limits and faster executions one should use e.g. segmented wheel sieve. For more information on the Myriad prime sieve and comparison to other sieves, see the related Master's thesis (.pdf).

The original idea of the prime sieve was conjured from a geometrical pattern observed in the squares of primes. Below is an illustration of the pattern with n=7.
<img src="https://github.com/JuhaniSipila/MyriadPrimes/blob/master/primeSquareWhiteWithBorders.svg?sanitize=true">

### JS implementation

The JavaScript implementation takes as a parameter the limit upto which primes are generated. Returns an array containing the primes upto the limit.

```
MyriadSieveLinear(limit)
```

### C++ implementation

The C++ implementation defines a long long (int) limit in the main-function upto which primes are generated and outputs the primes into stdout. Use e.g. the provided Makefile.

## Author

* **Juhani Sipilä** - [JuhaniSipila](https://github.com/JuhaniSipila)
