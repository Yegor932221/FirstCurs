#include"stdio.h"
#include <iostream>

void CreateFile(const char* name, int n, int lf, int rt)//������� ��������� ���� name n ������� � ��������� �� lf �� rt
{
	FILE* f;
	int x;
	fopen_s(&f, name, "w");//��������
	if (f == NULL) //�������� �������� ��
	{ 
	perror("error opening file in CreateFile");//����� ������
	exit(-1); 
	}
	srand(time(0));//����� ��� ������� 
	for (int i = 0; i < n; i++)
	{
		x = rand() % (rt - lf + 1) + lf;//��������� �����
		fprintf(f, "%d ", x);//���������
	}
	fclose(f);//�� �������� ��������� ����
}


void PrintFile(const char* name)
{
	FILE* f;
	int x;
	fopen_s(&f, name, "r");//���������
	if (f == NULL) //��������� ��������
	{
		perror("error opening file in PrintFile");//����� ������
		exit(1);
	}
	while (fscanf_s(f, "%d", &x) != EOF) printf("%d ", x);//���� �� ����� �� ����� ����� ������� ��� ������
	fclose(f);//�� �������� ��������� ����
}

void CopyOnlyPositivFile(FILE* from, FILE* to)
{
	int x;
	while (fscanf_s(from, "%d", &x) != EOF)//���� �� ����� ������� �����
		if (x >= 0)//���� ����� �� ����� �������������
		{
			fprintf(to, "%d ", x);//��������� �� ������ ����
		}
}

int main()
{
	FILE *f_before;//���� � ������� ����� ��
	FILE* f_after;//���� � ������� ����� �����
	CreateFile("randomText.txt", 20, -100, 100);//��������� ����������� ���� ������� �� -100 �� 100
	if (fopen_s(&f_before, "randomText.txt", "r")!=0)//��������� ����� �� ����������� ���� ������� � ��������� �� ������
	{
		perror("error opening randomText.txt �");//����� ������ ���� ���� �� ��������
		exit(-1);
	}
	if (fopen_s(&f_after, "finishText.txt", "w")!=0)//��������� ����� �� �������� ���� ������� � ��������� �� ������
	{
		perror("error opening finishText.txt �");//����� ������ ���� ���� �� ��������
		exit(-1);
	}

	CopyOnlyPositivFile(f_before, f_after);//�������� ������ ������������� �����

	fclose(f_after);//�� �������� ������� ���������
	fclose(f_before);//�� �������� ������� ���������

	printf("before: ");//����� ����� ��
	PrintFile("randomText.txt");

	printf("\nafter: ");//����� ����� �����
	PrintFile("finishText.txt");

	
	return 1;
}


