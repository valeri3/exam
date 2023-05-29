#include <iostream>
#include <iomanip>//необходим для выравнивания слов в cout
#include "windows.h"//подключение языка
#include <locale>

using namespace std;

const unsigned int globCharSize = 55;
//----------------str----------------
// Функция для определения длины строки
int my_Str_Len(const char* str)
{
	int ind = 0;  // Индекс для прохода по символам строки

	// Перебираем символы строки до тех пор, пока не достигнем символа '\0' (конец строки)
	// и увеличиваем индекс при каждой итерации
	for (ind; str[ind] != '\0'; ind++) {}

	return ind;  // Возвращаем полученную длину строки
}

// Функция для преобразования символа в нижний регистр
char my_Str_To_Lower_Case(char ch)
{
	if (ch >= 'A' && ch <= 'Z'  // Проверяем, является ли символ заглавной латинской буквой
		|| ch >= 'А' && ch <= 'Я')  // Проверяем, является ли символ заглавной кириллической буквой
	{
		return ch + 32;  // Возвращаем символ, преобразованный в соответствующий символ нижнего регистра
	}

	return ch;  // Если символ не является заглавной буквой, возвращаем его без изменений
}

// Функция для копирования строки
char* my_Str_Cpy(const char* source, char* destination)
{
	char* ptr = destination;  // Сохраняем указатель на начало целевой строки

	while (*source != '\0')  // Пока не достигнут конец исходной строки
	{
		*destination = *source;  // Копируем символ из исходной строки в целевую строку
		destination++;  // Увеличиваем указатель целевой строки
		source++;  // Увеличиваем указатель исходной строки
	}

	*destination = '\0';  // Устанавливаем нулевой символ в конце целевой строки, обозначая ее конец

	return ptr;  // Возвращаем указатель на начало целевой строки
}

// Функция для сравнения двух строк
int my_Str_Cmp(const char* str1, const char* str2)
{
	while (*str1)
	{
		// Если символы отличаются или достигнут конец второй строки,
		// прекращаем сравнение и выходим из цикла
		if (*str1 != *str2)
		{
			break;
		}

		// Переходим к следующей паре символов
		str1++;
		str2++;
	}

	// Возвращаем разницу ASCII после преобразования `char*` в `unsigned char*`
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// Перегрузка функции my_Str_Cmp осуществляет сравнение символов двух строк, заданных указателями str1 и str2.
// Параметр length определяет количество символов, которые требуется сравнить.
// Функция возвращает 0, если все сравниваемые символы совпадают, и 1 в противном случае.
int my_Str_Cmp(const char* str1, const char* str2, int length)
{
	for (int i = 0; i < length; i++)
	{
		// Сравниваем символы str1[i] и str2[i]
		if (str1[i] != str2[i])
			return 1; // Если найдено несовпадение символов, возвращаем 1
	}
	return 0; // Если все сравниваемые символы совпадают, возвращаем 0
}

//Функция выполняет конкатенацию(объединение) двух строк.
void my_Str_Cat(char* destination, const char* source)
{
	// Перемещаем указатель в конец целевой строки
	while (*destination)
	{
		destination++;
	}

	// Копируем символы из второй строки в конец целевой строки
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}

	// Добавляем нулевой символ в конец целевой строки
	*destination = '\0';
}

// Функция для проверки строки на наличие только пробелов
bool my_Str_With_Space(const char* str)
{

	while (*str != '\0')  // Пока не достигнут символ конца строки '\0'
	{
		if (*str != ' ')  // Если текущий символ не является пробелом
		{
			return false;  // Возвращаем false, так как строка содержит символы отличные от пробела
		}
		str++;  // Переходим к следующему символу
	}
	return true;  // Если строка состоит только из пробелов, возвращаем true
}

int my_Str_Char_To_int(const char* str)
{
	int result = 0;  // Результат преобразования строки в число
	int sign = 1;   // Знак числа (по умолчанию положительное)
	int i = 0;      // Индекс символа в строке

	// Проверка на отрицательное число
	if (str[0] == '-')
	{
		sign = -1;  // Если первый символ '-' - число отрицательное
		i = 1;      // Начинаем считывание числа со второго символа
	}

	// Цикл считывания цифр из строки и преобразования их в число
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');  // Умножение текущего значения на 10 и добавление новой цифры
		i++;  // Переход к следующему символу строки
	}

	return result * sign;  // Возвращаем результат с учетом знака
}

void int_To_Str(int num, char str[]) {
	int i = 0;

	// Если число равно нулю, записываем символ '0' в строку
	if (num == 0) {
		str[i++] = '0';
	}
	// Иначе, если число отрицательное
	else {
		if (num < 0) {
			str[i++] = '-';
			num = -num; // Приводим число к положительному значению для дальнейшей обработки
		}

		// Процесс конвертирования числа в строку
		while (num > 0) {
			str[i++] = '0' + (num % 10); // Получаем остаток от деления числа на 10 и преобразуем его в символ
			num /= 10; // Делаем целочисленное деление числа на 10 для перехода к следующей цифре
		}
	}

	str[i] = '\0'; // Добавляем нулевой символ в конец строки, чтобы обозначить ее конец
}


// Функция my_Str_Reverse инвертирует (разворачивает) заданную строку str.
// Параметр str является массивом символов, представляющим строку.
void my_Str_Reverse(char str[]) {
	int length = my_Str_Len(str); // Определяем длину строки

	int start = 0; // Индекс начального символа
	int end = length - 1; // Индекс конечного символа

	while (start < end) {
		// Обмен символами: первый символ становится последним, второй - предпоследним и так далее
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		// Переход к следующим символам
		start++;
		end--;
	}
}


