/* 
 * CS:APP Data Lab 
 * 
 * 
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y); // 德摩根律
}

/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  int a = 0xff; // 0xff 用于掩码操作，提取一个字节
  return (x >> (n << 3)) & a; // 将x右移n*8位，然后与0xff进行与操作，提取第n个字节
}

/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  int a = (1 << (31 + ~n + 1) << 1) + (1 << 31 >> 31); // 创建一个掩码，用于清除符号位
  return (x >> n) & a; // 右移n位后与掩码进行与操作，确保符号位为0
}

/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
  int a = 0x55;
  int b = 0x33;
  int c = 0xf;
  int d = 0xff;
  int e = ~(1 << 31 >> 15); // 00000000000000001111111111111111
  int cvt;

  a += a << 8;
  a += a << 16; // 01010101010101010101010101010101
  b += b << 8;
  b += b << 16; // 00110011001100110011001100110011
  c += c << 8;
  c += c << 16; // 00001111000011110000111100001111
  d += d << 16; // 00000000111111110000000011111111

  cvt = (x & a) + ((x >> 1) & a); // 计算每两位中1的个数
  cvt = (cvt & b) + ((cvt >> 2) & b); // 计算每四位中1的个数
  cvt = (cvt & c) + ((cvt >> 4) & c); // 计算每八位中1的个数
  cvt = (cvt & d) + ((cvt >> 8) & d); // 计算每十六位中1的个数
  cvt = (cvt & e) + ((cvt >> 16) & e); // 计算整个32位中1的个数
  return cvt;
}

/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int isNeg = (x >> 31) & 1; // 判断x是否为负数
  int cvt = ~x + 1; // 取反加1，得到-x
  int isCvtNeg = (cvt >> 31) & 1; // 判断-x是否为负数
  return ~(isNeg | isCvtNeg) + 2; // 如果x为0，则返回1，否则返回0
}

/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31; // 返回最小的32位有符号整数，即-2147483648
}

/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  int a = 31 + ~n + 1; // 计算32 - n
  return !((x << a << 1 >> a >> 1) ^ x); // 检查x是否可以用n位表示
}

/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  int bias = (x >> 31) & ~(1 << 31 >> 31 << n); // 偏置 2 ^ n - 1
  return (x + bias) >> n; // 将x加上偏置后右移n位，实现向零舍入的除法
}

/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1; // 取反加1，得到-x
}

/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
  return !(x >> 31) & !!x; // 判断x是否为正数
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int c = y + (~x + 1); // 计算y - x
  return !(c >> 31); // 如果y - x >= 0，则返回1，否则返回0
}

/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  int result = 0;
  result += (!!(x >> 16)) << 4; // if x > 16 bits, add 16.
  result += (!!(x >> (8 + result))) << 3; // if x > 8 bits, add 8...
  result += (!!(x >> (4 + result))) << 2;
  result += (!!(x >> (2 + result))) << 1;
  result += (!!(x >> (1 + result)));
  return result; // 通过二分法逐步缩小范围，找到x的最高有效位
}

/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
  int mask = 1 << 31;
  int e = (uf >> 23);
  int f = uf ^ (e << 23);
  if ((e & 0xff) == 0xff && f != 0) {
    return uf; // 如果uf是NaN，则返回uf
  }
  return uf ^ mask; // 否则，翻转符号位
}

/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  int sign = x & (1 << 31);
  int minus = 1 << 31; 
  int exp = 31;
  int bias = 127;
  int frac;
  if (!x) {
    return 0; // 如果x为0，则返回0
  }
  if (x == minus) {
    return minus | ((exp + bias) << 23); // 如果x是最小的负数，则返回对应的浮点数表示
  }
  if (sign) {
    x = ~x + 1; // 如果x为负数，则取其绝对值
  }
  while (!(x & minus))
  {
     x <<= 1;
     exp -= 1; // 找到x的最高有效位
  }
  frac = (((~minus) & x) >> 8); // 提取尾数部分
  if (x & 0x80 && ((frac & 1) ||((x & 0x7f) > 0))) {
    frac++; // 进行舍入处理
  }
  return sign + ((exp + bias) << 23) + frac; // 返回浮点数的二进制表示
}

/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  // inf or N/A
  if (((uf >> 23) & 0xff) == 0xff) { 
    return uf; // 如果uf是无穷大或NaN，则返回uf
  }

  // normalized
  if (((uf >> 23) & 0xff) != 0) {
    return uf + (1 << 23); // 如果uf是规格化数，则指数加1
  }

  // denormalized
  return (uf & (1 << 31)) | (uf << 1); // 如果uf是非规格化数，则尾数左移1位
}