

#include "Base.hpp"

Base *generate(void) {
  srand((unsigned)time(NULL));
  Base *bp = NULL;
  switch (rand() % 3) {
  case 0:
    std::cout << "Instanciated A" << std::endl;
    bp = new A();
    break;
  case 1:
    std::cout << "Instanciated B" << std::endl;
    bp = new B();
    break;
  case 2:
    std::cout << "Instanciated C" << std::endl;
    bp = new C();
    break;
  default:
    std::cout << "No class got instanciated." << std::endl;
    break;
  }
  return bp;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p) != NULL)
    std::cout << "Type A" << std::endl;
  else if (dynamic_cast<B *>(p) != NULL)
    std::cout << "Type B" << std::endl;
  else if (dynamic_cast<C *>(p) != NULL)
    std::cout << "Type C" << std::endl;
  else
    std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p) {
  try {
    A &res = dynamic_cast<A &>(p);
    (void)res;
    std::cout << "Type A" << std::endl;
  } catch (std::exception &e) {
    try {
      B &res = dynamic_cast<B &>(p);
      (void)res;
      std::cout << "Type B" << std::endl;
    } catch (std::exception &e) {
      try {
        C &res = dynamic_cast<C &>(p);
        (void)res;
        std::cout << "Type C" << std::endl;
      } catch (std::exception &e) {
        std::cout << "Unknown Type";
      }
    }
  }
}

int main() {
  Base *exp;
  Base *exp2;
  exp = generate();
  exp2 = generate();
  identify(*exp);
  identify(exp2);
  delete exp;
  delete exp2;
}