//---------------------cin_Min_Max------------------------
enum AllowType {
	only_symbols,   // Разрешены только символы, включая буквы (строчные и заглавные) и пробелы
	only_numbers,   // Разрешены только цифры
	universal,      // Разрешены символы: буквы (строчные и заглавные), цифры и пробелы
	numbers_float,  // Разрешены числа с плавающей точкой
	universal_numbers_float,   // Разрешены символы: буквы (строчные и заглавные), цифры, пробелы и числа с плавающей точкой
};

void cin_With_Min_Max(char str[], const int min, const int max, AllowType allowType = only_symbols)
{
	const char delim = '\n';  // Разделитель для ввода строки

	while (true)  // Бесконечный цикл для ввода строки с проверками
	{
		bool inFormat = true;  // Флаг, указывающий на корректный формат ввода строки

		cin.getline(str, globCharSize);  // Чтение строки из входного потока и сохранение её в переменную str

		int length = my_Str_Len(str);  // Вычисление длины строки при помощи функции my_Str_Len. Результат сохраняется в переменную length.

		// Проверка пустой строки
		if (length == 0)
		{
			inFormat = false;  // Формат некорректен, если строка пустая
		}
		// Проверка строки, состоящей только из пробелов
		else if (my_Str_With_Space(str))
		{
			inFormat = false;  // Формат некорректен, если строка состоит только из пробелов
		}
		// Проверка длины строки
		else if (length < min && length > max)
		{
			inFormat = false;  // Формат некорректен, если длина строки не соответствует заданным ограничениям
		}
		else
		{
			// Проверка символов
			for (int i = 0; i < length; i++)
			{
				switch (allowType)
				{
				case only_symbols:
					// Проверка на разрешенные символы (буквы и пробел)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= 'А' && str[i] <= 'Я')
						|| (str[i] >= 'а' && str[i] <= 'я')
						|| str[i] == ' '))
					{
						inFormat = false;  // Формат некорректен, если символ не является разрешенным
						break;
					}
					break;

				case only_numbers:
					// Проверка на разрешенные символы (цифры)
					if (!(str[i] >= '0' && str[i] <= '9'))
					{
						inFormat = false;  // Формат некорректен, если символ не является разрешенным
						break;
					}
					break;

				case universal:
					// Проверка на разрешенные символы (буквы, цифры и пробел)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= 'А' && str[i] <= 'Я')
						|| (str[i] >= 'а' && str[i] <= 'я')
						|| str[i] == ' '
						|| (str[i] >= '0' && str[i] <= '9')))
					{
						inFormat = false;  // Формат некорректен, если символ не является разрешенным
						break;
					}
					break;

				case numbers_float:
					// Проверка на разрешенные символы (цифры и точка)
					if (!((str[i] >= '0' && str[i] <= '9')
						|| str[i] == '.'))
					{
						inFormat = false;  // Формат некорректен, если символ не является разрешенным
						break;
					}
					break;

				case universal_numbers_float:
					// Проверка на разрешенные символы (буквы, цифры, пробел и числа с плавающей точкой)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= 'А' && str[i] <= 'Я')
						|| (str[i] >= 'а' && str[i] <= 'я')
						|| str[i] == ' '
						|| (str[i] >= '0' && str[i] <= '9')
						|| str[i] == '.'))
					{
						inFormat = false;  // Формат некорректен, если символ не является разрешенным
						break;
					}
					break;

				}
			}
		}

		if (inFormat)
		{
			break;  // Если формат корректен, выходим из цикла
		}
		else
		{
			if (cin.fail())
			{
				cin.clear();  // Сбрасываем флаг ошибки ввода
				cin.ignore(globCharSize, delim);  // Очищаем буфер ввода
			}

			cout << "\nWrong size or format, please enter correct parameters,"
				<< " min size: " << min
				<< ", max size: " << max << endl;
		}
	}
}

// Перегрузка функции cin_With_Min_Max для целочисленных значений.
// Функция предназначена для ввода значения с проверкой на минимальное и максимальное допустимые значения.
void cin_With_Min_Max(int& choose, const int min, const int max)
{
	char strInt[globCharSize];  // Массив символов для хранения строки с номером

	bool isValid = false;
	cin.clear();  // Очищаем поток ввода

	while (isValid != true)
	{
		cin_With_Min_Max(strInt, min, max, only_numbers);  // Вводим строку с номером, ограниченным диапазоном (от 1 до max)
		choose = my_Str_Char_To_int(strInt); // Преобразуем строку в целое число

		if (choose >= min && choose <= max)
		{
			isValid = true; // Введенное значение находится в допустимом диапазоне, выходим из цикла
			break;
		}

		// Выводим сообщение об ошибке, если введенное значение находится вне допустимого диапазона
		cout << "\nWrong size or format, please enter correct parameters. It should be from " << min << " to " << max << "." << endl;

		cout << "\nEnter again: ";
	}
}

//---------------------------------------cin_Min_Max_Date----------------------------------------
// Функция isLeapYear проверяет, является ли заданный год високосным.
// Возвращает true, если год високосный, и false в противном случае.
bool isLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// Функция maxDaysInMonth возвращает максимальное количество дней в заданном месяце для заданного года.
// Параметр month определяет номер месяца (от 1 до 12).
// Параметр year определяет год.
// Возвращает количество дней в месяце или -1 в случае ошибки.
int maxDaysInMonth(int month, int year)
{
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31; // В январе, марте, мае, июле, августе, октябре и декабре 31 день
	case 4: case 6: case 9: case 11:
		return 30; // В апреле, июне, сентябре и ноябре 30 дней
	case 2:
		return isLeapYear(year) ? 29 : 28; // В феврале 29 дней, если год високосный, иначе 28 дней
	default:
		return -1;  // Ошибка - некорректный номер месяца
	}
}

enum AllowDateType {
	day,   // Ввод дня
	month, // Ввод месяца
	year,   // Ввод года
	fullDate// Ввод полной даты
};


