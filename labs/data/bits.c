/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* x^y for a single bit is only 0 when both the digits are the same, so extending the idea to multiple bits, we get the expression below */
   return ((~(x & y)) & (~(~x & ~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
 /* Left-shift 1 by (sizeof(int)*8 - 1) positions to get smallest two's complement number that can be represented with int */
  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /* Check if x XORed with Tmin is 0xFFFFFFFF */
   return !((x ^ (1 << 31)) ^ (1 << 31 >> 31));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* Individually check the lowest to most significant bytes to see if they are all 0xAA */
  return !(((x & 0xAA) & ((x >> 8) & 0xAA) & ((x >> 16) & 0xAA) & ((x >> 24) & 0xAA)) ^ 0xAA);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
 /* Simply use the definition of two's complement */
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /* Check if the upper hex digit is 3 and then check if the lower hex digit is 
  above 9 */
  int check_for_3 = (x >> 4) ^ 0x3;
  int lower_hex_val = (x & 0xF);
  int check_lower_hex_val = 0x9 + (~lower_hex_val + 1); 
  return (!(check_for_3) & !(check_lower_hex_val & (1 << 31)));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* Generate a mask which is 0xFFFFFFFF when x is 0 and 0x00000000 when x is not zero. Then, AND the mask with z and negation of the mask with y and finally or both the statements, so only one of y, z is selected */ 
  int not_x = !x;
  int not_x_mask = not_x << 31 >> 31; 
  return ((~not_x_mask & y) | (not_x_mask & z));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0. 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /* Check if x = y by XORing the two values, then check if x is -ve and y is +ve, then in the case the signs of x and y are the same, check if x - y is -ve */
  int sign_x = (x >> 31) & 1;
  int sign_y = (y >> 31) & 1;
  int z = x + ~y + 1;
  int sign_z = (z >> 31) & 1;
  return !(x ^ y) | (sign_x & !sign_y) | ((!(sign_x ^ sign_y)) & sign_z);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    return (~(x >> 31) & (~x ^ (~x + 1)) >> 31) & 1; 
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int u_16, u_8, u_4, u_2, u_1, u_0;
  int sign = x >> 31;
  x = (sign & ~x) | (~sign & x);
  u_16 = !!(x >> 16) << 4;
  x = x >> u_16;
  u_8 = !!(x >> 8) << 3;
  x = x >> u_8;
  u_4 = !!(x >> 4) << 2;
  x = x >> u_4;
  u_2 = !!(x >> 2) << 1;
  x = x >> u_2;
  u_1 = !!(x >> 1);
  x = x >> u_1;
  u_0 = x;
  return u_16 + u_8 + u_4 + u_2 + u_1 + u_0 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int sign, exponent;
  sign = uf & (1 << 31);
  exponent = (uf >> 23) & 0xFF;
  if (exponent == 0) return (uf << 1) | sign;
  if (exponent == 255) return uf;
  exponent ++;
  if (exponent == 255) return (0xFF << 23) | sign;
  return  (exponent << 23) | (uf & ~(0xFF << 23));
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int exp = ((uf & 0x7f800000) >> 23) - 127;
  int frac = (uf & 0x007fffff) | (0x1 << 23); // Add 1 to the 24th bit, i.e., M = f + 1
  int sign = uf >> 31;  
  if (exp > 31) return 0x80000000;
  if (exp < 0) return 0; // Denormalized using this algorithm, exponent is -127, which meets this condition

  if (exp > 23) frac <<= (exp - 23);
  else frac >>= (23 - exp); // The fraction is already equivalent to being left-shifted by 23 bits

  if (!((frac >> 31) ^ sign)) return frac; // If the sign hasn't changed, output directly
  else if (!sign) return 0x80000000; // If it changes from positive to negative, it indicates overflow (but the test cases seem not to consider Tmin)
  else return ~frac + 1; // If it changes from negative to positive, output the opposite number
  
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    int exponent;
    if (x < -149) return 0;
    else if (x <= -126) return (1 << (149 + x));
    
    else if (x >= 128) return 255 << 23;
    else {
        exponent = x + 127;
        return exponent << 23;
    }
}
