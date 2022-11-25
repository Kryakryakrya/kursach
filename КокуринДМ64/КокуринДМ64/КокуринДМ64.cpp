
#include <iostream>
#include <string>
#include <vector>
#include "Header.h"
using namespace std;
vector<int> marked;
int main()
{
	setlocale(LC_ALL, "Russian");
	//cout << "Добро пожаловать в бухгалтерскую систему\n";
	cout << "Welcome!\n";
	while (true)
	{
		cout << "Select 1 to add the new data\n";
		cout << "Select 2 to show all\n";
		cout << "Select 3 to show the data by the number\n";
		cout << "Select 4 to choise data for delete\n";
		cout << "Select 5 to clear file from selected data\n";
		cout << "Select 6 to edit data\n";
		cout << "Select 7 to make an result\n";
		cout << "Select -1 to exit\n";

		/*cout << "Выберите 1 для добавления новой записи\n";
		cout << "Выберите 2 для просмотра всего файла\n";
		cout << "Выберите 3 для просмотра записи по ее номеру\n";
		cout << "Выберите 4 для указания записей на удаление\n";
		cout << "Выберите 5 для удаления указанных записей\n";
		cout << "Выберите 6 для редактирования записей\n";
		cout << "Выберите 7 для получения конечного решения\n";
		cout << "Выберите -1 для выхода\n";*/
		int a;
		cin >> a;

		if(!cin.good())
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.clear();
		if (a == 1)
		{
			mywrite(path);
			//break;
		}
		else if (a == 2)
		{
			readall(path);
			//break;
		}
		else if (a == 3)
		{
			readnumber(path);
			//break;
		}
		else if (a == 4)
		{
			metka(marked);
			//break;
		}
		else if (a == 5)
		{
			del(marked, path);
			//break;
		}
		else if (a == 6)
			;
		else if (a == 7)
			;
		else
			return 0;
	}
}