// Функция cin_With_Min_Max_Date предназначена для ввода даты с проверкой на минимальное и максимальное допустимые значения.
// Параметр str представляет массив символов, в который будет сохранена введенная дата.
// Параметры currentYear и currentMonth используются для проверки введенной даты в контексте текущего года и месяца.
// Параметр allowDateType определяет тип вводимой даты (день, месяц, год).
void cin_With_Min_Max_Date(char str[], int currentYear = 0, int currentMonth = 0, AllowDateType allowDateType = day) {
	const char delim = '\n';  // Разделитель для ввода строки

	while (true) {
		bool inFormat = true;

		// Проверяем, если требуется ввод полной даты
		if (allowDateType == fullDate) {
			int day, month, year;

			// Ввод дня
			while (true) {
				cout << "\nEnter day: ";
				cin_With_Min_Max(day, 1, 31);
				if (day < 1 || day > 31) {
					cout << "\nDay should be between 1 and 31. Try again.";
				}
				else {
					break;
				}
			}

			// Ввод месяца
			while (true) {
				cout << "Enter month: ";
				cin_With_Min_Max(month, 1, 12);
				if (month < 1 || month > 12) {
					cout << "\nMonth should be between 1 and 12. Try again.";
				}
				else {
					break;
				}
			}

			// Ввод года
			while (true) {
				cout << "Enter year: ";
				cin_With_Min_Max(year, 1970, 2170);
				if (year < 1970 || year > 2170) {
					cin.clear();
					cin.ignore();
					cout << "\nYear should be between 1970 and 2170. Try again.";
				}
				else {
					break;
				}
			}

			// Очищаем итоговую строку перед форматированием даты
			str[0] = '\0';

			// Форматируем дату с разделителями и ведущими нулями для дня, месяца и года
			char dayStr[3];
			char monthStr[3];
			char yearStr[5];
			int_To_Str(day, dayStr);
			int_To_Str(month, monthStr);
			int_To_Str(year, yearStr);

			// Задом на перед преобразуем день, месяц и год
			my_Str_Reverse(dayStr);
			my_Str_Reverse(monthStr);
			my_Str_Reverse(yearStr);

			// Форматируем дату с разделителями и ведущими нулями для дня, месяца и года
			if (my_Str_Len(dayStr) == 1) {
				my_Str_Cat(str, "0");
			}
			my_Str_Cat(str, dayStr);
			my_Str_Cat(str, "/");

			if (my_Str_Len(monthStr) == 1) {
				my_Str_Cat(str, "0");
			}
			my_Str_Cat(str, monthStr);
			my_Str_Cat(str, "/");
			my_Str_Cat(str, yearStr);

			return;
		}
		else {
			cin.ignore(); // Игнорируем символ новой строки, оставшийся после предыдущего ввода
			cin.getline(str, globCharSize);

			int length = my_Str_Len(str);

			// Проверка на нулевую длину строки или наличие пробелов
			if (length == 0 || my_Str_With_Space(str)) {
				inFormat = false;
			}
			else {
				// Проверяем, состоит ли строка только из цифр
				for (int i = 0; i < length; i++) {
					if (!(str[i] >= '0' && str[i] <= '9')) {
						inFormat = false;
						break;
					}
				}

				if (inFormat) {
					int inputValue = my_Str_Char_To_int(str);

					// Проверяем введенное значение в соответствии с типом даты (день, месяц, год)
					switch (allowDateType) {
					case day:
						if (currentYear == 0 || currentMonth == 0) {
							// Проверяем, если год или месяц не указаны, то день должен быть в диапазоне 1-31
							if (inputValue < 1 || inputValue > 31) {
								inFormat = false;
							}
						}
						else {
							// Проверяем, если год и месяц указаны, то день должен быть в диапазоне 1-максимальное количество дней в указанном месяце и году
							if (inputValue < 1 || inputValue > maxDaysInMonth(currentMonth, currentYear)) {
								inFormat = false;
							}
						}
						break;
					case month:
						// Проверяем, что введенный месяц находится в диапазоне 1-12
						if (inputValue < 1 || inputValue > 12) {
							inFormat = false;
						}
						break;
					case year:
						// Проверяем, что введенный год находится в диапазоне 1970-2170
						if (inputValue < 1970 || inputValue > 2170) {
							inFormat = false;
						}
						break;
					}
				}
			}

			// Если формат не соответствует требованиям, выводим сообщение об ошибке
			if (inFormat) {
				break;
			}
			else {
				if (cin.fail()) {
					cin.clear();
					cin.ignore(globCharSize, delim);
				}

				cout << "\nWrong size or format, please enter correct parameters\n";
			}
		}
	}
}


//---------------------------------------my_Time----------------------------------------
struct my_tm
{
	int tm_mday;  // день месяца, от 1 до 31
	int tm_mon;   // месяц,  от 0 до 11
	int tm_year;  // количество лет с 1900
};

// Функция string_to_my_tm преобразует строку с датой в структуру my_tm.
void string_to_my_tm(const char* date_str, struct my_tm* my_tm)
{
	char day[3] = { date_str[0], date_str[1], '\0' };    //1/02/2023
	char month[3] = { date_str[3], date_str[4], '\0' };
	char year[5] = { date_str[6], date_str[7], date_str[8], date_str[9], '\0' };

	// Копируем день, месяц и год из строки даты
	char day_copied[3];
	char month_copied[3];
	char year_copied[5];

	my_Str_Cpy(day, day_copied);
	my_Str_Cpy(month, month_copied);
	my_Str_Cpy(year, year_copied);

	// Преобразуем день, месяц и год в числовые значения и сохраняем в структуре
	my_tm->tm_mday = my_Str_Char_To_int(day_copied); // Преобразуем день в целое число
	my_tm->tm_mon = my_Str_Char_To_int(month_copied) - 1; // Преобразуем месяц в целое число и вычитаем 1, так как отсчет месяцев начинается с 0
	my_tm->tm_year = my_Str_Char_To_int(year_copied) - 1900; // Преобразуем год в целое число и вычитаем 1900, так как отсчет лет начинается с 1900
}

