#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>   
#include <filesystem> 
#include <stdio.h>
#include<Windows.h>
const int MAXSIZE=1000;
using namespace std;


struct MusicCard
{
	char MusicName [100];
	char AuthorName[100];
	char DATE[12];
	char TextMusic[1000];
};
int main();
int get_line_size(char str[], int max)// высчитвание длену строки
{
	int cymbol;
	int lenght;
	for (lenght = 0; (cymbol = getchar()) != EOF && cymbol != '\n' && lenght < max - 1; lenght++)
	{
		str[lenght] = cymbol;
	}
	str[lenght] = '\n';
	return lenght;
}

void ListMusic(MusicCard* List)
{
	*List = {};
	int N = 0;
	char Buf_Str[MAXSIZE];
	char Buf_Str2[MAXSIZE];
	int lengt;
	//get_line_size(Buf_Str2, MAXSIZE);
	//M= (struct MusicCard*)realloc(M, (100) * sizeof(struct MusicCard));
	//if (M == nullptr)	exit(EXIT_SUCCESS);
	FILE* f;
	if ((f = fopen("text1.txt", "r")) == NULL)
	{
		printf("!!!Файл небыл открыт!!! \n");
	}

	int ch = '*';
	char Name[] = "Название песни : ";
	char Autor[] = "Автор : ";
	char Year[] = "Год издания : ";
	char* Post, * name, * autor, * year;
	int Index = 1;
	if (f != NULL)
	{
		for (int i = 0; i < Index; i++)
		{
			if (N >= 0)
			{
				fgets(Buf_Str2, MAXSIZE, f);
				lengt = strlen(Buf_Str2);
				Post = strchr(Buf_Str2, ch);

				name = strstr(Buf_Str2, Name);
				autor = strstr(Buf_Str2, Autor);
				year = strstr(Buf_Str2, Year);
				if ((Buf_Str2[lengt - 1] == '\n') && !(Buf_Str2[lengt - 1] = '\0'))
				{
					if (Post != NULL)
					{
						Index--;
						//cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
					}
					else
					{
						Index++;

						if (name != NULL)
						{
							strncpy(List[N].MusicName, Buf_Str2, lengt);

						}
						else if (autor != NULL)
						{
							strncpy(List[N].AuthorName, Buf_Str2, lengt);
						}
						else if (year != NULL)
						{
							strncpy(List[N].DATE, Buf_Str2, lengt);

						}
						else {

							

								strncpy(List[N].TextMusic, Buf_Str2, strlen(Buf_Str2));
							


						}
						//cout << "[" << Index << "] ";
					}
				}

				N++;
				//Index++;
			}
		}
		
		for (int i = 0; i < (sizeof(List) != NULL); i++)
		{
			cout << List[i].MusicName << endl;
			cout << List[i].AuthorName << endl;
			cout << List[i].DATE << endl;
			cout << List[i].TextMusic << endl;
			cout << "_____________________________________________________________________";
		}
		
		//int Index = 0;
		//do
		//{
		//	if (Index == 0)
		//	{
		//		fgets(Buf_Str2, MAXSIZE, f);
		//		strncpy((List[Index].MusicName), Buf_Str2, strlen(Buf_Str2));
		//		for (int i = 0; i < strlen(Buf_Str2); i++)
		//			cout << List[i].MusicName;N++;
		//	}
		//	if (Index == 1)
		//	{
		//		fgets(Buf_Str2, MAXSIZE, f);
		//		strncpy(List[Index].AuthorName, Buf_Str2, strlen(Buf_Str2));
		//		for (int i = 0; i < strlen(Buf_Str2); i++)
		//			cout << List[i].AuthorName;
		//	}
		//	if (Index == 2)
		//	{
		//		fgets(Buf_Str2, MAXSIZE, f);
		//		strncpy(List[Index].DATE, Buf_Str2, strlen(Buf_Str2));
		//		for (int i = 0; i < strlen(Buf_Str2); i++)
		//			cout << List[i].DATE;
		//	}
		//	//if (Index >= 3)
		//	//{
		//	//	//char str= "*************";
		//	//	if(strcmp(Buf_Str2,Buf_Str ) && f!=NULL)
		//	//	{
		//	//		for (int i = 0; i < strlen(Buf_Str2); i++)
		//	//		{
		//	//			fgets(Buf_Str2, MAXSIZE, f);
		//	//			strncpy(List->FileName, Buf_Str2, strlen(Buf_Str2));

		//	//		}
		//	//		for (int i = 0; i < strlen(Buf_Str2); i++)
		//	//			cout << i << List[i].FileName;
		//	//	} 
		//	//	//if ((Index = 4) == NULL)continue;
		//	//		//else cout << "[" << Index - 3 << "] ";
		//	//}
		//	//Index++;
		//	
		//	/*return Index;*/
		//} while (!feof(f));
	}

	fclose(f);
	_getwch();
}
void MusicText(MusicCard* List)
{
	system("cls");
	//M= (struct MusicCard*)realloc(M, (100) * sizeof(struct MusicCard));
	int al = sizeof(List->MusicName) / sizeof(List->MusicName);
	cout << "Выберите музыкальное произведение: " << endl;
	for (int i = 0; i < (sizeof(List->MusicName)!=NULL); i++) {
		cout <<"["<< al<<"] ";
		printf("%s \n", List->MusicName);
	}
	int a;
	cin >> a;
	if (a == al)
		{
			int count = 1;
			for (int i = 0; i < (sizeof(List->TextMusic) != NULL); i++) {
				cout << "[" << count << "] ";
				printf("%s \n",List->TextMusic);
			}
		}
	while ((a <= 0) || (a > al))
	{
		cout << "Неверное значение." << endl;
		if ((a <= 0) || (a > al)) { main();}
	}
	/*ifstream fin(List[a - 1].FileName, ios_base::in);
	int count = 0; string str;
	while (getline(fin, str)) {
		if (count >= 3) cout << str << endl;
		else count++;
	}*/
	_getwch();
};
void SaveMusic(MusicCard* List)
{};
void DeleteMusic(MusicCard* List)
{};
void FindAuthorMusic(MusicCard* List)
{};
void FindWordInMusic(MusicCard* List)
{};
void EditSong(MusicCard* List)
{};

