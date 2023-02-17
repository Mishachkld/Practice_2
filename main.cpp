#include <iostream>
#define SIZE 999

void ownMemcopy(int *dst, int *src, const int &len) {
    int i, m;
    unsigned long long *wdst = (unsigned long long *)dst;   // текущая позиция в буфере назначения (т.е. на каком байте мы находимся в новом массиве)
    unsigned long long *wsrc = (unsigned long long *)src;   // текущая позиция в источнике(т.е. на каком байте мы находимся в старом массиве)
    char  *pointerDst, *pointerSrc;

    m = (SIZE * sizeof(int))/ sizeof(long long);          // получаем целое количество байт, которое нужно перенести ( длину нашего массива в байтах / 8 байт (т.е. long long)
    for(i = 0; i < m; i++)                                  // копируем основную часть блоками по 8 байт
        *(wdst++) = *(wsrc++);                              // (в зависимости от платформы)

    pointerDst = (char*)wdst;
    pointerSrc = (char*)wsrc;

    m = (SIZE * sizeof(int)) % sizeof(long long);          // получаем колличество оставшихся байт, которое нужно перенести ( длину нашего массива в байтах % 8 байт (делим и смотрим остаток)
    for(i = 0; i < m; i++)                                  // остаток копируем побайтно (аналогично предыдущему)
        *(pointerDst++) = *(pointerSrc++);
}

void outArray(int *array, const int &len) {
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    int tecArray[SIZE] = {123, 132, 154145, 2556516, 45454,6};
    int newArray[SIZE] = {0};
    int len = 9;

    ownMemcopy(newArray, tecArray, len);
    outArray(newArray, len);
    return 0;
}