int my_mktime(my_tm* my_tm) {
	// Простое преобразование даты в числовое значение
	// Обратите внимание, что это не будет соответствовать реальному времени, но может использоваться для сравнения дат
	return my_tm->tm_year * 365 + my_tm->tm_mon * 30 + my_tm->tm_mday;
}

// Функция compare_dates сравнивает две даты, представленные в виде строк.

int compare_dates(const char* date1, const char* date2) {
	// Извлекаем значения дня, месяца и года из первой даты
	int day1 = my_Str_Char_To_int(date1);
	int month1 = my_Str_Char_To_int(date1 + 3);
	int year1 = my_Str_Char_To_int(date1 + 6);

	// Извлекаем значения дня, месяца и года из второй даты
	int day2 = my_Str_Char_To_int(date2);
	int month2 = my_Str_Char_To_int(date2 + 3);
	int year2 = my_Str_Char_To_int(date2 + 6);

	// Сравниваем годы
	if (year1 < year2) return -1;
	if (year1 > year2) return 1;

	// Сравниваем месяцы
	if (month1 < month2) return -1;
	if (month1 > month2) return 1;

	// Сравниваем дни
	if (day1 < day2) return -1;
	if (day1 > day2) return 1;

	return 0; // Даты равны
}


int date_to_week_number(my_tm* date) {
	// Общее количество дней в каждом месяце (не учитывает високосные года)
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// Вычисляем день года
	int day_of_year = date->tm_mday;
	for (int i = 0; i < date->tm_mon; i++) {
		day_of_year += days_in_month[i];
	}

	// Вычисляем номер недели
	int week_number = (day_of_year - 1) / 7 + 1;

	return week_number;
}

//-----------------------------------------Task-------------------------------------------

//-----------------------------------------Task-------------------------------------------
struct Task
{
	char* name;          // Имя задачи
	int priority;        // Приоритет задачи
	char* description;   // Описание задачи
	char* datetime;      // Дата и время задачи
};

// Функция createTask создает новую задачу и инициализирует ее поля значениями переданных параметров.
// Возвращает указатель на созданную задачу.
Task* createTask(const char* name, int priority, const char* description, const char* datetime)
{
	Task* newTask = new Task; // Создаем новый объект типа Task

	// Создаем новую строку для поля name и копируем содержимое
	newTask->name = new char[globCharSize];
	my_Str_Cpy(name, newTask->name);

	newTask->priority = priority; // Присваиваем полю priority значение параметра priority

	// Создаем новую строку для поля description и копируем содержимое
	newTask->description = new char[globCharSize];
	my_Str_Cpy(description, newTask->description);

	// Создаем новую строку для поля datetime и копируем содержимое
	newTask->datetime = new char[globCharSize];
	my_Str_Cpy(datetime, newTask->datetime);

	return newTask; // Возвращаем указатель на созданную задачу
}


// Функция editTask изменяет значения полей существующей задачи на новые значения, переданные в параметрах.
void editTask(Task* task, const char* name, int priority, const char* description, const char* datetime) {
	// Копируем новое имя задачи в поле name
	my_Str_Cpy(name, task->name);

	// Присваиваем новое значение приоритета задачи полю priority
	task->priority = priority;

	// Копируем новое описание задачи в поле description
	my_Str_Cpy(description, task->description);

	// Копируем новую дату и время задачи в поле datetime
	my_Str_Cpy(datetime, task->datetime);
}

//---------------------------------------END-TASK----------------------------------------

//---------------------------------------TaskList-----------------------------------------
// Структура TaskList представляет список задач.
struct TaskList
{
	int size;       // Размер списка задач
	Task* tasks;    // Указатель на массив задач
};


// Функция createTaskList создает новый список задач и инициализирует его поля.
// Возвращает указатель на созданный список задач.
TaskList* createTaskList() {
	TaskList* newList = new TaskList; // Создаем новый объект типа TaskList

	newList->tasks = new Task[globCharSize]; // Выделяем память для массива задач размером globCharSize
	newList->size = 0; // Инициализируем размер списка задач нулевым значением

	return newList; // Возвращаем указатель на созданный список задач
}

// Функция displayTasks выводит список задач на экран.

void displayTasks(TaskList* list) {
	int width = 55; // Ширина выводимого блока задач

	// Вывод линии-разделителя
	cout << "\t";
	for (int j = 0; j < width; j++) {
		if (j != 0) {
			cout << "_";
		}
		else {
			cout << " ";
		}

		if (j + 1 == width) {
			cout << endl;
		}
	}

	// Вывод заголовка списка задач
	cout << fixed << left << setw(23) << "\t|" << fixed << left << setw(33) << "TASK LIST" << "|" << endl;

	// Вывод каждой задачи в списке
	for (int i = 0; i < list->size; i++) {
		// Вывод линии-разделителя
		cout << "\t";
		for (int j = 0; j < width; j++) {
			if (j != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (j + 1 == width) {
				cout << endl;
			}
		}

		// Вывод номера задачи, приоритета и даты и времени
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
		cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
		cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;

		// Вывод линии-разделителя
		cout << "\t";
		for (int j = 0; j < width; j++) {
			if (j != 0) {
				cout << "\"";
			}
			else {
				cout << "|";
			}

			if (j + 1 == width) {
				cout << "|" << endl;
			}
		}

		// Вывод имени задачи
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;

		// Вывод линии-разделителя
		cout << "\t";
		for (int j = 0; j < width; j++) {
			if (j != 0) {
				cout << "\"";
			}
			else {
				cout << "|";
			}

			if (j + 1 == width) {
				cout << "|" << endl;
			}
		}

		// Вывод описания задачи
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;

		// Вывод линии-разделителя
		cout << "\t";
		for (int j = 0; j < width; j++) {
			if (j != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (j + 1 == width) {
				cout << " " << endl;
			}
		}
	}
}


// Функция search_Task_By_Name выполняет поиск задачи по названию в списке задач.
// Выводит найденную задачу на экран.
void search_Task_By_Name(TaskList* list, const char* name) {
	// Выделение памяти для временных строк
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// Преобразование введенной строки в нижний регистр
	int nameLength = my_Str_Len(name);
	for (int i = 0; i < nameLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(name[i]);
	}
	strToFind[nameLength] = '\0'; // Закрытие строки

	bool notFound = true;  // Флаг, указывающий на результат поиска (не найдено)

	// Поиск задачи по названию
	for (int i = 0; i < list->size; i++) {
		// Преобразование названия задачи в нижний регистр
		int taskNameLength = my_Str_Len(list->tasks[i].name);
		for (int j = 0; j < taskNameLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].name[j]);
		}
		strTmp[taskNameLength] = '\0'; // Закрытие строки

		// Сравнение введенного названия с названием задачи
		for (int j = 0; j <= nameLength - 2; j++) {
			for (int k = 0; k <= taskNameLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, nameLength)) {
					// Вывод найденной задачи
					int width = 55;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}
					cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Founded name" << "|" << endl;

					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << " " << endl;
						}
					}

					notFound = false;  // Поиск успешен (найдена задача)
					break;
				}
			}
			if (!notFound)
				break;
		}
	}

	// Вывод сообщения, если задача не найдена
	if (notFound) {
		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Name not found" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}

	// Освобождение памяти
	delete[] strToFind;
	delete[] strTmp;
}

