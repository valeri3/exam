#include <iostream>
#include <iomanip>//��������� ��� ������������ ���� � cout
#include "windows.h"//����������� �����
#include <locale>

using namespace std;

const unsigned int globCharSize = 55;
//----------------str----------------
// ������� ��� ����������� ����� ������
int my_Str_Len(const char* str)
{
	int ind = 0;  // ������ ��� ������� �� �������� ������

	// ���������� ������� ������ �� ��� ���, ���� �� ��������� ������� '\0' (����� ������)
	// � ����������� ������ ��� ������ ��������
	for (ind; str[ind] != '\0'; ind++) {}

	return ind;  // ���������� ���������� ����� ������
}

// ������� ��� �������������� ������� � ������ �������
char my_Str_To_Lower_Case(char ch)
{
	if (ch >= 'A' && ch <= 'Z'  // ���������, �������� �� ������ ��������� ��������� ������
		|| ch >= '�' && ch <= '�')  // ���������, �������� �� ������ ��������� ������������� ������
	{
		return ch + 32;  // ���������� ������, ��������������� � ��������������� ������ ������� ��������
	}

	return ch;  // ���� ������ �� �������� ��������� ������, ���������� ��� ��� ���������
}

// ������� ��� ����������� ������
char* my_Str_Cpy(const char* source, char* destination)
{
	char* ptr = destination;  // ��������� ��������� �� ������ ������� ������

	while (*source != '\0')  // ���� �� ��������� ����� �������� ������
	{
		*destination = *source;  // �������� ������ �� �������� ������ � ������� ������
		destination++;  // ����������� ��������� ������� ������
		source++;  // ����������� ��������� �������� ������
	}

	*destination = '\0';  // ������������� ������� ������ � ����� ������� ������, ��������� �� �����

	return ptr;  // ���������� ��������� �� ������ ������� ������
}

// ������� ��� ��������� ���� �����
int my_Str_Cmp(const char* str1, const char* str2)
{
	while (*str1)
	{
		// ���� ������� ���������� ��� ��������� ����� ������ ������,
		// ���������� ��������� � ������� �� �����
		if (*str1 != *str2)
		{
			break;
		}

		// ��������� � ��������� ���� ��������
		str1++;
		str2++;
	}

	// ���������� ������� ASCII ����� �������������� `char*` � `unsigned char*`
	return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

// ���������� ������� my_Str_Cmp ������������ ��������� �������� ���� �����, �������� ����������� str1 � str2.
// �������� length ���������� ���������� ��������, ������� ��������� ��������.
// ������� ���������� 0, ���� ��� ������������ ������� ���������, � 1 � ��������� ������.
int my_Str_Cmp(const char* str1, const char* str2, int length)
{
	for (int i = 0; i < length; i++)
	{
		// ���������� ������� str1[i] � str2[i]
		if (str1[i] != str2[i])
			return 1; // ���� ������� ������������ ��������, ���������� 1
	}
	return 0; // ���� ��� ������������ ������� ���������, ���������� 0
}

//������� ��������� ������������(�����������) ���� �����.
void my_Str_Cat(char* destination, const char* source)
{
	// ���������� ��������� � ����� ������� ������
	while (*destination)
	{
		destination++;
	}

	// �������� ������� �� ������ ������ � ����� ������� ������
	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}

	// ��������� ������� ������ � ����� ������� ������
	*destination = '\0';
}

// ������� ��� �������� ������ �� ������� ������ ��������
bool my_Str_With_Space(const char* str)
{

	while (*str != '\0')  // ���� �� ��������� ������ ����� ������ '\0'
	{
		if (*str != ' ')  // ���� ������� ������ �� �������� ��������
		{
			return false;  // ���������� false, ��� ��� ������ �������� ������� �������� �� �������
		}
		str++;  // ��������� � ���������� �������
	}
	return true;  // ���� ������ ������� ������ �� ��������, ���������� true
}

int my_Str_Char_To_int(const char* str)
{
	int result = 0;  // ��������� �������������� ������ � �����
	int sign = 1;   // ���� ����� (�� ��������� �������������)
	int i = 0;      // ������ ������� � ������

	// �������� �� ������������� �����
	if (str[0] == '-')
	{
		sign = -1;  // ���� ������ ������ '-' - ����� �������������
		i = 1;      // �������� ���������� ����� �� ������� �������
	}

	// ���� ���������� ���� �� ������ � �������������� �� � �����
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		result = result * 10 + (str[i] - '0');  // ��������� �������� �������� �� 10 � ���������� ����� �����
		i++;  // ������� � ���������� ������� ������
	}

	return result * sign;  // ���������� ��������� � ������ �����
}

