#include "HashWithChaining.hxx"
#include "HashWithQuadratic.hxx"


int main(int ac, char* av[])
{
  // Key is an integer for student ID
  // Value is a string representing the students' entire name

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 13579
  // FIXME
  std::function<int(int)> concatEven = ...

  // Create a lamdba function that takes an int (the key) and returns
  // an int by taking every even-positioned digit in the key and
  // concatenating it to form the hash code, ie:
  //   key  = 123456789
  //   code = 2468
  // FIXME
  std::function<int(int)> concatOdd = ...

  // concat even digits, chaining
  HashWithChaining<int,string> h1(concatEven);

  // concat even digits, quadratic probing
  HashWithQuadratic<int,string> h2(concatEven);

  // concat odd digits, chaining
  HashWithChaining<int,string> h3(concatOdd);

  // concat odd digits, quadratic probing
  HashWithQuadratic<int,string> h4(concatOdd);

  // Read data from input file, and do inserts's and find's,
  // and gather statistics ...
  // FIXME


}