// Функция search_Task_By_Priority выполняет поиск задачи по приоритету в списке задач.
// Выводит найденную задачу на экран.
void search_Task_By_Priority(TaskList* list, int priority) {
	bool notFound = true;  // Флаг, указывающий на результат поиска (не найдено)

	// Поиск задачи по приоритету
	for (int i = 0; i < list->size; i++) {
		if (list->tasks[i].priority == priority) {
			// Вывод найденной задачи
			int width = 55;
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}
			cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Founded priority" << "|" << endl;

			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}

			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
			cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << "|";
				}

				if (x + 1 == width) {
					cout << "|" << endl;
				}
			}

			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << "|";
				}

				if (x + 1 == width) {
					cout << "|" << endl;
				}
			}

			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << " " << endl;
				}
			}

			notFound = false;  // Поиск успешен (найдена задача)
			break;
		}
	}

	// Вывод сообщения, если задача не найдена
	if (notFound) {
		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Priority not found" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}
}


// Функция search_Task_By_Description выполняет поиск задачи по описанию в списке задач.
// Выводит найденную задачу на экран.
void search_Task_By_Description(TaskList* list, const char* description) {
	// Выделение памяти для временных строк
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// Преобразование введенной строки в нижний регистр
	int descriptionLength = my_Str_Len(description);
	for (int i = 0; i < descriptionLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(description[i]);
	}
	strToFind[descriptionLength] = '\0'; // Закрытие строки

	bool notFound = true;  // Флаг, указывающий на результат поиска (не найдено)

	// Поиск задачи по описанию
	for (int i = 0; i < list->size; i++) {
		// Преобразование описания задачи в нижний регистр
		int taskDescriptionLength = my_Str_Len(list->tasks[i].description);
		for (int j = 0; j < taskDescriptionLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].description[j]);
		}
		strTmp[taskDescriptionLength] = '\0'; // Закрытие строки

		// Сравнение введенного описания с описанием задачи
		for (int j = 0; j <= descriptionLength - 2; j++) {
			for (int k = 0; k <= taskDescriptionLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, descriptionLength)) {
					// Вывод найденной задачи
					int width = 55;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}
					cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Founded description" << "|" << endl;

					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << " " << endl;
						}
					}

					notFound = false;  // Поиск успешен (найдена задача)
					break;
				}
			}
			if (!notFound) {
				break;
			}
		}
	}

	// Вывод сообщения, если задача не найдена
	if (notFound) {
		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Description not found" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}

	// Освобождение памяти
	delete[] strToFind;
	delete[] strTmp;
}


// Функция search_Task_By_Date_Time выполняет поиск задачи по дате и времени в списке задач.
// Выводит найденную задачу на экран.

void search_Task_By_Date_Time(TaskList* list, const char* datetime) {
	// Выделение памяти для временных строк
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// Преобразование введенной строки в нижний регистр
	int dateTimeLength = my_Str_Len(datetime);
	for (int i = 0; i < dateTimeLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(datetime[i]);
	}
	strToFind[dateTimeLength] = '\0'; // Закрытие строки

	bool notFound = true;  // Флаг, указывающий на результат поиска (не найдено)

	// Поиск задачи по дате и времени
	for (int i = 0; i < list->size; i++) {
		// Преобразование даты и времени задачи в нижний регистр
		int taskDateTimeLength = my_Str_Len(list->tasks[i].datetime);
		for (int j = 0; j < taskDateTimeLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].datetime[j]);
		}
		strTmp[taskDateTimeLength] = '\0'; // Закрытие строки

		// Сравнение введенной даты и времени с датой и временем задачи
		for (int j = 0; j <= dateTimeLength - 2; j++) {
			for (int k = 0; k <= taskDateTimeLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, dateTimeLength)) {
					// Вывод найденной задачи
					int width = 55;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}
					cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Founded date time" << "|" << endl;

					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "_";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
					cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << "|";
						}

						if (x + 1 == width) {
							cout << "|" << endl;
						}
					}

					cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;
					cout << "\t";
					for (int x = 0; x < width; x++) {
						if (x != 0) {
							cout << "\"";
						}
						else {
							cout << " ";
						}

						if (x + 1 == width) {
							cout << " " << endl;
						}
					}

					notFound = false;  // Поиск успешен (найдена задача)
					break;
				}
			}
			if (!notFound) {
				break;
			}
		}
	}

	// Вывод сообщения, если задача не найдена
	if (notFound) {
		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Date time not found" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}

	// Освобождение памяти
	delete[] strToFind;
	delete[] strTmp;
}