void int_To_Str(int num, char str[]) {
	int i = 0;

	// ���� ����� ����� ����, ���������� ������ '0' � ������
	if (num == 0) {
		str[i++] = '0';
	}
	// �����, ���� ����� �������������
	else {
		if (num < 0) {
			str[i++] = '-';
			num = -num; // �������� ����� � �������������� �������� ��� ���������� ���������
		}

		// ������� ��������������� ����� � ������
		while (num > 0) {
			str[i++] = '0' + (num % 10); // �������� ������� �� ������� ����� �� 10 � ����������� ��� � ������
			num /= 10; // ������ ������������� ������� ����� �� 10 ��� �������� � ��������� �����
		}
	}

	str[i] = '\0'; // ��������� ������� ������ � ����� ������, ����� ���������� �� �����
}


// ������� my_Str_Reverse ����������� (�������������) �������� ������ str.
// �������� str �������� �������� ��������, �������������� ������.
void my_Str_Reverse(char str[]) {
	int length = my_Str_Len(str); // ���������� ����� ������

	int start = 0; // ������ ���������� �������
	int end = length - 1; // ������ ��������� �������

	while (start < end) {
		// ����� ���������: ������ ������ ���������� ���������, ������ - ������������� � ��� �����
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		// ������� � ��������� ��������
		start++;
		end--;
	}
}


//---------------------cin_Min_Max------------------------
enum AllowType {
	only_symbols,   // ��������� ������ �������, ������� ����� (�������� � ���������) � �������
	only_numbers,   // ��������� ������ �����
	universal,      // ��������� �������: ����� (�������� � ���������), ����� � �������
	numbers_float,  // ��������� ����� � ��������� ������
	universal_numbers_float,   // ��������� �������: ����� (�������� � ���������), �����, ������� � ����� � ��������� ������
};

void cin_With_Min_Max(char str[], const int min, const int max, AllowType allowType = only_symbols)
{
	const char delim = '\n';  // ����������� ��� ����� ������

	while (true)  // ����������� ���� ��� ����� ������ � ����������
	{
		bool inFormat = true;  // ����, ����������� �� ���������� ������ ����� ������

		cin.getline(str, globCharSize);  // ������ ������ �� �������� ������ � ���������� � � ���������� str

		int length = my_Str_Len(str);  // ���������� ����� ������ ��� ������ ������� my_Str_Len. ��������� ����������� � ���������� length.

		// �������� ������ ������
		if (length == 0)
		{
			inFormat = false;  // ������ �����������, ���� ������ ������
		}
		// �������� ������, ��������� ������ �� ��������
		else if (my_Str_With_Space(str))
		{
			inFormat = false;  // ������ �����������, ���� ������ ������� ������ �� ��������
		}
		// �������� ����� ������
		else if (length < min && length > max)
		{
			inFormat = false;  // ������ �����������, ���� ����� ������ �� ������������� �������� ������������
		}
		else
		{
			// �������� ��������
			for (int i = 0; i < length; i++)
			{
				switch (allowType)
				{
				case only_symbols:
					// �������� �� ����������� ������� (����� � ������)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= '�' && str[i] <= '�')
						|| (str[i] >= '�' && str[i] <= '�')
						|| str[i] == ' '))
					{
						inFormat = false;  // ������ �����������, ���� ������ �� �������� �����������
						break;
					}
					break;

				case only_numbers:
					// �������� �� ����������� ������� (�����)
					if (!(str[i] >= '0' && str[i] <= '9'))
					{
						inFormat = false;  // ������ �����������, ���� ������ �� �������� �����������
						break;
					}
					break;

				case universal:
					// �������� �� ����������� ������� (�����, ����� � ������)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= '�' && str[i] <= '�')
						|| (str[i] >= '�' && str[i] <= '�')
						|| str[i] == ' '
						|| (str[i] >= '0' && str[i] <= '9')))
					{
						inFormat = false;  // ������ �����������, ���� ������ �� �������� �����������
						break;
					}
					break;

				case numbers_float:
					// �������� �� ����������� ������� (����� � �����)
					if (!((str[i] >= '0' && str[i] <= '9')
						|| str[i] == '.'))
					{
						inFormat = false;  // ������ �����������, ���� ������ �� �������� �����������
						break;
					}
					break;

				case universal_numbers_float:
					// �������� �� ����������� ������� (�����, �����, ������ � ����� � ��������� ������)
					if (!((str[i] >= 'a' && str[i] <= 'z')
						|| (str[i] >= 'A' && str[i] <= 'Z')
						|| (str[i] >= '�' && str[i] <= '�')
						|| (str[i] >= '�' && str[i] <= '�')
						|| str[i] == ' '
						|| (str[i] >= '0' && str[i] <= '9')
						|| str[i] == '.'))
					{
						inFormat = false;  // ������ �����������, ���� ������ �� �������� �����������
						break;
					}
					break;

				}
			}
		}

		if (inFormat)
		{
			break;  // ���� ������ ���������, ������� �� �����
		}
		else
		{
			if (cin.fail())
			{
				cin.clear();  // ���������� ���� ������ �����
				cin.ignore(globCharSize, delim);  // ������� ����� �����
			}

			cout << "\nWrong size or format, please enter correct parameters,"
				<< " min size: " << min
				<< ", max size: " << max << endl;
		}
	}
}

