#define _CRT_SECURE_NO_WARNINGS

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

ofstream fileout;
ifstream filein;
char files[] = "info.txt";

int getValueint(int q, int w)
{
	while (true) // цикл продолжается до тех пор, пока пользователь не введет корректное значение
	{
		int a;
		cin >> a;
		cin.ignore(cin.rdbuf()->in_avail());
		if (cin.fail()) { // если предыдущее извлечение оказалось неудачным,
			cin.clear(); // то возвращаем cin в 'обычный' режим работы
			cin.ignore(cin.rdbuf()->in_avail()); // и удаляем значения предыдущего ввода из входного буфера
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
		}
		else if (a >= q and a <= w) // если всё хорошо, то возвращаем a
			return a;
		else
			cout << "Вы ввели некорректное число! Попробуйте еще раз ";
	}
}
class clinic;
class fio
{
	char* surname; 	// указатели на строки с фамилией,
	char* name;	// именем и отчеством
	char* patronymic;

public:
	fio(int a)
	{
		a = 1;
	}
	fio()
	{
		surname = new char[60];
		name = new char[60];
		patronymic = new char[60];
	}
	~fio()
	{
		delete[] surname;
		delete[] name;
		delete[] patronymic;
	}
	friend class clinic;
	friend void search_fio(clinic* arr);
};

class clinic
{
	int speciality;  // специальность(1-терапевт, 2-кардиолог, 3- стоматолог)
	int qualification; //квалификация (0-высшая, 1- первая, 2- вторая)
	fio fam_name_patronymic;
public:
	static int count;        // счетчик существующих объектов класса
	friend void search_fio(clinic* arr);

	void add_new(clinic* arr)
	{
		cout << "Введите фамилию врача: " << ' ';
		cin >> arr[count].fam_name_patronymic.surname;
		cout << "Введите имя врача: " << ' ';
		cin >> arr[count].fam_name_patronymic.name;
		cout << "Введите отчество врача: " << ' ';
		cin >> arr[count].fam_name_patronymic.patronymic;
		cout << "Введите номер специальности(от 1 до 3): " << ' ';
		arr[count].speciality = getValueint(1, 3);
		cout << "Введите номер квалификации(от 0 до 2): " << ' ';
		arr[count].qualification = getValueint(0, 2);

		count++;
	}

	void print_header()
	{
		cout << setw(22) << "ФИО" << setw(40) << "Специальность    " << setw(22) << " Квалификация" << endl;
		cout << "_________________________________________________________________________________________" << endl;
	}

	void print_information(clinic* arr, int i)
	{
		int probel = 40;
		int twenty = 20;

		cout << setw(13) << arr[i].fam_name_patronymic.surname << setw(13) << arr[i].fam_name_patronymic.name << setw(13) << arr[i].fam_name_patronymic.patronymic;

		switch (arr[i].speciality)
		{
		case 1:
			cout << setw(18) << "Терапевт";
			break;
		case 2:
			cout << setw(18) <<  "Кардиолог";
			break;
		case 3:
			cout << setw(18) << "Стоматолог";
			break;
		}
		cout << setw(twenty);

		switch (arr[i].qualification)
		{
		case 0:
			cout << setw(26) << "Высшая" << endl;
			break;
		case 1:
			cout << setw(26) << "Первая" << endl;
			break;
		case 2:
			cout << setw(26) << "Вторая" << endl;
			break;
		}
	}

	void print_table(clinic* arr)
	{
		for (int i = 0; i < count; i++)
		{
			print_information(arr, i);
		}
	}

	void search_speciality_and_qualification(clinic* arr)
	{
		int num_speciality;
		int num_qualification;
		int exit_1 = 0;

		if (count == 0)
		{
			cout << "В базе поликлинники нет врачей" << endl;
		}
		else
		{
			cout << "Введите цифру в соответствии со специальностью врача (1-терапевт, 2-кардиолог, 3- стоматолог): ";
			num_speciality = getValueint(1, 3);
			cout << "Введите цифру в соответствии с квалификацией врача (0-высшая, 1- первая, 2- вторая): ";
			num_qualification = getValueint(0, 2);
		}


		for (int i = 0; i < count; i++)
		{
			if (arr[i].speciality == num_speciality && arr[i].qualification == num_qualification)
			{
				if (exit_1 == 0)
				{
					print_header();
					exit_1++;
				}
				print_information(arr, i);
			}
		}
		if (exit_1 == 0)
		{
			cout << "В базе полликлинники нет таких врачей";
		}
	}