// Определение функции display_task
void display_task(Task* task) {
	int width = 55;

	// Вывод приоритета и даты и времени задачи
	cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << task->priority << fixed << left << setw(2) << "|";
	cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << task->datetime << fixed << left << setw(2) << "|" << endl;

	cout << "\t";
	for (int j = 0; j < width; j++) {
		// Вывод разделительной линии
		if (j != 0) {
			cout << "\"";
		}
		else {
			cout << "|";
		}

		if (j + 1 == width) {
			cout << "|" << endl;
		}
	}

	// Вывод названия задачи
	cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << task->name << fixed << left << setw(2) << "|" << endl;
	cout << "\t";
	for (int j = 0; j < width; j++) {
		// Вывод разделительной линии
		if (j != 0) {
			cout << "\"";
		}
		else {
			cout << "|";
		}

		if (j + 1 == width) {
			cout << "|" << endl;
		}
	}

	// Вывод описания задачи
	cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << task->description << fixed << left << setw(2) << "|" << endl;
	cout << "\t";
	for (int j = 0; j < width; j++) {
		// Вывод разделительной линии
		if (j != 0) {
			cout << "\"";
		}
		else {
			cout << " ";
		}

		if (j + 1 == width) {
			cout << " " << endl;
		}
	}
}


// Функция, которая отображает задачи для определенного дня
void display_tasks_for_day(TaskList* list)
{
	char date_str[globCharSize];
	cout << "Please enter the day number (1 to 31): ";
	cin_With_Min_Max_Date(date_str, 0, 0, day);

	my_tm date;
	string_to_my_tm(date_str, &date);
	int tasks_found = 0;

	// Поиск задач, связанных с указанным днем
	for (int i = 0; i < list->size; i++) {
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		if (task_date.tm_mday == date.tm_mday)
		{
			int width = 55;

			// Вывод информации о найденных задачах
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}
			cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "tasks found for the specified day" << "|" << endl;

			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}

			cout << "\t";
			for (int j = 0; j < width; j++) {
				if (j != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (j + 1 == width) {
					cout << endl;
				}
			}

			// Вывод номера задачи и информации о задаче
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// Вывод сообщения, если задачи не найдены
	if (tasks_found == 0) {
		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "No tasks found for the specified day" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}
}


// Функция, которая отображает задачи для определенной недели
void display_tasks_for_week(TaskList* list) {
	int week_number;
	cout << "Please enter the week number (1 to 52): ";
	cin >> week_number;

	int tasks_found = 0;

	// Поиск задач, связанных с указанной неделей
	for (int i = 0; i < list->size; i++)
	{
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		if (date_to_week_number(&task_date) == week_number)
		{
			int width = 55;

			// Вывод информации о найденных задачах
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}
			cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "tasks found for the specified week" << "|" << endl;

			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}

			cout << "\t";
			for (int j = 0; j < width; j++) {
				if (j != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (j + 1 == width) {
					cout << endl;
				}
			}

			// Вывод номера задачи и информации о задаче
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// Вывод сообщения, если задачи не найдены
	if (tasks_found == 0) {

		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "No tasks found for the specified week" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
	}
}


// Функция, которая отображает задачи для определенного месяца
void display_tasks_for_month(TaskList* list) {
	int month_number;
	cout << "Please enter the month number (1 to 12): ";
	cin_With_Min_Max(month_number, 1, 12);

	int tasks_found = 0;

	// Поиск задач, связанных с указанным месяцем
	for (int i = 0; i < list->size; i++)
	{
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		// Приравниваем введенный месяц к месяцу задачи. Здесь нет нужды вычитать 1,
		// поскольку мы будем считать месяцы начиная с 1, как и пользователь.
		if (task_date.tm_mon + 1 == month_number)
		{
			int width = 55;

			// Вывод информации о найденных задачах
			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}
			cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "tasks found for the specified month" << "|" << endl;

			cout << "\t";
			for (int x = 0; x < width; x++) {
				if (x != 0) {
					cout << "\"";
				}
				else {
					cout << " ";
				}

				if (x + 1 == width) {
					cout << endl;
				}
			}

			cout << "\t";
			for (int j = 0; j < width; j++) {
				if (j != 0) {
					cout << "_";
				}
				else {
					cout << " ";
				}

				if (j + 1 == width) {
					cout << endl;
				}
			}

			// Вывод номера задачи и информации о задаче
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// Вывод сообщения, если задачи не найдены
	if (tasks_found == 0) {

		int width = 55;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "_";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}
		cout << fixed << left << setw(11) << "\t|" << fixed << left << setw(45) << "No tasks found for the specified month" << "|" << endl;
		cout << "\t";
		for (int x = 0; x < width; x++) {
			if (x != 0) {
				cout << "\"";
			}
			else {
				cout << " ";
			}

			if (x + 1 == width) {
				cout << endl;
			}
		}

	}
}


void sort_Tasks_By_Priority(TaskList& taskList)
{
	int width = 55;
	cout << "\t";
	for (int x = 0; x < width; x++)//линия разделитильная
	{
		if (x != 0)
		{
			cout << "_";
		}
		else
		{
			cout << " ";
		}

		if (x + 1 == width)
		{
			cout << endl;
		}
	}
	cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Sorted By Priority" << "|" << endl;
	cout << "\t";
	for (int x = 0; x < width; x++)//линия разделитильная
	{
		if (x != 0)
		{
			cout << "\"";
		}
		else
		{
			cout << " ";
		}

		if (x + 1 == width)
		{
			cout << endl;
		}
	}

	int size = taskList.size;
	Task* tasks = taskList.tasks;

	// Сортировка задач по приоритету в порядке убывания
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (tasks[i].priority < tasks[j].priority)
			{
				// Обмен местами задач с более низким и более высоким приоритетом
				Task temp = tasks[i];
				tasks[i] = tasks[j];
				tasks[j] = temp;
			}
		}
	}
}


