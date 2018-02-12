/* Простая программа обработки списка контактов,
в которой используется массив структур. */
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<Windows.h>
#define MAX 100
using namespace std;
// !!! Неправильная реализация, необходимо использовать динамические массивы
struct addr {
    char name[30];
    char surname[40];
    char city[20];
    char email[30];
    unsigned long int tel;//!!!номер тоже надо через строку, экспериментировал)
} addr_list[MAX];

void init_list(), enter();
void del(), list();
void load(), save();
void contact();
void sorting();
void sorting2();
void sorting3();
void search();
int menu_sort();
int sort();
int menu_select(), find_free();

int main()
{
    for (;;)
    {
        switch (menu_select())
        {
        case 1: enter();
            break;
        case 2: contact();
            break;
        case 3: del();
            break;
        case 4: list();
            break;
        case 5: save();
            break;
        case 6: load();
            break;
        case 7: sort();
            break;
        case 8: search();
            break;
        case 9: exit(0);
        }
    }
    return 0;
}

/* Инициализация списка. */
void init_list()
{
    for (int t = 0; t<MAX; ++t)
        addr_list[t].name[0] = '\0';
}

/* Получения значения, выбранного  в меню. */
int menu_select()
{
    char s[80];
    int c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 3);
    cout << "\n1. Add contact\n";
    cout << "2. Show a certain contact (by sequence number)\n";
    cout << "3. Delete contact\n";
    cout << "4. View all contacts to choose one\n";
    cout << "5. Save file\n";
    cout << "6. Load file\n";
    cout << "7. Sorting\n";
    cout << "8. Search\n";
    cout << "9. Exit\n";

    do {
        SetConsoleTextAttribute(h, 7);
        cout << "\nEnter the number from list:\n ";
        gets(s);
        c = atoi(s);
    } while (c<0 || c>9);
    return c;
}

/* Получения значения, выбранного  в меню сортировки. */
int menu_sort()
{
    char s[80];
    int c;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, 5);
    cout << "\n1. Name\n";
    cout << "2. Surname\n";
    cout << "3. City\n";
    cout << "4. Main menu\n";
    cout << "5. Exit\n";

    do {
        SetConsoleTextAttribute(h, 7);
        cout << "\nSelect sort or exit to the main menu:\n ";
        gets(s);
        c = atoi(s);
    } while (c<0 || c>5);
    return c;
}

int sort()
{
    for (;;)
    {
        switch (menu_sort())
        {
        case 1: sorting();
            break;
        case 2: sorting2();
            break;
        case 3: sorting3();
            break;
        case 4: main();//этот пункт тоже не понравился преподавателю, тут рекурсия получается )))
            break;
        case 5: exit(0);
        }
    }
    return 0;
}

/* Добавление адреса в список. */
void enter()
{
    int slot;
    char s[80];

    slot = find_free();

    if (slot == -1) {
        cout << "\nList is full";
        return;
    }

    cout << "Enter name: ";
    gets(addr_list[slot].name);

    cout << "Enter surname: ";
    gets(addr_list[slot].surname);

    cout << "Enter sity: ";
    gets(addr_list[slot].city);

    cout << "Enter e-mail: ";
    gets(addr_list[slot].email);

    cout << "Enter tel: ";
    gets(s);
    addr_list[slot].tel = strtoul(s, '\0', 10);
}

/*Вывод выбранного контакта на экран*/
void contact()
{
    int t;
    char s[80];

    cout << "view contact # : ";
    gets(s);
    t = atoi(s);
    cout << "contact # " << t << ":" << endl;
    cout << addr_list[t].name << endl;
    cout << addr_list[t].surname << endl;
    cout << addr_list[t].city << endl;
    cout << addr_list[t].email << endl;
    cout << addr_list[t].tel << endl;
}

/* Поиск свободной структуры. */
int find_free()
{
    int t;
    for (t = 0; addr_list[t].name[0] && t<MAX; ++t);
    if (t == MAX)
        return -1; /* свободных структур нет */
    return t;
}

/* Удаление адреса. */
void del()
{
    int slot;
    char s[80];

    cout << "Delete contact # : ";
    gets(s);
    slot = atoi(s);

    if (slot >= 0 && slot < MAX)
        addr_list[slot].name[0] = '\0';
}