// ���������� ������� cin_With_Min_Max ��� ������������� ��������.
// ������� ������������� ��� ����� �������� � ��������� �� ����������� � ������������ ���������� ��������.
void cin_With_Min_Max(int& choose, const int min, const int max)
{
	char strInt[globCharSize];  // ������ �������� ��� �������� ������ � �������

	bool isValid = false;
	cin.clear();  // ������� ����� �����

	while (isValid != true)
	{
		cin_With_Min_Max(strInt, min, max, only_numbers);  // ������ ������ � �������, ������������ ���������� (�� 1 �� max)
		choose = my_Str_Char_To_int(strInt); // ����������� ������ � ����� �����

		if (choose >= min && choose <= max)
		{
			isValid = true; // ��������� �������� ��������� � ���������� ���������, ������� �� �����
			break;
		}

		// ������� ��������� �� ������, ���� ��������� �������� ��������� ��� ����������� ���������
		cout << "\nWrong size or format, please enter correct parameters. It should be from " << min << " to " << max << "." << endl;

		cout << "\nEnter again: ";
	}
}

//---------------------------------------cin_Min_Max_Date----------------------------------------
// ������� isLeapYear ���������, �������� �� �������� ��� ����������.
// ���������� true, ���� ��� ����������, � false � ��������� ������.
bool isLeapYear(int year)
{
	return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
}

// ������� maxDaysInMonth ���������� ������������ ���������� ���� � �������� ������ ��� ��������� ����.
// �������� month ���������� ����� ������ (�� 1 �� 12).
// �������� year ���������� ���.
// ���������� ���������� ���� � ������ ��� -1 � ������ ������.
int maxDaysInMonth(int month, int year)
{
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31; // � ������, �����, ���, ����, �������, ������� � ������� 31 ����
	case 4: case 6: case 9: case 11:
		return 30; // � ������, ����, �������� � ������ 30 ����
	case 2:
		return isLeapYear(year) ? 29 : 28; // � ������� 29 ����, ���� ��� ����������, ����� 28 ����
	default:
		return -1;  // ������ - ������������ ����� ������
	}
}

enum AllowDateType {
	day,   // ���� ���
	month, // ���� ������
	year,   // ���� ����
	fullDate// ���� ������ ����
};


