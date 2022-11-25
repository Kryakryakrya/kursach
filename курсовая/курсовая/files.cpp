#include <fstream>
#include <stdio.h>
#include <string>
struct info
{
	info(string n, string s, int c, int p)
	{
		name = n; country = s; count = c; price = p;
	}
	info()
	{
		name = ""; country = ""; count = 0; price = 0;
	}
	string name;
	string country;
	int count;
	int price;
};
using namespace std;
const char* way = "C:\\Users\\Good guy\\Desktop\\try.bim";
void writeline(info &forwrite) // запись информации в конец файла
{
	FILE *f = fopen(way, "ab");
	fwrite(&forwrite, sizeof(info), 1, f);
}
info viewfull()
{

}
info readline(int line)
{
	FILE* f = fopen(way, "rb");
	fseek(f, (line-1) * sizeof(info), SEEK_SET);
	info current_struct;
	fread(&current_struct, sizeof(info), 1, f);
	return current_struct;
}