#include "Header.h"
#include <iomanip>
#include <string>
using namespace std;
// support function: to copy one to another
void copy(char* from, char* dest)
{
	//char* f = (char*)from;
	memset(dest, (char)0, 24);
	for (int i = 0; i < 25 && from[i] != '\0'; i++)
		dest[i] = from[i];
}
// the function to write struct at the end of file
void mywrite(const char* path) // запись в конец файла
{
	ofstream fout;
	fout.open(path, ios_base::binary | ios_base::app);
	data_struct object;
	cout << "Input name of item" << endl;
	cin >> object.name;
	cout << "Input the country" << endl;
	cin >> object.country;
	cout << "Input the price" << endl;
	cin >> object.price;
	cout << "Input amount of item" << endl;
	cin >> object.amount;
	fout.write((char*)&object, sizeof(data_struct));
	fout.close();
}
// the function to get the size of file
int size_of_file(const char* path)
{
	ifstream in(path, std::ifstream::ate | ios::binary);
	return in.tellg();
}
// the function to print the struct
void print(data_struct a, int i)
{
	cout << left << "| " << setw(3) << i  << "| " << setw(24) << a.name << "| " << setw(25) << a.country << "| " << setw(7) << a.price << "| " << setw(7) << a.amount << "|" << endl;
}
// the function to read the whole file
void readall(const char* path)
{
	cout << "\nThe whole list:" << endl;
	cout << "| N. | Name of item            | Name of country          | Price  | Amount |" << endl;
	cout << "|----|-------------------------|--------------------------|--------|--------|" << endl;
	ifstream fin;
	fin.open(path, ios_base::binary);
	data_struct current;
	int full_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	for (int i = 0; i < full_size; i += struct_size)
		readnumber(path, i / struct_size + 1);
	fin.close();
	cout << "|----|-------------------------|--------------------------|--------|--------|\n" << endl;
}
// the function to get line by number
data_struct readnumber(const char* path, int num)
{
	ifstream fin;
	fin.open(path, ios_base::binary);
	data_struct current;
	int full_size = size_of_file(path);
	int srtuct_size = sizeof(data_struct);
	fin.seekg(srtuct_size * (num-1), ios::beg);
	fin.read((char*)&current, srtuct_size);
	print(current,num);
	fin.close();
	return current;
}
// support function: to check consistence
bool myfind(vector<int> list, int a)
{
	for (int b : list)
		if (a == b)
			return true;
	return false;
}
// the function to create marks to delete
void metka(vector<int>& marked)
{
	cout << "Input line's number for delete \n";
	cout << "Attention! Double input means clearing from mark\n";
	cout << "At the end input \"-1\"" << endl;
	while (true)
	{
		int a;
		cin >> a;
		if (a == -1)
		{
			cout << "Your list for delete:\n";
			for (int b : marked)
				cout << b << " ";
			cout << endl;
			break;
		}
		if (myfind(marked, a))
		{
			cout << a << " line is free" << endl;
			marked.erase(std::find(marked.begin(), marked.end(), a));
		}
		else
		{
			marked.push_back(a);
			cout << "New line for delete: " << a << endl;
		}
	}
}
//  the function to delete marks data
void del(vector<int>& list, const char* path)
{
	vector<data_struct> reserve;
	ifstream fin;
	fin.open(path, ios_base::binary);
	data_struct current;
	int full_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	for (int i = 0; i < full_size; i += struct_size)
	{
		if (myfind(list, i/struct_size + 1))
			continue;
		fin.read((char*)&current, struct_size);
		reserve.push_back(current);
	}
	fin.close();

	ofstream fout;
	fout.open(path, ios_base::binary | ios_base::trunc);
	for (data_struct object : reserve)
		fout.write((char*)&object, sizeof(data_struct));
	fout.close();
	list.clear();
}