	void sort_alphabet(clinic* arr)
	{


		char change_1[100];
		int change_2;
		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count - 1; j++)
			{
				if (strcmp(arr[j].fam_name_patronymic.surname, arr[j + 1].fam_name_patronymic.surname) > 0)
				{
					strcpy(change_1, arr[j].fam_name_patronymic.surname);
					strcpy(arr[j].fam_name_patronymic.surname, arr[j + 1].fam_name_patronymic.surname);
					strcpy(arr[j + 1].fam_name_patronymic.surname, change_1);

					strcpy(change_1, arr[j].fam_name_patronymic.name);
					strcpy(arr[j].fam_name_patronymic.name, arr[j + 1].fam_name_patronymic.name);
					strcpy(arr[j + 1].fam_name_patronymic.name, change_1);

					strcpy(change_1, arr[j].fam_name_patronymic.patronymic);
					strcpy(arr[j].fam_name_patronymic.patronymic, arr[j + 1].fam_name_patronymic.patronymic);
					strcpy(arr[j + 1].fam_name_patronymic.patronymic, change_1);
					change_2 = arr[j].speciality;
					arr[j].speciality = arr[j + 1].speciality;
					arr[j + 1].speciality = change_2;

					change_2 = arr[j].qualification;
					arr[j].qualification = arr[j + 1].qualification;
					arr[j + 1].qualification = change_2;
				}
				if (strcmp(arr[j].fam_name_patronymic.surname, arr[j + 1].fam_name_patronymic.surname) == 0 and strcmp(arr[j].fam_name_patronymic.name, arr[j + 1].fam_name_patronymic.name) > 0)
				{
					strcpy(change_1, arr[j].fam_name_patronymic.surname);
					strcpy(arr[j].fam_name_patronymic.surname, arr[j + 1].fam_name_patronymic.surname);
					strcpy(arr[j + 1].fam_name_patronymic.surname, change_1);

					strcpy(change_1, arr[j].fam_name_patronymic.name);
					strcpy(arr[j].fam_name_patronymic.name, arr[j + 1].fam_name_patronymic.name);
					strcpy(arr[j + 1].fam_name_patronymic.name, change_1);

					strcpy(change_1, arr[j].fam_name_patronymic.patronymic);
					strcpy(arr[j].fam_name_patronymic.patronymic, arr[j + 1].fam_name_patronymic.patronymic);
					strcpy(arr[j + 1].fam_name_patronymic.patronymic, change_1);

					change_2 = arr[j].speciality;
					arr[j].speciality = arr[j + 1].speciality;
					arr[j + 1].speciality = change_2;

					change_2 = arr[j].qualification;
					arr[j].qualification = arr[j + 1].qualification;
					arr[j + 1].qualification = change_2;
				}
			}
		}
	}

	static void read(clinic* arr)
	{
		filein.open(files);
		if (!filein.is_open())
		{
			cout << "Ошибка открытия файл" << endl;
		}
		else
		{
			filein >> (clinic::count);

			for (int i = 0; i < (clinic::count); i++)
			{
				char* surname_1 = new char[100];
				filein.getline(surname_1, 100);
				filein.getline(surname_1, 100);
				arr[i].fam_name_patronymic.surname = surname_1;

				char* name_1 = new char[100];
				filein.getline(name_1, 100);
				arr[i].fam_name_patronymic.name = name_1;

				char* patronymic_1 = new char[100];
				filein.getline(patronymic_1, 100);
				arr[i].fam_name_patronymic.patronymic = patronymic_1;

				filein >> arr[i].speciality;
				filein >> arr[i].qualification;
			}
		}
		filein.close();
	}

	static void save(clinic* arr)
	{
		fileout.open(files);
		if (!fileout.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			fileout << (clinic::count) << endl;

			for (int i = 0; i < (clinic::count); i++)
			{
				fileout << arr[i].fam_name_patronymic.surname << endl;
				fileout << arr[i].fam_name_patronymic.name << endl;
				fileout << arr[i].fam_name_patronymic.patronymic << endl;
				fileout << arr[i].speciality << endl;
				fileout << arr[i].qualification << endl;
			}
		}
		fileout.close();
	}
};

int clinic::count = 0;

	int main()
	{
		setlocale(LC_ALL, "Russian");
		clinic* array = new clinic[100];
		clinic::read(array);
		while (true)
		{
			int menu;
			cout << "Выберите пункт меню: " << endl;
			cout << "Добавить нового врача .......................................... 1" << endl;
			cout << "Распечатка данных в табличном виде ............................. 2" << endl;
			cout << "Поиск врача по ФИО ............................................. 3" << endl;
			cout << "Фильтр по квалификации и специальности ......................... 4" << endl;
			cout << "Сортировка врачей по алфавиту .................................. 5" << endl;
			cout << "Выход из программы ............................................. 6" << endl;

			cin >> menu;
			if (menu == 6)
			{
				cout << "Вы вышли из программы";
				break;
			}
			switch (menu)
			{
			case 1:
			{
				array->add_new(array);
				break;
			}
			case 2:
			{
				if (clinic::count == 0)
				{
					cout << "В базе поликлинники нет врачей" << endl;
				}
				else
				{
					array->print_header();
					array->print_table(array);
				}
				break;
			}
			case 3:
			{
				search_fio(array);
				break;
			}
			case 4:
			{
				array->search_speciality_and_qualification(array);
				cout << endl;
				break;
			}
			case 5:
			{
				if (clinic::count == 0)
				{
					cout << "В базе поликлинники нет врачей" << endl;
					break;
				}
				else
				{
					array->sort_alphabet(array);
					array->print_header();
					array->print_table(array);
					break;
				}
			}
			default:
			{
				cout << "Попробуйте снова: " << endl;
				break;
			}
			}
		}
		filein.close();
		clinic::save(array);

		delete[] array;

	}

	void search_fio(clinic* arr)
	{
		char* surname_1 = new char[100];
		cout << "Введите фамилию врача: " << ' ';
		cin.getline(surname_1, 100); cin.getline(surname_1, 100);
		char* name_1 = new char[100];
		cout << "Введите имя врача: " << ' ';
		cin.getline(name_1, 100); 
		char* patronymic_1 = new char[100];
		cout << "Введите отчество врача: " << ' ';
		cin.getline(patronymic_1, 100); 

		int exit = 0;

		for (int i = 0; i < clinic::count; i++)
		{
			if (strcmp(surname_1, arr[i].fam_name_patronymic.surname) == 0 and strcmp(name_1, arr[i].fam_name_patronymic.name) == 0 and strcmp(patronymic_1, arr[i].fam_name_patronymic.patronymic) == 0)
			{
				if (exit == 0)
				{
					arr->print_header();
					exit++;
				}
				arr->print_information(arr, i);
			}
		}
		if (exit == 0)
		{
			cout << "Врача с таким ФИО нет в базе данных!" << endl;
		}
		delete[] surname_1; delete[] name_1; delete[] patronymic_1;
	}


