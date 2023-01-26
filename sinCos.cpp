#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846

using namespace std;

// Вычисление синуса
double my_sin(double x);

// Вычисление косинуса
double my_cos(double x);

// Машинный эпсилон
double EMach();

int main() {
	cout << "X\t" 
		<< "SysCos\t\t" << "MyCos\t\t" << "DCos\t\t" 
		<< "SysSin\t\t" << "MySin\t\t" << "Dsin\n";
	for (int i = 0; i < 50 + 1; i += 5) {
		double dCos = abs((my_cos(i) - cos(i)) / cos(i));
		double dSin = abs((my_sin(i) - sin(i)) / sin(i));
		cout << i << '\t' 
			<< cos(i) << '\t' << my_cos(i) << '\t' << dCos << '\t' 
			<< sin(i) << '\t' << my_sin(i) << '\t' << dSin << endl;
	}
	return 0;
}

double my_cos(double x) {
	// Вычисление косинуса
	while (x > PI * 2) { x -= PI * 2; }
	double tmp = 1, cos0 = 1, cos1 = 1, k = 1;
	double d = EMach();
	do
	{
		cos0 = cos1;
		tmp *= (-1) * (x * x) / ((k * 2 - 1) * (k * 2));
		cos1 += tmp;
		k++;
	} while (abs(cos0 - cos1) > d);
	return cos0;
}

double my_sin(double x) {
	// Вычисление синуса
	while (x > PI * 2) { x -= PI * 2; }
	double tmp = x, sin0, sin1 = x, k = 1;
	double d = EMach();
	do
	{
		sin0 = sin1;
		tmp *= ((-1) * (x * x)) / ((k * 2) * (k * 2 + 1));
		sin1 += tmp;
		k++;
	} while (abs(sin0 - sin1) > d);
	return sin0;
}

double EMach() {
	// Машинный эпсилон
	double x = 1, y = 0, me;
	do {
		me = x;
		x = x / 2;
		y = 1 + x;
	} while (y != 1);
	return me;
}