bool equal(char* one, char* two)
{
	for (int i = 0; i < 24; i++)
		if (one[i] != two[i])
			return false;
	return true;
}
// функция изменения полей файла
void change(const char* path)
{
	cout << "Input country" << endl;
	char find_country[25];
	memset(find_country, (char)0, 24);
	cin >> find_country;
	cout << "Input item" << endl;
	char find_tovar[25];
	memset(find_tovar, (char)0, 24);
	cin >> find_tovar;
	int full_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	data_struct current; int num = 0;
	ifstream fin;
	fin.open(path, ios_base::binary);
	bool flag = false;
	for (int i = 0; i < full_size; i += struct_size)
	{
		fin.read((char*)&current, struct_size);
		if (equal(current.country, find_country) && equal(current.name, find_tovar))
		{
			num = i / struct_size;
			cout << "We found this line: " << endl;
			print(current, num + 1);
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "We haven't found" << endl;
		return;
	}
	cout << "Input name of item" << endl;
	cin >> current.name;
	cout << "Input the country" << endl;
	cin >> current.country;
	cout << "Input the price" << endl;
	cin >> current.price;
	cout << "Input amount of item" << endl;
	cin >> current.amount;
	fstream fout;
	fout.open(path, ios_base::binary | ios_base::in | ios_base::out);
	fout.seekp(sizeof(data_struct) * num, ios::beg);
	fout.write((char*)&current, sizeof(data_struct));
	fout.close();
}
// the support function to check two strings

// the support struct to prepare data
struct total
{
	char name[25];
	vector<string> country;
	int total_value;
	int total_amount;
	total(char n[], char c[], int a, int p)
	{
		copy(n, name); country.push_back(c); total_amount = a; total_value = p;
	}
};
// the support function to print result
void result_print(vector<total>& goods)
{
	int result_max = 0;
	string result_item = "";
	cout << "\nReport:\n";
	for (total c : goods)
	{
		cout << "Information about " << c.name << "\nExport to: ";
		for (string b : c.country)
			cout << b << " ";
		cout << "\n Total amount: " << c.total_amount;
		cout << "\n Total value: " << c.total_value << "\n" << endl;
		if (c.total_value > result_max)
		{
			result_max = c.total_value;
			result_item = c.name;
		}
	}
	cout << "\nThe best item is: " << result_item << ". Total value: " << result_max << "\n" << endl;
}
// the support function to prepare data
void prepare_data(vector<total>& goods, const char* path)
{
	int full_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	for (int i = 0; i < full_size; i += struct_size)
	{
		data_struct current = readnumber(path, i / struct_size + 1);
		bool flag_name = false;
		for (total& a : goods)
		{
			if (equal(current.name, a.name))
			{
				flag_name = true;
				bool flag_country = false;
				for (string b : a.country)
					if (equal(current.country, &b[0]))
						flag_country = true;
				a.total_amount += current.amount;
				if (!flag_country)
					a.country.push_back(current.country);
				a.total_value += (current.amount * current.price);

			}
		}
		if (!flag_name)
		{
			goods.push_back(total(current.name, current.country, current.amount, current.price * current.amount));
		}
	}
}
// the function to solve the main task
void result(const char* path)
{
	vector<total> goods;
	prepare_data(goods, path);
	result_print(goods);
}
int myfind_s(vector<string> list, string a)
{
	for (int i = 0; i<list.capacity();i++)
		if (list[i] == a)
			return i;
	return -1;
}
void zachita(const char* path)
{
	int full_size = size_of_file(path);
	int struct_size = sizeof(data_struct);
	vector<string> country;
	vector<int> tovar;
	for (int i = 0; i < full_size; i += struct_size)
	{
		data_struct current = readnumber(path, i / struct_size + 1);
		int index = myfind_s(country, current.country);
		if (index == -1)
		{
			country.push_back(current.country);
			tovar.push_back(current.amount);
		}
		else
			tovar[index] += current.amount;
	}
	int max_amount = 0;
	int max_index = -1;
	for (int i = 0; i<tovar.capacity();i++)
	{
		if (tovar[i] > max_amount)
		{
			max_amount = tovar[i];
			max_index = i;
		}
	}
	cout << "\nAnswer: " << country[max_index] << ". Amount of goods: " << max_amount << "\n\n" << endl;
}