#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <math.h>

float resh(float a, float b, float c);

int main(int arg, char* argv[])
{
	system("chcp 1251>nul");
	float mas[10];
	for (int i = 0; i < arg; i++)
	{
		mas[i] = atof(argv[i]);
	}
	//проверка если меньше 3 аргумента
	if (arg < 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "введено меньше 3 чисел!!!");
		fclose(rez);
		printf("введено меньше 3 чисел!!!");
	}
	//проверка если больше 3 аргумента
	else if (arg > 3)
	{
		FILE* rez = fopen("rez.txt", "w");
		fprintf(rez, "введено больше 3 чисел!!!");
		fclose(rez);
		printf("введено больше 3 чисел!!!");
	}
	else
	{
		float a = mas[0];
		float b = mas[1];
		float c = mas[2];
		//проверка если а =0
		if (a == 0)
		{
			FILE* rez = fopen("rez.txt", "w");
			fprintf(rez, "\nКоэффицент a не может быть равен нулю!!!");
			fclose(rez);
			printf("\nКоэффицент a не может быть равен нулю!!!");
		}
		else
		{
			//передаем данные в метод resh
			resh(a, b, c);
		}
	}
	return 10;
}
//метод для подсчета дискрименанта
float diskr(float a, float b, float c)
{
	return b * b - 4 * a * c;
}
//метод решения
float resh(float a, float b, float c)
{
	FILE* rez = fopen("rez.txt", "w"); //открываем файл для записи
	if (diskr(a, b, c) < 0)//проверка меньше ли дискрименант 0
	{
		fprintf(rez, "\nДействительных корней нет, D=%-5.2f.", diskr(a, b, c));
		fclose(rez);
		printf("\nДействительных корней нет, D=%-5.2f.", diskr(a, b, c));
	}
	else if (diskr(a, b, c) == 0)//проверка равен ли дискрименант 0
	{
		float x = (-b) / (2 * a);
		fprintf(rez, "\nD = %f. x = %f", diskr(a, b, c), x);
		fclose(rez);
		printf("\nD = %f. x = %f", diskr(a, b, c), x);
	}
	else
	{
		float x1 = (-b + sqrt(diskr(a, b, c))) / (2 * a);
		float x2 = (-b - sqrt(diskr(a, b, c))) / (2 * a);
		fprintf(rez, "\nD = %-5.2f. x1 = %-5.2f, x2 = %-5.2f", diskr(a, b, c), x1, x2);
		fclose(rez);
		printf("\nD = %-5.2f. x1 = %-5.2f, x2 = %-5.2f", diskr(a, b, c), x1, x2);
	}
}

