#include"stdio.h"
#include <iostream>
#define UI unsigned int // #define UC unsigned char


void OutputBV(UI x, int n)//����� ������ �������
{
	UI mask = 1;//00000001 
	int i;
	mask <<= n - 1;//������� ����� �� n-1
	for (i = 0; i < n; i++, mask >>= 1)//������� ���� ������
		printf("%d", (x & mask) ? 1 : 0);//���� ���� 1 (x&mask!=0) �� 1 ����� ����
}

void OutputBM(UI* bm, int m, int n)//����� �������
{
	for (int i = 0; i < m; i++)
	{
		OutputBV(bm[i], n);//����� �������
		puts(" "); 
	}
}

UI Input2BV(char s[], int n)//���� �������
{
	UI x = 0; int i;
	for (i = 0; i < n; i++)
	{
		x <<= 1;
		if (s[i] == '1') x++;
	} 
	return x;
}

void InputBM(UI* bm, int m, int n)//���� �������
{
	char s[33];
	for (int i = 0; i < m; i++)
	{
		fgets(s,33,stdin); //������ ������
		bm[i] = Input2BV(s, n);//������ � ������
	}
}

int MaxWeight(UI* x,int m, int n)//������������� ������������� �� ���� �������
{
	UI mask = 1;
	int max = 0, max_it=0;
	int now = 0;
	for (int i = 0; i < n; i++, mask <<= 1)//������� �����
	{
		for (int j = 0; j < m; j++)//������� ��������
		{
			if (x[j] & mask) now++;
		}
		if (now > max)
		{
			max = now;
			max_it = i;
		}
	}
	return max_it;
}

int Definebit(UI value, int k)//����� ����� ��� ��� � �������
{
	UI mask = 1;
	mask <<= k; 
	if ((value & mask) == 0) return 0;
	else return 1;
}

UI Invert(UI x, int k)//����������� �-��� �������
{
	UI mask = 1;
	mask <<= k;
	x ^= mask;
	return x;
}

UI* ChangeMaxAndK(UI* x, int m, int n, int k)
{
	int max = MaxWeight(x, m, n);//������� ��������
	if (k == max) return x;
	UI maxMask = 1;
	UI kMask = 1;
	maxMask <<= max;
	kMask <<= k;
	for (int i = 0; i < m; i++)
	{
		if (Definebit(x[i],max)!=Definebit(x[i],k))//���� ���������� ��������
		{
			x[i]=Invert(x[i], max);//����������� ���
			x[i] = Invert(x[i], k);
		}
	}
	return x;
}

int main()
{
	UI* x=new UI[3];
	printf("Input BM\n");
	InputBM(x, 3, 8);
	printf("\n");
	UI* y =ChangeMaxAndK(x, 3, 8, 2);
	OutputBM(y, 3, 8);
	delete[] x;
}