#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Definitions
{
public:
	static struct data_struct // структура для хранения информации в файле
	{
		char name[25];
		char country[25];
		int amount;
		int price;
		data_struct(char n[25], char c[25], int a, int p)
		{
			copy(&name,n);
			copy(&country, c);
			amount = a;
			price = p;
		}
		data_struct() { }
	};
	static void copy(char* from, char* dest)
	{
		for (int i = 0; i < 25; i++)
			dest[i] = from[i];
	}
	static void mywrite(data_struct object, const char* path) // запись в конец файла
	{
		//ofstream fout(myfile, ios_base::binary | ios_base::app);
		//fout.wr
		FILE* f;

		fopen_s(&f, path, "ab");
		fwrite(&object, sizeof(data_struct), 1, f);
		fclose(f);
	}
	static data_struct readline(FILE* f, const char* path)
	{
		data_struct object;
		fread(&object, sizeof(data_struct), 1, f);
		return object;
	}
	static int size_of_file(const char* path)
	{
		ifstream in(path, std::ifstream::ate | ios::binary);
		return in.tellg();
	}
};