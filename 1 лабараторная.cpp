// 1 лабараторная.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

int main()
{
	
	unsigned clock = 0;
	unsigned long long average = 0;
	int i;

	for (i = 0; i < 5; i++)
	{
		__asm rdtsc;
		__asm mov[clock], eax;

		// задержка 1 секунда
		Sleep(1000);


		__asm rdtsc;
		__asm sub eax, [clock];
		__asm mov[clock], eax;

		// количество тактов процессора на вычисления
		printf("Number of cycles in the %u iteration %u\n", i+1, clock);
		average += clock;
	};
	average = average / i;
	printf("average number of cycles %llu\n", average);
	printf("CPU frequency %f\n", float(average)/1000000000);

	system("pause");

	return 0;
}