// ������� cin_With_Min_Max_Date ������������� ��� ����� ���� � ��������� �� ����������� � ������������ ���������� ��������.
// �������� str ������������ ������ ��������, � ������� ����� ��������� ��������� ����.
// ��������� currentYear � currentMonth ������������ ��� �������� ��������� ���� � ��������� �������� ���� � ������.
// �������� allowDateType ���������� ��� �������� ���� (����, �����, ���).
void cin_With_Min_Max_Date(char str[], int currentYear = 0, int currentMonth = 0, AllowDateType allowDateType = day) {
	const char delim = '\n';  // ����������� ��� ����� ������

	while (true) {
		bool inFormat = true;

		// ���������, ���� ��������� ���� ������ ����
		if (allowDateType == fullDate) {
			int day, month, year;

			// ���� ���
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

			// ���� ������
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

			// ���� ����
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

			// ������� �������� ������ ����� ��������������� ����
			str[0] = '\0';

			// ����������� ���� � ������������� � �������� ������ ��� ���, ������ � ����
			char dayStr[3];
			char monthStr[3];
			char yearStr[5];
			int_To_Str(day, dayStr);
			int_To_Str(month, monthStr);
			int_To_Str(year, yearStr);

			// ����� �� ����� ����������� ����, ����� � ���
			my_Str_Reverse(dayStr);
			my_Str_Reverse(monthStr);
			my_Str_Reverse(yearStr);

			// ����������� ���� � ������������� � �������� ������ ��� ���, ������ � ����
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
			cin.ignore(); // ���������� ������ ����� ������, ���������� ����� ����������� �����
			cin.getline(str, globCharSize);

			int length = my_Str_Len(str);

			// �������� �� ������� ����� ������ ��� ������� ��������
			if (length == 0 || my_Str_With_Space(str)) {
				inFormat = false;
			}
			else {
				// ���������, ������� �� ������ ������ �� ����
				for (int i = 0; i < length; i++) {
					if (!(str[i] >= '0' && str[i] <= '9')) {
						inFormat = false;
						break;
					}
				}

				if (inFormat) {
					int inputValue = my_Str_Char_To_int(str);

					// ��������� ��������� �������� � ������������ � ����� ���� (����, �����, ���)
					switch (allowDateType) {
					case day:
						if (currentYear == 0 || currentMonth == 0) {
							// ���������, ���� ��� ��� ����� �� �������, �� ���� ������ ���� � ��������� 1-31
							if (inputValue < 1 || inputValue > 31) {
								inFormat = false;
							}
						}
						else {
							// ���������, ���� ��� � ����� �������, �� ���� ������ ���� � ��������� 1-������������ ���������� ���� � ��������� ������ � ����
							if (inputValue < 1 || inputValue > maxDaysInMonth(currentMonth, currentYear)) {
								inFormat = false;
							}
						}
						break;
					case month:
						// ���������, ��� ��������� ����� ��������� � ��������� 1-12
						if (inputValue < 1 || inputValue > 12) {
							inFormat = false;
						}
						break;
					case year:
						// ���������, ��� ��������� ��� ��������� � ��������� 1970-2170
						if (inputValue < 1970 || inputValue > 2170) {
							inFormat = false;
						}
						break;
					}
				}
			}

			// ���� ������ �� ������������� �����������, ������� ��������� �� ������
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
	int tm_mday;  // ���� ������, �� 1 �� 31
	int tm_mon;   // �����,  �� 0 �� 11
	int tm_year;  // ���������� ��� � 1900
};

// ������� string_to_my_tm ����������� ������ � ����� � ��������� my_tm.
void string_to_my_tm(const char* date_str, struct my_tm* my_tm)
{
	char day[3] = { date_str[0], date_str[1], '\0' };    //1/02/2023
	char month[3] = { date_str[3], date_str[4], '\0' };
	char year[5] = { date_str[6], date_str[7], date_str[8], date_str[9], '\0' };

	// �������� ����, ����� � ��� �� ������ ����
	char day_copied[3];
	char month_copied[3];
	char year_copied[5];

	my_Str_Cpy(day, day_copied);
	my_Str_Cpy(month, month_copied);
	my_Str_Cpy(year, year_copied);

	// ����������� ����, ����� � ��� � �������� �������� � ��������� � ���������
	my_tm->tm_mday = my_Str_Char_To_int(day_copied); // ����������� ���� � ����� �����
	my_tm->tm_mon = my_Str_Char_To_int(month_copied) - 1; // ����������� ����� � ����� ����� � �������� 1, ��� ��� ������ ������� ���������� � 0
	my_tm->tm_year = my_Str_Char_To_int(year_copied) - 1900; // ����������� ��� � ����� ����� � �������� 1900, ��� ��� ������ ��� ���������� � 1900
}

int my_mktime(my_tm* my_tm) {
	// ������� �������������� ���� � �������� ��������
	// �������� ��������, ��� ��� �� ����� ��������������� ��������� �������, �� ����� �������������� ��� ��������� ���
	return my_tm->tm_year * 365 + my_tm->tm_mon * 30 + my_tm->tm_mday;
}

// ������� compare_dates ���������� ��� ����, �������������� � ���� �����.

int compare_dates(const char* date1, const char* date2) {
	// ��������� �������� ���, ������ � ���� �� ������ ����
	int day1 = my_Str_Char_To_int(date1);
	int month1 = my_Str_Char_To_int(date1 + 3);
	int year1 = my_Str_Char_To_int(date1 + 6);

	// ��������� �������� ���, ������ � ���� �� ������ ����
	int day2 = my_Str_Char_To_int(date2);
	int month2 = my_Str_Char_To_int(date2 + 3);
	int year2 = my_Str_Char_To_int(date2 + 6);

	// ���������� ����
	if (year1 < year2) return -1;
	if (year1 > year2) return 1;

	// ���������� ������
	if (month1 < month2) return -1;
	if (month1 > month2) return 1;

	// ���������� ���
	if (day1 < day2) return -1;
	if (day1 > day2) return 1;

	return 0; // ���� �����
}


int date_to_week_number(my_tm* date) {
	// ����� ���������� ���� � ������ ������ (�� ��������� ���������� ����)
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// ��������� ���� ����
	int day_of_year = date->tm_mday;
	for (int i = 0; i < date->tm_mon; i++) {
		day_of_year += days_in_month[i];
	}

	// ��������� ����� ������
	int week_number = (day_of_year - 1) / 7 + 1;

	return week_number;
}

//-----------------------------------------Task-------------------------------------------

//-----------------------------------------Task-------------------------------------------
struct Task
{
	char* name;          // ��� ������
	int priority;        // ��������� ������
	char* description;   // �������� ������
	char* datetime;      // ���� � ����� ������
};

// ������� createTask ������� ����� ������ � �������������� �� ���� ���������� ���������� ����������.
// ���������� ��������� �� ��������� ������.
Task* createTask(const char* name, int priority, const char* description, const char* datetime)
{
	Task* newTask = new Task; // ������� ����� ������ ���� Task

	// ������� ����� ������ ��� ���� name � �������� ����������
	newTask->name = new char[globCharSize];
	my_Str_Cpy(name, newTask->name);

	newTask->priority = priority; // ����������� ���� priority �������� ��������� priority

	// ������� ����� ������ ��� ���� description � �������� ����������
	newTask->description = new char[globCharSize];
	my_Str_Cpy(description, newTask->description);

	// ������� ����� ������ ��� ���� datetime � �������� ����������
	newTask->datetime = new char[globCharSize];
	my_Str_Cpy(datetime, newTask->datetime);

	return newTask; // ���������� ��������� �� ��������� ������
}


// ������� editTask �������� �������� ����� ������������ ������ �� ����� ��������, ���������� � ����������.
void editTask(Task* task, const char* name, int priority, const char* description, const char* datetime) {
	// �������� ����� ��� ������ � ���� name
	my_Str_Cpy(name, task->name);

	// ����������� ����� �������� ���������� ������ ���� priority
	task->priority = priority;

	// �������� ����� �������� ������ � ���� description
	my_Str_Cpy(description, task->description);

	// �������� ����� ���� � ����� ������ � ���� datetime
	my_Str_Cpy(datetime, task->datetime);
}

//---------------------------------------END-TASK----------------------------------------

//---------------------------------------TaskList-----------------------------------------
// ��������� TaskList ������������ ������ �����.
struct TaskList
{
	int size;       // ������ ������ �����
	Task* tasks;    // ��������� �� ������ �����
};


// ������� createTaskList ������� ����� ������ ����� � �������������� ��� ����.
// ���������� ��������� �� ��������� ������ �����.
TaskList* createTaskList() {
	TaskList* newList = new TaskList; // ������� ����� ������ ���� TaskList

	newList->tasks = new Task[globCharSize]; // �������� ������ ��� ������� ����� �������� globCharSize
	newList->size = 0; // �������������� ������ ������ ����� ������� ���������

	return newList; // ���������� ��������� �� ��������� ������ �����
}

// ������� displayTasks ������� ������ ����� �� �����.

void displayTasks(TaskList* list) {
	int width = 55; // ������ ���������� ����� �����

	// ����� �����-�����������
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

	// ����� ��������� ������ �����
	cout << fixed << left << setw(23) << "\t|" << fixed << left << setw(33) << "TASK LIST" << "|" << endl;

	// ����� ������ ������ � ������
	for (int i = 0; i < list->size; i++) {
		// ����� �����-�����������
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

		// ����� ������ ������, ���������� � ���� � �������
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
		cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << list->tasks[i].priority << fixed << left << setw(2) << "|";
		cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << list->tasks[i].datetime << fixed << left << setw(2) << "|" << endl;

		// ����� �����-�����������
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

		// ����� ����� ������
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << list->tasks[i].name << fixed << left << setw(2) << "|" << endl;

		// ����� �����-�����������
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

		// ����� �������� ������
		cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << list->tasks[i].description << fixed << left << setw(2) << "|" << endl;

		// ����� �����-�����������
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


// ������� search_Task_By_Name ��������� ����� ������ �� �������� � ������ �����.
// ������� ��������� ������ �� �����.
void search_Task_By_Name(TaskList* list, const char* name) {
	// ��������� ������ ��� ��������� �����
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// �������������� ��������� ������ � ������ �������
	int nameLength = my_Str_Len(name);
	for (int i = 0; i < nameLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(name[i]);
	}
	strToFind[nameLength] = '\0'; // �������� ������

	bool notFound = true;  // ����, ����������� �� ��������� ������ (�� �������)

	// ����� ������ �� ��������
	for (int i = 0; i < list->size; i++) {
		// �������������� �������� ������ � ������ �������
		int taskNameLength = my_Str_Len(list->tasks[i].name);
		for (int j = 0; j < taskNameLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].name[j]);
		}
		strTmp[taskNameLength] = '\0'; // �������� ������

		// ��������� ���������� �������� � ��������� ������
		for (int j = 0; j <= nameLength - 2; j++) {
			for (int k = 0; k <= taskNameLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, nameLength)) {
					// ����� ��������� ������
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

					notFound = false;  // ����� ������� (������� ������)
					break;
				}
			}
			if (!notFound)
				break;
		}
	}

	// ����� ���������, ���� ������ �� �������
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

	// ������������ ������
	delete[] strToFind;
	delete[] strTmp;
}

