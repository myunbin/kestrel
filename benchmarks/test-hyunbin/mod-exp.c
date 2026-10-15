/* @KESTREL
 * pre: left.a == right.a && left.b == right.b && left.a >= 0 && left.a < 1000 && left.b >= 0;
 * left: exp_left;
 * right: exp_right;
 * post: left.ret == right.ret;
 */

void _test_gen(int a, int b) {
  a = ((a % 1000) + 1000) % 1000;
  b = ((b % 1024) + 1024) % 1024;
  _main(a, b, a, b);
}

void exp_left(int a, int b) {
  int base = a;
  int power = b;
  int ret = 1;
  while (power > 0) {
    ret = (ret * base) % 1000;
    power = power - 1;
  }
}

void exp_right(int a, int b) {
  int base = a;
  int power = b;
  int ret = 1;
  while (power > 0) {
    if (power % 2 == 1) {
      ret = (ret * base) % 1000;
    }
    power = power / 2;
    base = (base * base) % 1000;
  }
}
