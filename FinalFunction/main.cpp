#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>

// Вывод массива в консоль.
template<typename T>
void print_arr(T arr[], const int lenght) {
	std::cout << '[';
	for (int i = 0; i < lenght; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
// Заполнение массива случайными числами.
template<typename T>
void fill_arr(T arr[], const int lenght, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < lenght; i++)
		arr[i] = rand() % (right - left) + left;
}

void type_of(int num) {std::cout << "INT\n";}
void type_of(double num) { std::cout << "DOUBLE\n"; }
void type_of(char num) { std::cout << "CHAR\n"; }
void type_of(float num) { std::cout << "FLOAT\n"; }

// Рекурсивный поиск всех элементов от А до В.
int sum_AB(int A, int B) {
	if (A > B) {
		std::cout << "Ты дурак!!!\n";
		std::swap(A, B);
	}
	if (A == B)
		return A;
	return sum_AB(A, B - 1) + B;
}
template<typename T>
void middle_sort(T arr[], const int lenght) {
	int first_index=0,last_index=0;
	for (int i = 0; i < lenght; i++)
		if (arr[i] < 0) {
			first_index = i;
			break;
		}
	for(int i=lenght-1;i>=0;i--)
		if (arr[i] < 0) {
			last_index = i;
			break;
		}
	// Быстрая сортировка.
	/*if(first_index!=last_index)
		std::sort(arr + first_index + 1, arr + last_index);*/
	// Пузырьковая сортировка.
	for (int i = last_index - 1; i > 0; i--)
		for (int j = first_index + 1; j < i; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}
template<typename T>
void sorr(T arr[], const int lenght,T h=1) {
	for (int j = h; j > 0; j--)
		for (int i = lenght - 1; i > 0; i--)
			std::swap(arr[i], arr[i - 1]);
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	//  Задача 1. Тип данных.
	/*std::cout << "Задача 1.\n";
	std::cout << "7 - ";
	type_of(7);
	std::cout << "4.6 - ";
	type_of(4.6);
	std::cout << "a - ";
	type_of('a');
	std::cout << "6.7F - ";
	type_of(6.7F);
	std::cout << "\n\n";*/

	//  Задача 2. Рекурсивная сумма от N до M.
	/*std::cout << "Задача 2.\nВведите начало диапазона : ";
	std::cin >> n;
	std::cout << "Введите конец диапазона : ";
	std::cin >> m;
	std::cout << "Сумма чисел от " << n << " до " << m << " это " << sum_AB(n, m) << "\n\n";*/

	//  Задача 3. Сортировка середины.
	/*std::cout << "Задача 3.\nИзначальный массив : \n\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, -20, 21);
	print_arr(arr3, size3);
	std::cout << "\n\nИтоговый массив : \n";
	middle_sort(arr3, size3);
	print_arr(arr3, size3);
	std::cout << "\n\n";*/

	//  Задача 4. Сдвиг массива на переданное число.
	std::cout << "Задача 4.\nИзначальный массив : \n";
	const int size4 = 5;
	int arr4[size4]{ 1,2,3,4,5 };
	print_arr(arr4, size4);
	std::cout << "Введите значение сдвига : ";
	std::cin >> n;
	sorr(arr4, size4,n);
	std::cout << "\nИтоговый массив : \n";
	print_arr(arr4, size4);

	// Задача 5. 

	

	return 0;
}