// ������� search_Task_By_Priority ��������� ����� ������ �� ���������� � ������ �����.
// ������� ��������� ������ �� �����.
void search_Task_By_Priority(TaskList* list, int priority) {
	bool notFound = true;  // ����, ����������� �� ��������� ������ (�� �������)

	// ����� ������ �� ����������
	for (int i = 0; i < list->size; i++) {
		if (list->tasks[i].priority == priority) {
			// ����� ��������� ������
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

			notFound = false;  // ����� ������� (������� ������)
			break;
		}
	}

	// ����� ���������, ���� ������ �� �������
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


// ������� search_Task_By_Description ��������� ����� ������ �� �������� � ������ �����.
// ������� ��������� ������ �� �����.
void search_Task_By_Description(TaskList* list, const char* description) {
	// ��������� ������ ��� ��������� �����
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// �������������� ��������� ������ � ������ �������
	int descriptionLength = my_Str_Len(description);
	for (int i = 0; i < descriptionLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(description[i]);
	}
	strToFind[descriptionLength] = '\0'; // �������� ������

	bool notFound = true;  // ����, ����������� �� ��������� ������ (�� �������)

	// ����� ������ �� ��������
	for (int i = 0; i < list->size; i++) {
		// �������������� �������� ������ � ������ �������
		int taskDescriptionLength = my_Str_Len(list->tasks[i].description);
		for (int j = 0; j < taskDescriptionLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].description[j]);
		}
		strTmp[taskDescriptionLength] = '\0'; // �������� ������

		// ��������� ���������� �������� � ��������� ������
		for (int j = 0; j <= descriptionLength - 2; j++) {
			for (int k = 0; k <= taskDescriptionLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, descriptionLength)) {
					// ����� ��������� ������
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

					notFound = false;  // ����� ������� (������� ������)
					break;
				}
			}
			if (!notFound) {
				break;
			}
		}
	}

	// ����� ���������, ���� ������ �� �������
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

	// ������������ ������
	delete[] strToFind;
	delete[] strTmp;
}


