#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void Zavd()
{
	double xi[4];
	double fxi[4];
	cout << "\nVikoristati tablichni dani z laboratornoi roboti:\nxi = {-3, -1, 0, 2}\nf(xi) = {8, 4, -4, -2}\n";
	cout << "chi vvesti svoi chisla? (1/2) ";
	int q0;
	cin >> q0;
	if (q0 == 1)
	{
		xi[0] = -3;
		xi[1] = -1;
		xi[2] = 0;
		xi[3] = 2;
		fxi[0] = 8;
		fxi[1] = 4;
		fxi[2] = -4;
		fxi[3] = -2;
	}
	else
		if (q0 == 2)
		{
			for (int i = 0; i <= 3; i++)
			{
				cout << "x" << i << " = ";
				cin >> xi[i];
			}
			cout << endl;
			for (int i = 0; i <= 3; i++)
			{
				cout << "f(x" << i << ") = ";
				cin >> fxi[i];
			}
		}
		else
		{
			cout << "Nice Try\n";
			system("pause");
			return;
		}
	system("cls");
	// Âûâîä òàáëèöû
	cout << "-------------\nLaboratorna 3\n-------------\n";
	cout << "\n\nTablicya:\n\n" << setw(6) << "xi" << setw(11) << "f(xi)\n\n";
	for (int i = 0; i <= 3; i++)
		cout << setw(6) << xi[i] << setw(8) << fxi[i] << endl;
	cout << endl;
	// Ðàñ÷åò êîåôèöèåíòîâ óð. Ëàãðàíæà
	double a = 0;
	double bcd[3];
	double L[] = { 0, 0, 0, 0 };
	int n;
	for (int i = 0; i <= 3; i++)
	{
		n = 0;
		a = fxi[i];
		for (int k = 0; k <= 3; k++)
		{
			if (k != i)
			{
				a = a / (xi[i] - xi[k]);
				bcd[n] = xi[k];
				n++;
			}
		}
		L[0] = L[0] + a;
		L[1] = L[1] - a * (bcd[0] + bcd[1] + bcd[2]);
		L[2] = L[2] + a * (bcd[0] * bcd[1] + bcd[1] * bcd[2] + bcd[0] * bcd[2]);
		L[3] = L[3] - a * (bcd[0] * bcd[1] * bcd[2]);
	}
	// Âûâîä óð. Ëàãðàíæà
	cout << "Rivnyannya Lagranja:\nL3(xi) =";
	if (L[0] == -1)
		cout << " - x^3";
	else
		if (L[0] == 1)
			cout << " x^3";
	if ((L[0] < 0) && (L[0] != -1))
	{
		L[0] = L[0] * (-1);
		cout << " - " << L[0] << "x^3";
		L[0] = L[0] * (-1);
	}
	else
		if ((L[0] > 0) && (L[0] != 1))
			cout << L[0] << " x^3";
	if (L[1] == -1)
		cout << " - x^2";
	else
		if ((L[1] == 1) && (L[0] != 0))
			cout << " + x^2";
		else if (L[0] == 0)
			cout << " x^2";
	if ((L[1] < 0) && (L[1] != -1))
	{
		L[1] = L[1] * (-1);
		cout << " - " << L[1] << "x^2";
		L[1] = L[1] * (-1);
	}
	else
		if ((L[1] > 0) && (L[1] != 1))
			if (L[0] != 0)
				cout << " + " << L[1] << "x^2";
			else if (L[0] == 0)
				cout << L[1] << "x^2";
	if (L[2] == -1)
		cout << " - x";
	else
		if ((L[2] == 1) && (L[0] != 0) && (L[1] != 0))
			cout << " + x";
		else if ((L[0] == 0) && (L[1] == 0))
			cout << " x";
	if ((L[2] < 0) && (L[2] != -1))
	{
		L[2] = L[2] * (-1);
		cout << " - " << L[2] << "x";
		L[2] = L[2] * (-1);
	}
	else
		if ((L[2] > 0) && (L[2] != 1))
			if ((L[0] != 0) && (L[1] != 0))
				cout << " + " << L[2] << "x";
			else if ((L[0] == 0) && (L[1] == 0))
				cout << L[2] << "x";
	if ((L[3] < 0) && (L[3] != -1))
	{
		L[3] = L[3] * (-1);
		cout << " - " << L[3] << endl << endl;
		L[3] = L[3] * (-1);
	}
	else
		if ((L[3] > 0) && (L[3] != 1))
			if ((L[0] != 0) && (L[1] != 0) && (L[2] != 0))
				cout << " + " << L[3] << endl << endl;
			else if ((L[0] == 0) && (L[1] == 0) && (L[2] == 0))
				cout << L[3] << endl << endl;
	// Ïîäñòàâëÿòü ëè 4 ÷èñëà â óðàâíåíèå?
	cout << "Hochete pidstaviti 4 chisla do rivnyannya? (y/n) ";
	char q1;
	cin >> q1;
	if ((q1 == 'y') || (q1 == 'Y'))
	{}
	else
		if ((q1 == 'n') || (q1 == 'N'))
			return;
		else
		{
			cout << "Nice Try\n";
			system("pause");
			return;
		}
	double x0;
	double x1;
	double x2;
	double x3;
	double Lx0;
	double Lx1;
	double Lx2;
	double Lx3;
	cout << "\nvikoristati chisla z laboratornoi roboti (-2, -1.5, -0.5, 1)\n";
	cout << "chi vvesti svoi chisla? (1/2) ";
	int q2;
	cin >> q2;
	if (q2 == 1)
	{
		x0 = -2;
		x1 = -1.5;
		x2 = -0.5;
		x3 = 1;
	}
	else
		if (q2 == 2)
		{
			cout << "Vvedit` svoi chisla:\n";
			cout << "x0 = ";
			cin >> x0;
			cout << "x1 = ";
			cin >> x1;
			cout << "x2 = ";
			cin >> x2;
			cout << "x3 = ";
			cin >> x3;
		}
		else
		{
			cout << "Nice Try\n";
			system("pause");
			return;
		}
	Lx0 = L[0]*pow(x0, 3) + L[1]*pow(x0, 2) + L[2]*x0 + L[3];
	Lx1 = L[0]*pow(x1, 3) + L[1]*pow(x1, 2) + L[2]*x1 + L[3];
	Lx2 = L[0]*pow(x2, 3) + L[1]*pow(x2, 2) + L[2]*x2 + L[3];
	Lx3 = L[0]*pow(x3, 3) + L[1]*pow(x3, 2) + L[2]*x3 + L[3];
	cout << "\nL3(" << x0 << ") = " << Lx0 << endl;
	cout << "L3(" << x1 << ") = " << Lx1 << endl;
	cout << "L3(" << x2 << ") = " << Lx2 << endl;
	cout << "L3(" << x3 << ") = " << Lx3 << "\n\n";
	system("pause");
}

void main()
{
	cout << "-------------\nLaboratorna 3\n-------------\n";
	Zavd();
}

//  xi:  -3    -1    0   2
// fxi:   8     4   -4  -2
// xi2:  -2  -1.5 -0.5   1