/* Вывод списка на экран c возможностью просмотра данных контакта по номеру по порядку. */
void list()
{
    for (int t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
        cout << "contact # " << t << ":" << endl;
        cout << addr_list[t].name << endl;
        cout << addr_list[t].surname << endl;
        cout << addr_list[t].city << endl;
        cout << addr_list[t].email << endl;
        cout << addr_list[t].tel << endl;
        cout << endl;
    }
    contact();
}

/*Сортировка по имени*/
void sorting()
{
    int t;
    for (t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
    }

    for (int j = t - 1; j>0; j--)
    for (int i = 0; i < j; i++)
    {
        int k = strcmp(addr_list[i].name, addr_list[i + 1].name);
        if (k == 1)
            swap(addr_list[i], addr_list[i + 1]);
    }

    for (int t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
        cout << "contact # " << t << ":" << endl;
        cout << addr_list[t].name << endl;
        cout << addr_list[t].surname << endl;
        cout << addr_list[t].city << endl;
        cout << addr_list[t].email << endl;
        cout << addr_list[t].tel << endl;
        cout << endl;
    }
}

/*Сортировка по фамилии*/
void sorting2()
{
    int t;
    for (t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
    }

    for (int j = t - 1; j>0; j--)
    for (int i = 0; i < j; i++)
    {
        int k = strcmp(addr_list[i].surname, addr_list[i + 1].surname);
        if (k == 1)
            swap(addr_list[i], addr_list[i + 1]);
    }

    for (int t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
        cout << "contact # " << t << ":" << endl;
        cout << addr_list[t].surname << endl;
        cout << addr_list[t].name << endl;
        cout << addr_list[t].city << endl;
        cout << addr_list[t].email << endl;
        cout << addr_list[t].tel << endl;
        cout << endl;
    }
}

/*Сортировка по городу*/
void sorting3()
{
    int t;
    for (t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
    }

    for (int j = t - 1; j>0; j--)
    for (int i = 0; i < j; i++)
    {
        int k = strcmp(addr_list[i].city, addr_list[i + 1].city);
        if (k == 1)
            swap(addr_list[i], addr_list[i + 1]);
    }

    for (int t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
        cout << "contact # " << t << ":" << endl;
        cout << addr_list[t].city << endl;
        cout << addr_list[t].surname << endl;
        cout << addr_list[t].name << endl;
        cout << addr_list[t].email << endl;
        cout << addr_list[t].tel << endl;
        cout << endl;
    }
}

void search()
{
    char search[30];
    cout << "Enter name for search: ";
    gets(search);

    int t;
    for (t = 0; t<MAX; ++t)
    {
        if (addr_list[t].name[0] == '\0')
            break;
    }
    int k;
    for (int i = 0; i < t; i++)
    {
        char *istr;
        istr = strstr(addr_list[i].name, search);
        if (istr == NULL);
        //			cout << "No matches";
        else
            k = i;
    }

    cout << "contact # " << k << ":" << endl;
    cout << addr_list[k].name << endl;
    cout << addr_list[k].surname << endl;
    cout << addr_list[k].city << endl;
    cout << addr_list[k].email << endl;
    cout << addr_list[k].tel << endl;
    cout << endl;
}

/* Сохранение списка. */
void save()
{
    FILE  *fp;

    if ((fp = fopen("contact_list", "wb")) == NULL)
    {
        cout << "Error opening file.\n";
        return;
    }

    for (int i = 0; i<MAX; i++)
    if (*addr_list[i].name)
    if (fwrite(&addr_list[i], sizeof(struct addr), 1, fp) != 1)
        cout << "Error writing file.\n";

    fclose(fp);
}

/* Загрузить файл. */
void load()
{
    FILE  *fp;

    if ((fp = fopen("contact_list", "rb")) == NULL)
    {
        cout << "Error opening file.\n";
        return;
    }

    init_list();
    for (int i = 0; i<MAX; i++)
    if (fread(&addr_list[i], sizeof(struct addr), 1, fp) != 1)
    {
        if (feof(fp)) break;
        cout << "Error read file.\n";
    }

    fclose(fp);
}