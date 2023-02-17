#include <iostream>
#define SIZE 1000

void myMemcopy( int *dst, int *src, int &len) {
    int i, m;
    unsigned long long *wdst = (unsigned long long *)dst;   // текущая позиция в буфере назначения
    unsigned long long *wsrc = (unsigned long long *)src;   // текущая позиция в источнике
    char  *pointerDst, *pointerSrc;

    m = (SIZE * sizeof(int))/ sizeof(long long);
    for(i = 0; i < m; i++)                                  // копируем основную часть блоками по 4 или 8 байт
        *(wdst++) = *(wsrc++);                              // (в зависимости от платформы)

    pointerDst = (char*)wdst;
    pointerSrc = (char*)wsrc;

    m = (SIZE * sizeof(int)) % sizeof(long long);
    for(i = 0; i < m; i++)                                  // остаток копируем побайтно
        *(pointerDst++) = *(pointerSrc++);
}

void outArray(int *array, const int &len) {
    for (int i = 0; i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

int main() {
    int tecArray[SIZE] = {123, 132, 3, 2556516, 45454,6};
    int newArray[SIZE] = {0};
    int len = 6;

    myMemcopy(newArray, tecArray, len);
    outArray(newArray, len);
    return 0;
}





