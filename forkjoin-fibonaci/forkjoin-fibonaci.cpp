#include "benchmark.hpp"

namespace par = pasl::sched::native;

long fib_par(long n)
{
  long result;
  if (n < 2)
  {
    result = n;
  }
  else
  {
    long a, b;
    fork2([&]
          { a = fib_par(n - 1); }, [&]
          { b = fib_par(n - 2); });
    result = a + b;
  }
  return result;
}

int main(int argc, char **argv)
{
  long n = 40;
  if (argc > 1)
  {
    n = std::stol(argv[1]);
  }

  long result = fib_par(n);
  std::cout << "Fibonacci of " << n << " is " << result << std::endl;

  return 0;
}
