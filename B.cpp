//#include<iostream>
//#include<math.h>
//
//using namespace std;
//
//int main()
//{
//	double a, b, c;
//	cin >> a >> b >> c;
//
//	if (pow(b, 2) - 4 * a * c < 0)
//	{
//		cout << "No answer!";
//		return 0;
//	}
//	double delta = sqrt(pow(b, 2) - 4 * a * c);
//	double x1 = ((-1) * b + delta) / (2 * a);
//	double x2 = ((-1) * b - delta) / (2 * a);
//	if(x1*pow(10,6)%10>=5)
//	if (x1 == x2)
//		printf("x1=x2=%.5f", x1);
//	else
//		printf("x1=%.5f;x2=%.5f", x1, x2);
//
//	return 0;
//}
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        cout << "No answer!" << endl;
    }
    else if (discriminant > 0) {
        double x1 = (-b - sqrt(discriminant)) / (2 * a);
        double x2 = (-b + sqrt(discriminant)) / (2 * a);
        cout << fixed << setprecision(5);
        if(x1 < x2)
            cout << "x1=" << x1 << ";x2=" << x2 << endl;
        else
            cout << "x1=" << x2 << ";x2=" << x1 << endl;
    }
    else if (discriminant == 0) {
        double x = -b / (2 * a);
        cout << fixed << setprecision(5);
        cout << "x1=x2=" << x << endl;
    }
    else {
        cout << "No answer!" << endl;
    }

    return 0;
}
