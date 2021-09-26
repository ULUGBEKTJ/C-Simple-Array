
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>




void list(int** m, int a, int b);
void vvod(int** m, int a, int b);
void show(int** m, int a, int b);
void operacii(int** mass, int a, int b);
void opred(int** m, int a, int  b);
void um(int** mass, int a, int b);
void diag(int** m, int a, int b);
void pdiag(int** m, int a, int b);
void create(int** m, int a, int b, int v);
void fuy(int** m, int a, int b);
void fuyrr(int** m, int a, int b);
void file(int** m, int a, int b);
int masy(int m);
void www(int** m, int a, int b, int v);
int smchic(int a);
int afff(int g);
int ht(int h);
////////////////////////////////////////
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::ifstream;
using std::ofstream;
using std::string;
short i, j, o, v;
/////////////////////////////////////////
void main()
{
	system("cls");
	setlocale(LC_ALL, "Russian");

	int a, b;
	cout << "введите количество строк.\n";
	cin >> a;
	cout << "введите количество столбцов.\n";
	cin >> b;
	int** massiv = new int* [a];
	for (i = 0; i < a; i++)		massiv[i] = new int[b];

	system("cls");
beg:
	cout << "ввести матрицу вручную (1)  или считать с файла? (2)\n";
	int vibor;
	cin >> vibor;
	switch (vibor)
	{
	case 1: vvod(massiv, a, b); list(massiv, a, b);
	case 2: file(massiv, a, b); list(massiv, a, b);
	default:
		cout << "неопознанна команда\n"; system("pause"); goto beg;

	}
}