// ������� search_Task_By_Date_Time ��������� ����� ������ �� ���� � ������� � ������ �����.
// ������� ��������� ������ �� �����.

void search_Task_By_Date_Time(TaskList* list, const char* datetime) {
	// ��������� ������ ��� ��������� �����
	char* strToFind = new char[globCharSize];
	char* strTmp = new char[globCharSize];

	// �������������� ��������� ������ � ������ �������
	int dateTimeLength = my_Str_Len(datetime);
	for (int i = 0; i < dateTimeLength; i++) {
		strToFind[i] = my_Str_To_Lower_Case(datetime[i]);
	}
	strToFind[dateTimeLength] = '\0'; // �������� ������

	bool notFound = true;  // ����, ����������� �� ��������� ������ (�� �������)

	// ����� ������ �� ���� � �������
	for (int i = 0; i < list->size; i++) {
		// �������������� ���� � ������� ������ � ������ �������
		int taskDateTimeLength = my_Str_Len(list->tasks[i].datetime);
		for (int j = 0; j < taskDateTimeLength; j++) {
			strTmp[j] = my_Str_To_Lower_Case(list->tasks[i].datetime[j]);
		}
		strTmp[taskDateTimeLength] = '\0'; // �������� ������

		// ��������� ��������� ���� � ������� � ����� � �������� ������
		for (int j = 0; j <= dateTimeLength - 2; j++) {
			for (int k = 0; k <= taskDateTimeLength - 2; k++) {
				if (!my_Str_Cmp(strToFind + j, strTmp + k, dateTimeLength)) {
					// ����� ��������� ������
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

					notFound = false;  // ����� ������� (������� ������)
					break;
				}
			}
			if (!notFound) {
				break;
			}
		}
	}

	// ����� ���������, ���� ������ �� �������
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

	// ������������ ������
	delete[] strToFind;
	delete[] strTmp;
}


