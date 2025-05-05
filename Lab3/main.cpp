#include"stdio.h"
#include <iostream>

void CreateFile(const char* name, int n, int lf, int rt)//функци€ заполн€ет файл name n числами в диапозоне от lf до rt
{
	FILE* f;
	int x;
	fopen_s(&f, name, "w");//открытие
	if (f == NULL) //проверка открылс€ ли
	{ 
	perror("error opening file in CreateFile");//вывод ошибки
	exit(-1); 
	}
	srand(time(0));//старт дл€ рандома 
	for (int i = 0; i < n; i++)
	{
		x = rand() % (rt - lf + 1) + lf;//рандомное число
		fprintf(f, "%d ", x);//вписываем
	}
	fclose(f);//не забываем закрывать файл
}


void PrintFile(const char* name)
{
	FILE* f;
	int x;
	fopen_s(&f, name, "r");//открываем
	if (f == NULL) //провер€ем открытие
	{
		perror("error opening file in PrintFile");//вывод ошибки
		exit(1);
	}
	while (fscanf_s(f, "%d", &x) != EOF) printf("%d ", x);//пока не дошли до конца файла выводим его данные
	fclose(f);//не забываем закрывать файл
}

void CopyOnlyPositivFile(FILE* from, FILE* to)
{
	int x;
	while (fscanf_s(from, "%d", &x) != EOF)//пока не конец первого файла
		if (x >= 0)//если число из файла положительное
		{
			fprintf(to, "%d ", x);//вписываем во второй файл
		}
}

int main()
{
	FILE *f_before;//файл в котором будет до
	FILE* f_after;//файл в котором будет ответ
	CreateFile("randomText.txt", 20, -100, 100);//заполн€ем изначальный файл числами от -100 до 100
	if (fopen_s(&f_before, "randomText.txt", "r")!=0)//провер€ем можно ли изначальный файл открыть и открываем на чтение
	{
		perror("error opening randomText.txt Е");//вывод ошибки если файл не открылс€
		exit(-1);
	}
	if (fopen_s(&f_after, "finishText.txt", "w")!=0)//провер€ем можно ли итоговый файл открыть и открываем на запись
	{
		perror("error opening finishText.txt Е");//вывод ошибки если файл не открылс€
		exit(-1);
	}

	CopyOnlyPositivFile(f_before, f_after);//копируем только положительные числа

	fclose(f_after);//не забываем воврем€ закрывать
	fclose(f_before);//не забываем воврем€ закрывать

	printf("before: ");//вывод файла до
	PrintFile("randomText.txt");

	printf("\nafter: ");//вывод файла после
	PrintFile("finishText.txt");

	
	return 1;
}


