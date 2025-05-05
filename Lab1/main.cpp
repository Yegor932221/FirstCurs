#include"stdio.h"
#include <iostream>
#define UI unsigned int // #define UC unsigned char

UI Set0Last(UI x ,int k)//��������� k �������� ������ 0
{
	UI mask = 1; // 00000001
	for (int i = 0; i <= k; i++)//������� ��������� k ������
	{
		x &= (~mask);//������ 0
		mask <<= 1;//������� �����
	}
	return x;
}

UI Set1Last(UI x, int k)//��������� k �������� ������ 1
{
	UI mask = 1; // 00000001
	for (int i = 0; i <= k; i++)//������� ��������� k ������
	{
		x |= mask;//������ 1
		mask <<= 1;//������� �����
	}
	return x;
}

void OutputBV(UI x, int n)//����� ������ �������
{
	UI mask = 1;//00000001 
	int i;
	mask <<= n - 1;//������� ����� �� n-1
	for (i = 0; i < n; i++, mask >>= 1)//������� ���� ������
	 printf("%d", (x&mask) ? 1 : 0 );//���� ���� 1 (x&mask!=0) �� 1 ����� ����
}

UI SetUp1(UI x, int k)
{
	UI mask = 1; // 00000001
	mask <<= k;
	x |= mask;
	return x;
}

UI Input1BV(char s[], int n)
{
	UI x = 0; int i;
	for (i = 0; i < n; i++)
		if (s[i] == '1') x = SetUp1(, );
	return x;
}


int main()
{
	UI x=43;
	UI y = Set0Last(x, 4);//����� ������� ������� ������ 0
	UI z = Set1Last(x, 4);//����� ������� ������� ������ 1

	printf("before: ");
	OutputBV(x, 8);//����� ������������

	printf("\nafter set0:");
	OutputBV(y, 8);

	printf("\nafter set1:");
	OutputBV(z, 8);

}