void sort_Tasks_By_Time(TaskList& taskList)
{
	int width = 55;
	cout << "\t";
	for (int x = 0; x < width; x++)//линия разделитильная
	{
		if (x != 0)
		{
			cout << "_";
		}
		else
		{
			cout << " ";
		}

		if (x + 1 == width)
		{
			cout << endl;
		}
	}
	cout << fixed << left << setw(20) << "\t|" << fixed << left << setw(36) << "Sorted By Time" << "|" << endl;
	cout << "\t";
	for (int x = 0; x < width; x++)//линия разделитильная
	{
		if (x != 0)
		{
			cout << "\"";
		}
		else
		{
			cout << " ";
		}

		if (x + 1 == width)
		{
			cout << endl;
		}
	}

	int size = taskList.size;
	Task* tasks = taskList.tasks;

	// Сортировка задач по времени в порядке возрастания
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (compare_dates(tasks[i].datetime, tasks[j].datetime) > 0)
			{
				// Если дата задачи i больше даты задачи j, меняем их местами
				Task temp = tasks[i];
				tasks[i] = tasks[j];
				tasks[j] = temp;
			}
		}
	}
}


void editTaskInList(TaskList* list, int index, const char* name, int priority, const char* description, const char* datetime) {
	// Проверяем, что индекс находится в допустимых пределах
	if (index < list->size) {
		// Вызываем функцию editTask для редактирования задачи с указанным индексом
		editTask(&list->tasks[index], name, priority, description, datetime);
	}
}


void addTask(TaskList* list, Task* task) {
	// Проверяем, что размер списка меньше глобального размера
	if (list->size < globCharSize) {
		// Добавляем задачу в список задач
		list->tasks[list->size] = *task;
		// Увеличиваем размер списка на 1
		list->size++;
	}
}


void removeTask(TaskList* list, int index) {
	// Проверяем, что индекс находится в допустимых пределах
	if (index < list->size) {
		// Освобождаем память, выделенную под строки задачи
		delete[] list->tasks[index].name;
		delete[] list->tasks[index].description;
		delete[] list->tasks[index].datetime;

		// Смещаем оставшиеся задачи в списке на одну позицию влево
		for (int i = index; i < list->size - 1; i++) {
			list->tasks[i] = list->tasks[i + 1];
		}

		// Уменьшаем размер списка на 1
		list->size--;
	}
}


void deleteTaskList(TaskList* list) {
	// Освобождаем память, выделенную под строки каждой задачи
	for (int i = 0; i < list->size; i++) {
		delete[] list->tasks[i].name;
		delete[] list->tasks[i].description;
		delete[] list->tasks[i].datetime;
	}

	// Освобождаем память, выделенную под массив задач
	delete[] list->tasks;

	// Освобождаем память, выделенную под сам список задач
	delete list;
}


//-----------------------------------------END-TASKLIST-----------------------------------

//-----------------------------------------INTERFACE--------------------------------------
const char* caseChoose[] =
{
	"\n\t1) Add task",
	"\n\t2) Delete task",
	"\n\t3) Edit task",
	"\n\t4) Search task by title",
	"\n\t5) Search task by priority",
	"\n\t6) Search task by description",
	"\n\t7) Search task by date and time",
	"\n\t8) Display tasks for day",
	"\n\t9) Display tasks for week",
	"\n\t10) Display tasks for month",
	"\n\t11) Sort tasks by priority",
	"\n\t12) Sort tasks by date and time",
	"\n\t13) Display all tasks",
	"\n\t14) Exit"
};

// Функция для вывода соответствующего пункта меню
void menu_Out_Put_In_Func(int item) {
	system("cls");
	cout << caseChoose[item - 1] << endl;
}

// Функция для печати главного меню
void print_Main_Menu() {
	cout << "\n\t MAIN MENU" << endl;
	for (int i = 0; i < 14; i++) {
		cout << caseChoose[i];
	}
	cout << endl;
}

// Функция для вывода сообщения о возврате в главное меню
void menu_Out_Put_Back_To_Menu() {
	cout << "\n\tPress any button to return to MAIN MENU.";
	system("pause>null");
	system("cls");
}

// Функция для вывода сообщения о выходе
void menu_Out_Put_Exit() {
	system("cls");
	cout << "\n\tExit" << endl;
	Sleep(1000);
}


void addTaskThroughUserInput(TaskList* taskList) {
	// Запрос данных для создания новой задачи от пользователя
	char name[globCharSize];
	char description[globCharSize];
	char datetime[globCharSize];
	int priority;

	cout << "Enter task name: ";
	cin_With_Min_Max(name, 4, globCharSize);

	cout << "Enter task description: ";
	cin_With_Min_Max(description, 1, globCharSize);

	cout << "Enter task date and time: ";
	cin_With_Min_Max_Date(datetime, 0, 0, fullDate);

	cout << "Enter task priority (from 1 to 5): ";
	cin_With_Min_Max(priority, 1, 5);

	// Создание новой задачи с полученными данными и добавление ее в список задач
	addTask(taskList, createTask(name, priority, description, datetime));

	// Отображение обновленного списка задач
	displayTasks(taskList);
}

void editTaskThroughUserInput(TaskList* taskList, int index) {
	if (index < taskList->size) {
		// Запрос новых данных для редактирования задачи от пользователя
		char name[globCharSize];
		char description[globCharSize];
		char datetime[globCharSize];
		int priority;

		cout << "Enter new task name: ";
		cin_With_Min_Max(name, 4, globCharSize);

		cout << "Enter new task description: ";
		cin_With_Min_Max(description, 1, globCharSize);

		cout << "Enter new task date and time: ";
		cin_With_Min_Max_Date(datetime, 0, 0, fullDate);

		cout << "Enter task priority (from 1 to 5): ";
		cin_With_Min_Max(priority, 1, 5);

		// Редактирование задачи с указанным индексом в списке
		editTask(&taskList->tasks[index], name, priority, description, datetime);
	}
}

