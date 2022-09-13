#include <iostream>
#include <math.h>

#define a_po_russki_mozhno setlocale(LC_ALL, "Russian"); system("chcp 1251")

using namespace std;

enum Functions { SH, SQUARE, EXP };

double square(double);

void showFunctions();

double getNumber(char);

int* getFunction();

int main() {
	a_po_russki_mozhno;

	double x, y;
	double (*userFunction)(double);
	double userFunctionResult;
	double testResult;
	double result;

	showFunctions();

	int* functionNumber = getFunction();
	x = getNumber('x');
	y = getNumber('y');

	switch (*functionNumber) {
	case SH:
		userFunction = sinh; break;
	case SQUARE:
		userFunction = square; break;
	case EXP:
		userFunction = exp; break;
	default:
		userFunction = square;
	}

	userFunctionResult = userFunction(x);
	testResult = y * userFunctionResult;

	if (testResult == 10) {
		result = log(x) - pow(userFunctionResult, 2);
		cout << "Равно 10" << endl;
	}
	else if (testResult < 10) {
		result = 2 * y - 10 * sin(x);
		cout << "Меньше 10" << endl;
	}
	else {
		result = pow(y, 2) + pow(userFunctionResult, 2);
		cout << "Другой" << endl;
	}

	cout << "Результат: " << result << endl;

	delete functionNumber;
	return 0;
}

void showFunctions() {
	cout << "Доступные функции:" << endl;
	cout << "\t" << SH << " - sh(x)" << endl;
	cout << "\t" << SQUARE << " - x^2" << endl;
	cout << "\t" << EXP << " - e^x" << endl;
}

double square(double x) {
	return pow(x, 2);
}

double getNumber(char symbolVar) {
	double number;
	printf("Введите %c: ", symbolVar);
	cin >> number;
	return number;
}

int* getFunction() {
	int* functionNumber = new int;
	cout << "Введите номер функции: ";
	cin >> *functionNumber;
	return functionNumber;
}
