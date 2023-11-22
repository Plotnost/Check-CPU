// 1 лабараторная.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <windows.h>

__int64 clock1;
__int64 clock2;

int main()
{
    unsigned long long diff;
    unsigned long long aver = 0;
    int i;

    for (i = 0; i < 10; i++)
    {
        __asm {
            rdtsc;
            mov dword ptr[clock1], eax
            mov dword ptr[clock1 + 4], edx
        }

        Sleep(1000);

        __asm {
            rdtsc;
            mov dword ptr[clock2], eax
            mov dword ptr[clock2 + 4], edx
        }

        

        // Рассчитываем прошедшее время в тактах процессора
        diff = clock2 - clock1;

        // количество тактов процессора на вычисления
        printf("Number of cycles in the %u iteration %lld\n", i + 1, diff);
        aver += diff;
    }

    aver = aver / i;
    printf("average number of cycles %llu\n", aver);
    printf("CPU frequency %f GHz\n", float(aver) / 1000000000);

    system("pause");

    return 0;
}
