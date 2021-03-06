#include <iostream>
#include <iomanip>
#include <GeographicLib/Utility.hpp>
#include "JacobiConformal.hpp"

using namespace std;
using namespace GeographicLib;

int main() {
  Utility::set_digits();
  Math::real a = 6378137+35, b = 6378137-35, c = 6356752;
  JacobiConformal jc(a, b, c);
  cout  << fixed << setprecision(1)
        << "Ellipsoid parameters: a = "
        << a << ", b = " << b << ", c = " << c << "\n"
        << setprecision(10)
        << "Quadrants: x = " << jc.x() << ", y = " << jc.y() << "\n";
  Math::real f = 90 / jc.x();
  cout << "Scaled coordinates (angle x y):\n";
  for (int i = 0; i <= 90; i += 5) {
    Math::real omg = i, bet = i;
    cout << i << " " << jc.x(omg)*f << " " << jc.y(bet)*f << "\n";
  }
}
