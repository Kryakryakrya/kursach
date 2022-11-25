#include <limits>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Header.h"
#undef max
using namespace std;
// supported function: to copy one to another
void copy(char* from, char* dest)
{
	//char* f = (char*)from;
	memset(dest, (char)0, 24);
	for (int i = 0; i < 25 && from[i]!='\0'; i++)
		dest[i] = from[i];
}
// the function to read current line
data_struct readline(FILE* f, const char* path)
{
	data_struct object;
	fread(&object, sizeof(data_struct), 1, f);
	return object;
}
// the function to read the whole file
void readall(const char* path)
{
	FILE* f;
	fopen_s(&f, path, "rb");
	int total_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	data_struct a;
	int current_size = 0;
	for (int i = 0; current_size < total_size; i += 1, current_size += struct_size, fseek(f, current_size, SEEK_SET))
	{
		a = readline(f, path);
		cout << a.name << " " << a.country << " " << a.amount << " " << a.price << endl;
	}
	fclose(f);
}
// the function to get line by number
void readnumber(const char* path)
{
	cout << "Какую строку вы желаете считать?\n";
	int number;
	cin >> number;
	FILE* f;
	fopen_s(&f, path, "rb");
	int total_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	data_struct a;
	fseek(f, struct_size*number, SEEK_SET);
	a = readline(f, path);
	cout << a.name << " " << a.country << " " << a.amount << " " << a.price << endl;
	fclose(f);
}
// the function to get the size of file
int size_of_file(const char* path)
{
	ifstream in(path, std::ifstream::ate | ios::binary);
	return in.tellg();
} 
// support function: to check consistence
bool myfind(vector<int> list, int a)
{
	for (int b : list)
		if (a == b)
			return true;
	return false;
}
// the function to delete marks data
void del(vector<int>& list, const char* path)
{
	vector<data_struct> reserve;
	int total_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	FILE* f;
	fopen_s(&f, path, "rb");
	for (int i = 0; i < total_size / struct_size; i++, fseek(f, struct_size, SEEK_CUR))
	{
		if (myfind(list, i))
			continue;
		reserve.push_back(readline(f, path));
	}
	fclose(f);
	fopen_s(&f, path, "wb");
	for (data_struct object:reserve)
		fwrite(&object, sizeof(data_struct), 1, f);
	fclose(f);
}
// the function to create marks to delete
void metka(vector<int>& marked)
{
	/*cout << "Введите номер записи для удаления. \n";
	cout << "Ввод номеров записей, подготовленных к удалению, предотвращает их от удаления\n";
	cout << "В конце введите \"-1\"\n";*/
	while (true)
	{
		int a;
		cin >> a;
		if (a == -1)
			break;
		if (myfind(marked, a))
			marked.erase(std::find(marked.begin(), marked.end(), a));
		else
			marked.push_back(a);
	}
}
// функция изменения полей файла
//void change(const char* path)
//{
//	cout << "Введите номер записи для изменения:\n";
//	int number;
//	cin >> number;
//	cout << "Введите имя поля для изменения:\n1 - name, 2 - country, 3 - amount, 4 - price, -1 - выход\n";
//	int field;
//	cin >> field;
//	switch (field)
//	{
//	case(1):
//		string temp;
//		getline(cin, temp);
//
//	}
//}