// ����������� ������� display_task
void display_task(Task* task) {
	int width = 55;

	// ����� ���������� � ���� � ������� ������
	cout << "\t" << fixed << left << setw(10) << "Priority:" << fixed << left << setw(2) << task->priority << fixed << left << setw(2) << "|";
	cout << "\t" << fixed << left << setw(10) << "Datetime:" << fixed << left << setw(13) << task->datetime << fixed << left << setw(2) << "|" << endl;

	cout << "\t";
	for (int j = 0; j < width; j++) {
		// ����� �������������� �����
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

	// ����� �������� ������
	cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Name: " << fixed << left << setw(36) << task->name << fixed << left << setw(2) << "|" << endl;
	cout << "\t";
	for (int j = 0; j < width; j++) {
		// ����� �������������� �����
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

	// ����� �������� ������
	cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(17) << "Description: " << fixed << left << setw(36) << task->description << fixed << left << setw(2) << "|" << endl;
	cout << "\t";
	for (int j = 0; j < width; j++) {
		// ����� �������������� �����
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


// �������, ������� ���������� ������ ��� ������������� ���
void display_tasks_for_day(TaskList* list)
{
	char date_str[globCharSize];
	cout << "Please enter the day number (1 to 31): ";
	cin_With_Min_Max_Date(date_str, 0, 0, day);

	my_tm date;
	string_to_my_tm(date_str, &date);
	int tasks_found = 0;

	// ����� �����, ��������� � ��������� ����
	for (int i = 0; i < list->size; i++) {
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		if (task_date.tm_mday == date.tm_mday)
		{
			int width = 55;

			// ����� ���������� � ��������� �������
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

			// ����� ������ ������ � ���������� � ������
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// ����� ���������, ���� ������ �� �������
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


// �������, ������� ���������� ������ ��� ������������ ������
void display_tasks_for_week(TaskList* list) {
	int week_number;
	cout << "Please enter the week number (1 to 52): ";
	cin >> week_number;

	int tasks_found = 0;

	// ����� �����, ��������� � ��������� �������
	for (int i = 0; i < list->size; i++)
	{
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		if (date_to_week_number(&task_date) == week_number)
		{
			int width = 55;

			// ����� ���������� � ��������� �������
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

			// ����� ������ ������ � ���������� � ������
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// ����� ���������, ���� ������ �� �������
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


// �������, ������� ���������� ������ ��� ������������� ������
void display_tasks_for_month(TaskList* list) {
	int month_number;
	cout << "Please enter the month number (1 to 12): ";
	cin_With_Min_Max(month_number, 1, 12);

	int tasks_found = 0;

	// ����� �����, ��������� � ��������� �������
	for (int i = 0; i < list->size; i++)
	{
		my_tm task_date;
		string_to_my_tm(list->tasks[i].datetime, &task_date);

		// ������������ ��������� ����� � ������ ������. ����� ��� ����� �������� 1,
		// ��������� �� ����� ������� ������ ������� � 1, ��� � ������������.
		if (task_date.tm_mon + 1 == month_number)
		{
			int width = 55;

			// ����� ���������� � ��������� �������
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

			// ����� ������ ������ � ���������� � ������
			cout << "\t" << fixed << left << setw(2) << "|" << fixed << left << setw(7) << "Task #" << fixed << left << setw(2) << i + 1 << fixed << left << setw(2) << "|";
			display_task(&list->tasks[i]);
			tasks_found++;
		}
	}

	// ����� ���������, ���� ������ �� �������
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
	for (int x = 0; x < width; x++)//����� ��������������
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
	for (int x = 0; x < width; x++)//����� ��������������
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

	// ���������� ����� �� ���������� � ������� ��������
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (tasks[i].priority < tasks[j].priority)
			{
				// ����� ������� ����� � ����� ������ � ����� ������� �����������
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
	for (int x = 0; x < width; x++)//����� ��������������
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
	for (int x = 0; x < width; x++)//����� ��������������
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

	// ���������� ����� �� ������� � ������� �����������
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (compare_dates(tasks[i].datetime, tasks[j].datetime) > 0)
			{
				// ���� ���� ������ i ������ ���� ������ j, ������ �� �������
				Task temp = tasks[i];
				tasks[i] = tasks[j];
				tasks[j] = temp;
			}
		}
	}
}


void editTaskInList(TaskList* list, int index, const char* name, int priority, const char* description, const char* datetime) {
	// ���������, ��� ������ ��������� � ���������� ��������
	if (index < list->size) {
		// �������� ������� editTask ��� �������������� ������ � ��������� ��������
		editTask(&list->tasks[index], name, priority, description, datetime);
	}
}


void addTask(TaskList* list, Task* task) {
	// ���������, ��� ������ ������ ������ ����������� �������
	if (list->size < globCharSize) {
		// ��������� ������ � ������ �����
		list->tasks[list->size] = *task;
		// ����������� ������ ������ �� 1
		list->size++;
	}
}


void removeTask(TaskList* list, int index) {
	// ���������, ��� ������ ��������� � ���������� ��������
	if (index < list->size) {
		// ����������� ������, ���������� ��� ������ ������
		delete[] list->tasks[index].name;
		delete[] list->tasks[index].description;
		delete[] list->tasks[index].datetime;

		// ������� ���������� ������ � ������ �� ���� ������� �����
		for (int i = index; i < list->size - 1; i++) {
			list->tasks[i] = list->tasks[i + 1];
		}

		// ��������� ������ ������ �� 1
		list->size--;
	}
}


void deleteTaskList(TaskList* list) {
	// ����������� ������, ���������� ��� ������ ������ ������
	for (int i = 0; i < list->size; i++) {
		delete[] list->tasks[i].name;
		delete[] list->tasks[i].description;
		delete[] list->tasks[i].datetime;
	}

	// ����������� ������, ���������� ��� ������ �����
	delete[] list->tasks;

	// ����������� ������, ���������� ��� ��� ������ �����
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

// ������� ��� ������ ���������������� ������ ����
void menu_Out_Put_In_Func(int item) {
	system("cls");
	cout << caseChoose[item - 1] << endl;
}

// ������� ��� ������ �������� ����
void print_Main_Menu() {
	cout << "\n\t MAIN MENU" << endl;
	for (int i = 0; i < 14; i++) {
		cout << caseChoose[i];
	}
	cout << endl;
}

// ������� ��� ������ ��������� � �������� � ������� ����
void menu_Out_Put_Back_To_Menu() {
	cout << "\n\tPress any button to return to MAIN MENU.";
	system("pause>null");
	system("cls");
}

// ������� ��� ������ ��������� � ������
void menu_Out_Put_Exit() {
	system("cls");
	cout << "\n\tExit" << endl;
	Sleep(1000);
}


void addTaskThroughUserInput(TaskList* taskList) {
	// ������ ������ ��� �������� ����� ������ �� ������������
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

	// �������� ����� ������ � ����������� ������� � ���������� �� � ������ �����
	addTask(taskList, createTask(name, priority, description, datetime));

	// ����������� ������������ ������ �����
	displayTasks(taskList);
}

void editTaskThroughUserInput(TaskList* taskList, int index) {
	if (index < taskList->size) {
		// ������ ����� ������ ��� �������������� ������ �� ������������
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

		// �������������� ������ � ��������� �������� � ������
		editTask(&taskList->tasks[index], name, priority, description, datetime);
	}
}

void searchTaskByName(TaskList* taskList) {
	// ������ ����� ������ ��� ������ �� ������������
	char* str = new char[globCharSize];

	cout << "Enter task name: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// ����� ������ �� ����� � ������ �����
	search_Task_By_Name(taskList, str);

	delete[] str;
}

void searchTaskByDescription(TaskList* taskList) {
	// ������ �������� ������ ��� ������ �� ������������
	char* str = new char[globCharSize];

	cout << "Enter task description: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// ����� ������ �� �������� � ������ �����
	search_Task_By_Description(taskList, str);

	delete[] str;
}

void searchTaskByDateTime(TaskList* taskList) {
	// ������ ���� � ������� ������ ��� ������ �� ������������
	char* str = new char[globCharSize];

	cout << "Enter task date and time: ";
	cin_With_Min_Max(str, 1, globCharSize, universal);

	// ����� ������ �� ���� � ������� � ������ �����
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

	srand(time(NULL)); rand();//��������� ������ c��� �����
	//int varRandNumber = varMin + rand() % (varMax - varMin + 1);// ������
//----------------------------------------------------------------------------------------
	bool exitFlag = false; // ���� ��� �������� ���������� ���������
	int menuCommand = 0; // ���������� ��� �������� ��������� ������� ����

	TaskList* myTasks = createTaskList(); // �������� ������ �����

	while (exitFlag != true)
	{
		print_Main_Menu(); // ����� �������� ����

		cin_With_Min_Max(menuCommand, 1, 14); // ������ ������ ������� � ������������

		switch (menuCommand)
		{
		case 1:
			menu_Out_Put_In_Func(menuCommand);
			addTaskThroughUserInput(myTasks); // ���������� ������ ����� ���� ������ �� ������������
			menu_Out_Put_Back_To_Menu();
			break;

		case 2:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(1); // ����� ��������� � ������ ������ �����
			}
			else {
				displayTasks(myTasks); // ����������� ������ �����
				cin_With_Min_Max(menuCommand, 1, myTasks->size); // ������ ������ ������ ��� ��������
				removeTask(myTasks, menuCommand - 1); // �������� ������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 3:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(2); // ����� ��������� � ������ ������ �����
			}
			else {
				displayTasks(myTasks); // ����������� ������ �����
				cin_With_Min_Max(menuCommand, 1, myTasks->size); // ������ ������ ������ ��� ��������������
				editTaskThroughUserInput(myTasks, menuCommand - 1); // �������������� ������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 4:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(3); // ����� ��������� � ������ ������ �����
			}
			else {
				searchTaskByName(myTasks); // ����� ������ �� �����
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 5:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(4); // ����� ��������� � ������ ������ �����
			}
			else {
				cin_With_Min_Max(menuCommand, 1, 5); // ������ ������ ���������� ������
				search_Task_By_Priority(myTasks, menuCommand); // ����� ������ �� ����������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 6:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(5); // ����� ��������� � ������ ������ �����
			}
			else {
				searchTaskByDescription(myTasks); // ����� ������ �� ��������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 7:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(6); // ����� ��������� � ������ ������ �����
			}
			else {
				searchTaskByDateTime(myTasks); // ����� ������ �� ���� � �������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 8:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(7); // ����� ��������� � ������ ������ �����
			}
			else {
				display_tasks_for_day(myTasks); // ����������� ����� ��� ���������� ���
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 9:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(8); // ����� ��������� � ������ ������ �����
			}
			else {
				display_tasks_for_week(myTasks); // ����������� ����� ��� ��������� ������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 10:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(9); // ����� ��������� � ������ ������ �����
			}
			else {
				display_tasks_for_month(myTasks); // ����������� ����� ��� ���������� ������
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 11:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(10); // ����� ��������� � ������ ������ �����
			}
			else {
				sort_Tasks_By_Priority(*myTasks); // ���������� ����� �� ����������
				displayTasks(myTasks); // ����������� ���������������� ������ �����
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 12:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(11); // ����� ��������� � ������ ������ �����
			}
			else {
				sort_Tasks_By_Time(*myTasks); // ���������� ����� �� �������
				displayTasks(myTasks); // ����������� ���������������� ������ �����
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 13:
			menu_Out_Put_In_Func(menuCommand);
			if (myTasks->size < 1) {
				menu_Out_Put_In_Func_Row_Empty(12); // ����� ��������� � ������ ������ �����
			}
			else {
				displayTasks(myTasks); // ����������� ������ �����
			}
			menu_Out_Put_Back_To_Menu();
			break;

		case 14:
			menu_Out_Put_In_Func(menuCommand);
			menu_Out_Put_Exit(); // ����� ��������� � ������ �� ���������
			deleteTaskList(myTasks); // ������������ ������, ���������� ��� ������ �����
			exitFlag = true; // ��������� ����� ���������� ���������
			break;

		default:
			break;
		}
	}

}
