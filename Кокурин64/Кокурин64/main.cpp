// Кокурин64.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <vector>
#include <iostream>
#include "вводвывод.h"
#include <Windows.h>
int main()
{
    setlocale(LC_ALL, "Russian");

    const char* myfile = "myfile.bin";







   /* ofstream out(myfile, ios_base::binary);

    Definitions::data_struct b("Название", "Страна", 15, 40);
    Definitions::data_struct c("noНазвание", "Страна", 15, 40);
    Definitions::data_struct d("yesНазвание", "Страна", 15, 40);
    out << b.name << " " << b.contry << " " << b.amount << " " << b.price << endl;
    out << c.name << " " << c.contry << " " << c.amount << " " << c.price << endl;
    out << d.name << " " << d.contry << " " << d.amount << " " << d.price << endl;
    out.close();*/











    //int size_file = Definitions::size_of_file(myfile);
    //int size_struct = sizeof(Definitions::data_struct);/*
    //Definitions::data_struct b("Название", "Страна", 15, 40);
    //Definitions::data_struct c("noНазвание", "Страна", 15, 40);
    //Definitions::data_struct d("yesНазвание", "Страна", 15, 40);
    //Definitions::mywrite(b, myfile);
    //Definitions::mywrite(c, myfile);
    //Definitions::mywrite(d, myfile);*/
    //vector<Definitions::data_struct> a;
    //FILE* f;
    //fopen_s(&f, myfile, "rb");
    //if (f == NULL)
    //    cout << "ERROR!!!";
    //else
    //    for (int i = 0; i < size_file; i += size_struct, fseek(f, size_struct, SEEK_SET))
    //    {
    //        a.push_back(Definitions::readline(f, myfile));
    //    }
    //fclose(f);
    //for (Definitions::data_struct b : a)
    //    cout << b.name << endl;
    //int total_size = GetFileSize(myfile);
    /*Definitions::data_struct obj("Мороженное", "ЮАР", 15, 40);
    Definitions::mywrite(obj,myfile);
    ifstream in;
    in.open(myfile, ios::binary);
    string line;
    while (getline(in, line))
        cout << line;*/
}