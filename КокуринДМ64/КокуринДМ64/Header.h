#pragma once
#include <string.h>
#include <string>
#include <vector>
// supported function: to copy one to another
void copy(char* from, char* dest);
// struct to store data
struct data_struct
{
	char name[25];
	char country[25];
	int amount;
	int price;
	data_struct() { memset(name, (char)0, 24); memset(country, char(0), 24); amount = 0; price = 0; };
	data_struct(char n[], char c[], int a, int p)
	{
		copy(n, name); copy(c, country); amount = a; price = p;
	}
};
// the function to write struct at the end of file
void mywrite(const char* path);
// the function to read current line
data_struct readline(FILE* f, const char* path);
// the function to read the whole file
void readall(const char* path);
// the function to get line by number
void readnumber(const char* path);
// the function to get the size of file
int size_of_file(const char* path);
// функция изменения полей файла
void change(const char* path);
//  the function to delete marks data
void del(std::vector<int> &list, const char* path);
// the function to create marks to delete
void metka(std::vector<int> &marked);