void searchTaskByName(TaskList* taskList) {
	// Запрос имени задачи для поиска от пользователя
	char* str = new char[globCharSize];

	cout << "Enter task name: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// Поиск задачи по имени в списке задач
	search_Task_By_Name(taskList, str);

	delete[] str;
}

void searchTaskByDescription(TaskList* taskList) {
	// Запрос описания задачи для поиска от пользователя
	char* str = new char[globCharSize];

	cout << "Enter task description: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// Поиск задачи по описанию в списке задач
	search_Task_By_Description(taskList, str);

	delete[] str;
}

void searchTaskByDateTime(TaskList* taskList) {
	// Запрос даты и времени задачи для поиска от пользователя
	char* str = new char[globCharSize];

	cout << "Enter task date and time: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// Поиск задачи по дате и времени в списке задач
	search_Task_By_Date_Time(taskList, str);

	delete[] str;
}

void menu_Out_Put_In_Func_Row_Empty(int item) {
	const char* caseChoose[] = {
		"\n\tSorry, the task list is empty. Please add a task before deleting it.",
		"\n\tSorry, the task list is empty. Please add a task before editing it.",
		"\n\tSorry, the task list is empty. Please add a task before searching by task title.",
		"\n\tSorry, the task list is empty. Please add a task before searching by task priority.",
		"\n\tSorry, the task list is empty. Please add a task before searching by task description.",
		"\n\tSorry, the task list is empty. Please add a task before searching by date and time.",
		"\n\tSorry, the task list is empty. There are no tasks to display for the selected day.",
		"\n\tSorry, the task list is empty. There are no tasks to display for the selected week.",
		"\n\tSorry, the task list is empty. There are no tasks to display for the selected month.",
		"\n\tSorry, the task list is empty. Please add tasks before sorting them by priority.",
		"\n\tSorry, the task list is empty. Please add tasks before sorting them by date and time.",
		"\n\tSorry, the task list is empty. There are no tasks to display.",
	};

	system("cls");

	cout << caseChoose[item - 1] << endl;
}



//-----------------------------------------END-INTERFACE----------------------------------
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand(time(NULL)); rand();//генерация псевдо cлуч чисел
	//int varRandNumber = varMin + rand() % (varMax - varMin + 1);// пример
//----------------------------------------------------------------------------------------
	bool exitFlag = false; // Флаг для проверки завершения программы
	int menuCommand = 0; // Переменная для хранения выбранной команды меню

	TaskList* myTasks = createTaskList(); // Создание списка задач

	while (exitFlag != true)
	{
		print_Main_Menu(); // Вывод главного меню

		cin_With_Min_Max(menuCommand, 1, 14); // Запрос выбора команды у пользователя

		switch (menuCommand)
		{
		case 1:
			menu_Out_Put_In_Func(menuCommand);
			addTaskThroughUserInput(myTasks); // Добавление задачи через ввод данных от пользователя
			menu_Out_Put_Back_To_Menu();
			break;

		case 2:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(1); // Вывод сообщения о пустом списке задач
			}
			else {
				displayTasks(myTasks); // Отображение списка задач
				cin_With_Min_Max(menuCommand, 1, myTasks->size); // Запрос выбора задачи для удаления
				removeTask(myTasks, menuCommand - 1); // Удаление задачи
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 3:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(2); // Вывод сообщения о пустом списке задач
			}
			else {
				displayTasks(myTasks); // Отображение списка задач
				cin_With_Min_Max(menuCommand, 1, myTasks->size); // Запрос выбора задачи для редактирования
				editTaskThroughUserInput(myTasks, menuCommand - 1); // Редактирование задачи
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 4:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(3); // Вывод сообщения о пустом списке задач
			}
			else {
				searchTaskByName(myTasks); // Поиск задачи по имени
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 5:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(4); // Вывод сообщения о пустом списке задач
			}
			else {
				cin_With_Min_Max(menuCommand, 1, 5); // Запрос выбора приоритета задачи
				search_Task_By_Priority(myTasks, menuCommand); // Поиск задачи по приоритету
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 6:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(5); // Вывод сообщения о пустом списке задач
			}
			else {
				searchTaskByDescription(myTasks); // Поиск задачи по описанию
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 7:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(6); // Вывод сообщения о пустом списке задач
			}
			else {
				searchTaskByDateTime(myTasks); // Поиск задачи по дате и времени
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 8:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(7); // Вывод сообщения о пустом списке задач
			}
			else {
				display_tasks_for_day(myTasks); // Отображение задач для выбранного дня
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 9:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(8); // Вывод сообщения о пустом списке задач
			}
			else {
				display_tasks_for_week(myTasks); // Отображение задач для выбранной недели
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 10:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(9); // Вывод сообщения о пустом списке задач
			}
			else {
				display_tasks_for_month(myTasks); // Отображение задач для выбранного месяца
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 11:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(10); // Вывод сообщения о пустом списке задач
			}
			else {
				sort_Tasks_By_Priority(*myTasks); // Сортировка задач по приоритету
				displayTasks(myTasks); // Отображение отсортированного списка задач
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 12:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(11); // Вывод сообщения о пустом списке задач
			}
			else {
				sort_Tasks_By_Time(*myTasks); // Сортировка задач по времени
				displayTasks(myTasks); // Отображение отсортированного списка задач
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 13:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(12); // Вывод сообщения о пустом списке задач
			}
			else {
				displayTasks(myTasks); // Отображение списка задач
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 14:
			menu_Out_Put_In_Func(menuCommand);
			menu_Out_Put_Exit(); // Вывод сообщения о выходе из программы
			deleteTaskList(myTasks); // Освобождение памяти, выделенной под список задач
			exitFlag = true; // Установка флага завершения программы
			break;

		default:
			break;
		}
	}

}