/////////////////////////////////////////
void file(int** m, int a, int b)
{
	system("CLS");
	string name;

	cout << "введите название файла\n";
	cin >> name;


	ifstream f(name);
	for (i = 0; i < a; i++)
	{

		for (j = 0; j < b; j++)
		{
			f >> m[i][j];
		}
	}

}
/////////////////////////////////////////
void list(int** m, int a, int b)
{
pokaz:
	system("cls");
	show(m, a, b);

	cout << "транспонирование       1\n\a";
	cout << "умножение на матрицу   2\n\a";
	cout << "определитель           3\n\a";
	cout << "диагональ              4\n\a";
	cout << "диагональ  побочно     5\n\a";
	cout << "сложение               6\n\a";
	cout << "вычитание              7\n\a";
	cout << "умножение на число     8\n\a";
	cout << "деление   на число     9\n\a";
	cout << "простые числа         10\n\a";
	cout << "сумма чисел от 5 до 8 11\n\a";
	cout << "числа Фибоначи        12\n\a";
	cout << "полидром              13\n\a";
	cout << "\n\n\n\nввод заново         0\n\n\n\n\n\n";



	cin >> v;
	switch (v)
	{
	case 0:
		main();
	case 1:
		operacii(m, a, b);
	case 2:
		um(m, a, b);
	case 3:
		opred(m, a, b);
	case 4:
		diag(m, a, b);
	case 5:
		pdiag(m, a, b);
	case 6: create(m, a, b, v);
	case 7: create(m, a, b, v);
	case 8: fuy(m, a, b);
	case 9: fuyrr(m, a, b);
	case 10: www(m, a, b, v);
	case 11:www(m, a, b, v);
	case 12:www(m, a, b, v);
	case 13:www(m, a, b, v);
	default: cout << "нет опреации\n"; system("pause"); goto pokaz;

	}
}
/////////////////////////////////////////
void vvod(int** m, int a, int b)
{
	system("cls");

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			cout << "введите элемент массива [" << i + 1 << "] [" << j + 1 << "]\n";
			cin >> m[i][j];
		}
	}
}
/////////////////////////////////////////
void show(int** m, int a, int b)
{

	for (o = 1; o <= (b * 5 + 1); o++)
	{
		cout << '*';/// //////////////////////////////////////
	}
	cout << endl;
	for (i = 0; i < a; i++)
	{
		cout << '*';
		for (j = 0; j < b; j++)
		{
			cout << setw(3) << m[i][j] << " *";
		}
		cout << endl;
		for (o = 1; o <= (b * 5 + 1); o++)
		{
			cout << '*';
		}
		cout << endl;
	}

}//работает...//// change
/////////////////////////////////////////
void operacii(int** mass, int a, int b)
{
	if (a != b) { cout << "\n только квадратная матрица \n"; system("pause"); list(mass, a, b); }
	if (a == b)
	{
		int a1 = a, b1 = b;
		int** mas = new int* [a1];
		for (i = 0; i < a1; i++)
		{
			mas[i] = new int[b1];
		}
		//////////////////////////////////////
		for (i = 0; i < a; i++)/// ввод массива
		{
			for (j = 0; j < b; j++)
			{
				mas[i][j] = mass[j][i];
			}
		}

		for (i = 0; i < a; i++)
		{
			delete[]mass[i];
		}
		delete[]mass;
		list(mas, a1, b1);
	}
}
/////////////////////////////////////////
void um(int** mass, int a, int b)
{
	system("cls");
	show(mass, a, b);
	int m, n;
	cout << "\n введите количество строк второй матрицы \n";
	cin >> m;
	cout << "\n введите количество столбцов второй матрицы \n";
	cin >> n;

	////////////////////////
	if (b != m) { cout << "\n !!! размеры не совпдают !!! \n"; system("pause"); list(mass, a, b); }



	if (b == m)
	{
		int a1 = a, n1 = n;
		////////////////////////////
		int** max = new int* [m];
		for (i = 0; i < m; i++)
		{
			max[i] = new int[n];

		}
		vvod(max, m, n);

		////////////////////////


		cout << "получится матрица размера  -  " << a1 << " x " << n1;
		system("pause");


		int** me = new int* [a1];

		for (i = 0; i < a1; i++)
		{
			me[i] = new int[n1];
		}

		int s = 0, k = 0;
		////////////////////////////
		for (i = 0; i < a; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (o = 0; o < b; o++)
				{
					s = s + mass[i][o] * max[o][j];

				}
				me[i][j] = s;
				s = 0;

			}
		}
		//////////////////////////////////////////
		for (i = 0; i < a; i++)
		{
			delete[]mass[i];
		}
		delete[]mass;



		for (i = 0; i < m; i++)
		{
			delete[]max[i];
		}
		delete[] max;


		list(me, a1, n1);
	}

}
/////////////////////////////////////////
void  diag(int** m, int a, int b)
{

	if (a != b)
	{
		cout << "!!! только квадратные !!!" << endl;
	}
	if (a == b)
	{

		for (i = 1; i <= a; i++)
		{
			cout << setw(i * 2) << m[i - 1][i - 1] << endl;
		}
	}
	system("pause");
	list(m, a, b);
}
/////////////////////////////////////////
void  pdiag(int** m, int a, int b)
{
	j = a;
	if (a != b)
	{
		cout << "!!! только квадратные !!!" << endl;
	}
	if (a == b)
	{


		for (i = 1; i <= a; i++)
		{
			cout << setw(j * 2) << m[i - 1][j - 1] << endl;
			j--;
		}
	}
	system("pause");
	list(m, a, b);
}
/////////////////////////////////////////
void opred(int** m, int a, int  b)
{

	if (a != b) { cout << "\n!!!матрица должна быть квадратной!!! \n"; }
	if (a == 1 && b == 1) cout << "\n определитель == " << m[0][0];
	if (a == 2 && b == 2) { cout << "\n определитель == " << m[0][0] * m[1][1] - m[0][1] * m[1][0]; }
	if (a == 3 && b == 3) { cout << "\n определитель == " << m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][2] * m[1][1] * m[2][0] - m[1][2] * m[2][1] * m[0][0] - m[1][0] * m[0][1] * m[2][2]; }

	system("pause");
	list(m, a, b);
}
/////////////////////////////////////////
void create(int** m, int a, int b, int v)
{
	int aa = a, bb = b;
	cout << "размерность вашей матрицы будет - строк (" << a << ") и столбцов (" << b << ")\n"; system("pause");
	if (v == 6) { v = 1; }
	if (v == 7) { v = -1; }

	int** mm = new int* [aa];
	for (i = 0; i < aa; i++)
	{
		mm[i] = new int[bb];
	}
	vvod(mm, aa, bb);
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			m[i][j] += (v * mm[i][j]);
		}
	}
	/*for (i = 0; i < b; i++)
	{
	delete[i]m;
	}
	delete[]m;*/
	list(m, a, b);

}
/////////////////////////////////////////
void fuy(int** m, int a, int b)
{
	system("cls");
	cout << "введиете число умножения\n";
	cin >> o;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < b; j++)
		{
			m[i][j] *= o;
		}
	}
	list(m, a, b);

}
/////////////////////////////////////////
void fuyrr(int** m, int a, int b)
{
	system("cls");
	int r, f;
	cout << "введиете число деления\n";
	cin >> r;

	for (o = 1; o <= (b * 8 + 1); o++)
	{
		cout << '*';
	}
	cout << endl;
	for (i = 0; i < a; i++)
	{
		cout << '*';
		for (j = 0; j < b; j++)
		{
			f = m[i][j];
			if (f % r == 0)
			{
				cout << setw(4) << f;
				cout << "   *";
			}
			else {
				if (f < r)cout << setw(6) << f % r << '/' << r;
				cout << " *";
				if (f > r) cout << setw(2) << f / r << ',' << f % r << '/' << r;
				cout << " *";
			}
		}
		cout << endl;
		for (o = 1; o <= (b * 8 + 1); o++)
		{
			cout << '*';
		}
		cout << endl;
	}
	system("pause");
	list(m, a, b);

}
/////////////////////////////////////////
void www(int** m, int a, int b, int v)
{
	int y = 0;
	for (o = 1; o <= (b * 5 + 1); o++)
	{
		cout << '*';
	}
	cout << endl;
	for (i = 0; i < a; i++)
	{
		cout << '*';
		for (j = 0; j < b; j++)
		{
			cout << setw(3) << m[i][j] << " *";

			if (v == 10) { y += masy(m[i][j]); if (b - j == 1)cout << (y > 0 ? "   в строке содержаться простые числа" : "   в строке не содержатьс простые числа"); }
			if (v == 11) { y += smchic(m[i][j]); if (b - j == 1) cout << "   сумма чисел равна " << y; }
			if (v == 12) { cout << afff(m[i][j]); }
			if (v == 13) { cout << ht(m[i][j]); }
		}
		cout << endl;
		for (o = 1; o <= (b * 5 + 1); o++)
		{
			cout << '*';
		}
		cout << endl;
		y = 0;
	}
	v = 0;

	system("pause");
	list(m, a, b);

}
int masy(int m)
{
	m -= 2;
	for (o = 0; o < 5; o++)
	{

		if (m == 2 || m == 3) return 1;
		if (m % 2 != 0 || m % 3 != 0 || m % 5 != 0)return 1;
	}
	m++;
	return 0;
}
/////////////////////////////////////////
int smchic(int a)
{
	/////////////////////////////////////////
	if (a >= 5 || a <= 8)return a;
	return 0;
}
int afff(int g)
{
	int a = 1, b = 0, c = 0;
	if (g <= 0)return 0;
	if (g > 1)
	{
		for (i = 1; i < g; i++)
		{
			c += b + a;
			b = a;
			a = a + b;
		}
		return c;
	}
	return 0;
}
int ht(int h)
{
	int g = h;
	int s = 0;
	while (abs(h > 10))

	{
		s = s + h % 10;
		h = h / 10;
		s = s * 10;

	}
	if (g == s + h)return 1;
	if (g != s + h)return 0;
	return 0;
}