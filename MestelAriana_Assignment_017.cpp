// MestelAriana_Assignment_017.cpp
/*****
  Problem: Add the following operators to the class: operator-(), operator*(), operator/().
  Make sure Rats are reduced to lowest terms. So if a Rat is 2/4 it should be reduced to 1⁄2.
  If a Rat represents an “improper fraction” (i.e. numerator >denominator) print the Rat as
  a “mixed number.” So 6/4 will be printed as 1 1⁄2.
  Ideas: Overload the operators the same way we overloaded the plus operator in class.
  Reduce the fractions using a for loop and declaring it a friend inside the class and
  the function should be outside the class.  In the << function, add that if the numerator
  is larger than the denominator then figure out how to represent it as a mixed number.
*****/

#include <iostream>
using namespace std;

class Rat{
    private:
      int n;
      int d;
    public:
      // default constructor
      Rat() {
        n=0;
        d=1;
      }
      // 2 parameter constructor
      Rat(int i, int j){
      n=i;
      d=j; }
      // conversion constructor
      Rat(int i)
        { n=i;
          d=1; }
      //accessor functions (usually called get() and set(...) )
      int getN(){ return n;}
      int getD(){ return d;}
      void setN(int i){ n=i;}
      void setD(int i){ d=i;}
      //arithmetic operators
      Rat operator+(Rat r){
         Rat t;
         t.n=n*r.d+d*r.n;
         t.d=d*r.d;
         return t;
      }
      Rat operator-(Rat r) { // 1/2 2/3
        Rat t;
        t.n = n*r.d - d*r.n;
        t.d = d*r.d;
        return t;
      }
      Rat operator*(Rat r) {
        Rat t;
        t.n = n * r.n;
        t.d = d * r.d;
        return t;
      }
      Rat operator/(Rat r) {
        Rat t;
        t.n = n * r.d;
        t.d = d * r.n;
        return t;
      }
    // 2 overloaded i/o operators
    friend ostream& operator<<(ostream& os, Rat r);
    friend istream& operator>>(istream& is, Rat& r);
    friend Rat reduced(Rat r);
    }; //end Rat
// operator<<() is NOT a member function but since it was declared a friend of Rat // it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
  if (r.d > r.n) {
    os<<r.n<<" / "<<r.d<<endl;
  }
  else {
    int a, b;
    a = r.n / r.d;
    b = r.n % r.d;
    os << a << " " << b << "/" << r.d << endl;
  }
  return os;
}
// operator>>() is NOT a member function but since it was declared a friend of Rat // it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
  is>>r.n>>r.d;
  return is;
}
Rat reduced(Rat r) {
  Rat t;
  for (int x = r.d; x >= 1; x--) {
    if ((r.n % x == 0) && (r.d % x == 0)) {
      t.n = (r.n / x);
      t.d = (r.d / x);
      break;
    }
  }
  return t;
}


int main(){
  Rat a(6, 4), b(3, 9), c;
  c = a * b;
  cout << reduced(a);
return 0;
}
