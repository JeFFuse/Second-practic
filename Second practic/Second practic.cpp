#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <chrono>

using namespace std;

void swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void InsertSort(int a[])
{
	for (int i = 1; i < 100; i++)
	{
		int k = i - 1;
		while (k >= 0 && a[k] > a[k + 1])
		{
			swap(&a[k], &a[k + 1]);
			k--;
		}
	}
}

void Bubble(int a[])
{
	for (int i = 0; i < 100 - 1; i++)
	{
		for (int j = 0; j < 100 - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int vr = 0;
				vr = a[j];
				a[j] = a[j + 1];
				a[j + 1] = vr;
			}
		}
	}
}

void ShakerSort(int a[])
{
	int i, j, k;
	int n = 100;
	int f = 0;
	for (i = f; i < 100; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(&a[j], &a[j + 1]);
			}
		}
		for (k = n - 1; k >= f; k--)
		{
			if (a[k] < a[k - 1])
			{
				swap(&a[j], &a[j - 1]);
			}
		}
	}
}

void QuickSort(int* arr, int  end, int begin)
{
	int mid;
	int f = begin;
	int l = end;
	mid = arr[(f + l ) / 2];
	while (f < l)
	{
		while (arr[f] < mid) f++;
		while (arr[l] > mid) l--;
		if (f <= l)
		{
			swap(arr[f], arr[l]);
			f++;
			l--;
		}
	}
	if (begin < l) QuickSort(arr, l, begin);
	if (f < end) QuickSort(arr, end, f);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int m[100];
	int h[100];
	int z;
	int maxN = -100;
	int minN = 100;
	while (true)
	{
		int task;
		cout << "Выберете пункт:\n"
			"1.Создать новый массив\n"
			"2.Отсортировать массив\n"
			"3.Минимальное и максимальное число\n"
			"4.Среднее значение максимального и минимального\n"
			"5.Количество элементов, которые меньше числа \"а\"\n"
			"6.Количество элементов, которые больше числа \"b\"\n"
			"7.Бинарный поиск числа \"а\"\n"
			"8.Замена элементов \"а\" & \"b\"\n"
			"9.Закрыть программу\n";
		cin >> task;
		cout << '\n' << '\n';
		switch (task)
		{
		case 1:
		{
			for (z = 0; z < 100; z++)
			{
				int rando = (rand() % 100);
				int zn = (rand() % 2);
				if (zn == 0)
				{
					rando = -rando;
				}
				m[z] = rando;
				h[z] = m[z];
			}

			for (int i = 0; i < 100; i++)
				cout << setw(8) << left << m[i];
			cout << endl << '\n' << '\n';
			break;
		}
		case 2:
		{
			int sorttype;
			cout << "Выберете сортировку:\n" <<
				" 1. Bubble Sort\n" <<
				" 2. Shaker Sort\n" <<
				" 3. Insertion Sort\n" <<
				" 4. Quick Sort\n";
			cin >> sorttype;
			switch (sorttype)
			{
			case 1: {
				auto start = chrono::steady_clock::now();
				Bubble(m);
				auto end = chrono::steady_clock::now();
				for (int i = 0; i < 100; i++)
					cout << setw(8) << left << m[i];
				cout << '\n' << endl;
				cout << "Затраченое время в наносекундах: "
					<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
					<< " ns" << endl;

				cout << "Затраченое время в микросекундах: "
					<< chrono::duration_cast<chrono::microseconds>(end - start).count()
					<< " µs" << endl;

				cout << "Затраченое время в милисекундах: "
					<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
					<< " ms" << endl;

				cout << "Время в секундах: "
					<< chrono::duration_cast<chrono::seconds>(end - start).count()
					<< " sec";
				cout << '\n' << endl;
				break;
			}
			case 2: {
				auto start = chrono::steady_clock::now();
				ShakerSort(m);
				auto end = chrono::steady_clock::now();
				for (int i = 0; i < 100; i++)
					cout << setw(8) << left << m[i];
				cout << '\n' << endl;
				cout << "Затраченое время в наносекундах: "
					<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
					<< " ns" << endl;

				cout << "Затраченое время в микросекундах: "
					<< chrono::duration_cast<chrono::microseconds>(end - start).count()
					<< " µs" << endl;

				cout << "Затраченое время в милисекундах: "
					<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
					<< " ms" << endl;

				cout << "Время в секундах: "
					<< chrono::duration_cast<chrono::seconds>(end - start).count()
					<< " sec";
				cout << '\n' << endl;
				break;
			}
			case 3: {
				auto start = chrono::steady_clock::now();
				InsertSort(m);
				auto end = chrono::steady_clock::now();
				for (int i = 0; i < 100; i++)
					cout << setw(8) << left << m[i];
				cout << '\n' << endl;
				cout << "Затраченое время в наносекундах: "
					<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
					<< " ns" << endl;

				cout << "Затраченое время в микросекундах: "
					<< chrono::duration_cast<chrono::microseconds>(end - start).count()
					<< " µs" << endl;

				cout << "Затраченое время в милисекундах: "
					<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
					<< " ms" << endl;

				cout << "Время в секундах: "
					<< chrono::duration_cast<chrono::seconds>(end - start).count()
					<< " sec";
				cout << '\n' << endl;
				break;
			}
			case 4: {
				auto start = chrono::steady_clock::now();
				QuickSort(m, 99, 0);
				auto end = chrono::steady_clock::now();
				for (int i = 0; i < 100; i++)
					cout << setw(8) << left << m[i];
				cout << '\n' << endl;
				cout << "Затраченое время в наносекундах: "
					<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
					<< " ns" << endl;

				cout << "Затраченое время в микросекундах: "
					<< chrono::duration_cast<chrono::microseconds>(end - start).count()
					<< " µs" << endl;

				cout << "Затраченое время в милисекундах: "
					<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
					<< " ms" << endl;

				cout << "Время в секундах: "
					<< chrono::duration_cast<chrono::seconds>(end - start).count()
					<< " sec";
				cout << '\n' << endl;
				break;
			}
			default: {
				break;
			}
			}
			break;
		}
		case 3: {
			InsertSort(m);
			
			
			auto start1 = chrono::steady_clock::now();
			for (int i = 0; i < 100; i++)
			{
				if (m[i] < minN)
				{
					minN = m[i];
				}

				if (m[i] > maxN)
				{
					maxN = m[i];
				}
			}
			auto end1 = chrono::steady_clock::now();

			cout << "Максимальное значение: " << maxN << '\n' << "Минимальное значение: " << minN << endl;
			cout << "Затраченое время неотсортированного массива в наносекундах : "
				<< chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count()
				<< " ns" << '\n' << endl;
			auto start2 = chrono::steady_clock::now();

			int maxO;
			int minO;
			maxO = m[99];
			minO = m[0];

			auto end2 = chrono::steady_clock::now();

			cout << "Максимальное значение: " << maxO << '\n' << "Минимальное значение: " << minO << endl;
			cout << "Затраченое время отсортированного массива в наносекундах : "
				<< chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
				<< " ns" << endl << '\n' << '\n';
			break;
		}
		case 4: {
			for (int i = 0; i < 100; i++)
			{
				if (m[i] < minN)
				{
					minN = m[i];
				}

				if (m[i] > maxN)
				{
					maxN = m[i];
				}
			}
			int kolvo = 0;
			int srzn = (maxN + minN) / 2;
			cout << "Среднее значение макс и мин: " << srzn << '\n';
			cout << "Индексы всех элементов, которые равны этому значению: ";
			auto start3 = chrono::steady_clock::now();
			for (int i = 0; i < 100; i++)
			{
				if (srzn == h[i])
				{
					cout << i << " ";
					kolvo += 1;
				}
			}
			if (kolvo == 0)
			{
				cout << "их нету";
			}
			auto end3 = chrono::steady_clock::now();
			cout << '\n';
			cout << "Количество: " << kolvo << '\n';
			cout << "Время поиска в наносекундах : "
				<< chrono::duration_cast<chrono::nanoseconds>(end3 - start3).count()
				<< " ns" << endl << '\n' << '\n';
			break;
		}
		case 5: {
			Bubble(m);
			int a;
			int kl = 0;
			cout << "Введите число a: ";
			cin >> a;
			for (int i = 0; i < 100; i++)
			{
				if (m[i] < a)
				{
					kl += 1;
				}
			}
			cout << "Количество элементов: " << kl << '\n' << endl;
			break;
		}
		
		case 6: {
			Bubble(m);
			int b;
			int kl = 0;
			cout << "Введите число b: ";
			cin >> b;
			for (int i = 0; i < 100; i++)
			{
				if (m[i] > b)
				{
					kl += 1;
				}
			}
			cout << "Количество элементов: " << kl << '\n' << endl;
			break;
		}
		case 7: {
			Bubble(m);
			int c;
			bool flag = false;
			int l = 0;
			int r = 99;
			int mid;
			cout << "Введите число: ";
			cin >> c;
			auto start1 = chrono::steady_clock::now();
			while ((l <= r) && (flag != true))
			{
				mid = (l + r) / 2;

				if (m[mid] == c)
				{
					flag = true;
				}
				if (m[mid] > c)
				{
					r = mid - 1;
				}
				else
				{
					l = mid + 1;
				}
			}
			auto end1 = chrono::steady_clock::now();
			if (flag == true)
			{
				auto start2 = chrono::steady_clock::now();
				for (int i = 0; i < 100; i++)
				{
					if (m[i] == c)
					{
						break;
					}
				}
				auto end2 = chrono::steady_clock::now();
				cout << "Такое число есть в массиве!" << '\n' << '\n';
				cout << "Затраченое время перебор в наносекундах : "
					<< chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count()
					<< " ns" << endl;
				cout << "Затраченое время бинарный поиск в наносекундах : "
					<< chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count()
					<< " ns" << '\n' << endl;
				break;
			}
			else
			{
				cout << "Данное число в массиве не имеется" << '\n' << '\n';
				break;
			}
		}
		
		
		case 8:
		{
			int a;
			int b;
			cout << "Запишите 2 индекса(0-99): ";
			cin >> a >> b;
			swap(m[a], m[b]);
			for (int i = 0; i < 100; i++)
				cout << setw(8) << left << m[i];
			cout << endl << '\n' << '\n';
			break;
		}
		
		
		case 9: {exit(0);
			break; }

		default:
		{
			break;
		}
		}
	}
}