//void main_menu() {
//	
//	system("cls"); 
//	int index = -1;
//	int a = 1;
//	MusicCard* List = new MusicCard[100];
//	ListMusic(List);
//
//	while (a != 0) {
//		system("cls");
//		cout << "Каталог текстов песен" << endl;
//		cout << "---------------------" << endl;
//		cout << "Выберите действие: " << endl;
//		cout << "[1] - Вывести текст песни." << endl;
//		cout << "[2] - Сохранить текст песни в файл." << endl;
//		cout << "[3] - Удалить песню из каталога." << endl;
//		cout << "[4] - Поиск песен одного автора." << endl;
//		cout << "[5] - Поиск слова в песнях." << endl;
//		cout << "[6] - Изменение текста песни." << endl;
//		cout << "[0] - Выход из программы." << endl;
//		cin >> a;
//		while ((a < 0) || (a > 6)) {
//			cout << "Неверное значение." << endl;
//			cin >> a;
//		}
//		//cin.get();
//		if (a == 1) MusicText(List, index);
//		else if (a == 2) SaveMusic(List);
//		else if (a == 3) DeleteMusic(List);
//		else if (a == 4) FindAuthorMusic(List);
//		else if (a == 5) FindWordInMusic(List);
//		else if (a == 6) EditSong(List);
//		else if (a == 0) break;
//	}
//	
//}


int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "1251");
	printf("Чтобы начать работу нажмите клавишу [ENTER]!!!\n");
	_getwch();

	MusicCard* List = new MusicCard[100];
	ListMusic(List);

	system("cls");
	//main_menu();
	while (true) {
		system("cls");
		printf("Каталог текстов песен\n");
		printf("---------------------\n");
		printf("Выберите действие: \n");
		printf("[1] - Вывести текст песни.\n");
		printf("[2] - Сохранить текст песни в файл.\n");
		printf("[3] - Удалить песню из каталога.\n");
		printf("[4] - Поиск песен одного автора.\n");
		printf("[5] - Поиск слова в песнях.\n");
		printf("[6] - Изменение текста песни.\n");
		printf("[0] - Выход из программы.\n");

		int choice;
		cin >> choice;

		switch (choice) {
			//ListMusic(List);
		case 1:  MusicText(List); break;
		case 2:  SaveMusic(List);break;
		case 3:  DeleteMusic(List); break;
		case 4:  FindAuthorMusic(List); break;
		case 5:  FindWordInMusic(List); break;
		case 6:  EditSong(List); break;
		case 0: exit(EXIT_SUCCESS); break;
		default: printf("Ошибка\n");
		}
		system("pause");
	}
	
	return 0;


}