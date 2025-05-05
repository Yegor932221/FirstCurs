#include"stdio.h"
#include <iostream>
#define UI unsigned int // #define UC unsigned char

UI Set0Last(UI x ,int k)//последние k символов делает 0
{
	UI mask = 1; // 00000001
	for (int i = 0; i <= k; i++)//перебор последних k членов
	{
		x &= (~mask);//ставим 0
		mask <<= 1;//двигаем маску
	}
	return x;
}

UI Set1Last(UI x, int k)//последние k символов делает 1
{
	UI mask = 1; // 00000001
	for (int i = 0; i <= k; i++)//перебор последних k членов
	{
		x |= mask;//ставим 1
		mask <<= 1;//двигаем маску
	}
	return x;
}

void OutputBV(UI x, int n)//вывод булева вектора
{
	UI mask = 1;//00000001 
	int i;
	mask <<= n - 1;//двигаем маску на n-1
	for (i = 0; i < n; i++, mask >>= 1)//перебор всех членов
	 printf("%d", (x&mask) ? 1 : 0 );//если была 1 (x&mask!=0) то 1 иначе нуль
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
	UI y = Set0Last(x, 4);//вызов функции которая ставит 0
	UI z = Set1Last(x, 4);//вызов функции которая ставит 1

	printf("before: ");
	OutputBV(x, 8);//вывод изначального

	printf("\nafter set0:");
	OutputBV(y, 8);

	printf("\nafter set1:");
	OutputBV(z, 8);

}