/*
 * Хотим проверить, изменится ли значение переменной в ребенке, если поменять ее в родителе (или наоборот)
 *
 */

// printf
#include <stdio.h>
// fork
#include <unistd.h>

int main() {
    int x = 1;

    // ожидаем: если ребенок раньше выполнится, то он мог меняет значение на 100, если родитель, то значение поменяется на 500
    // Вывод будет 1 1. Так как память копируется, но у каждого процесса она своя. Используется
    // copy-on-write, то есть x на самом деле не скопирован, пока мы его не меняем и оба процесса
    // смотрят в одно и то же значение в памяти, однако, когда мы меняем значение на 100 или 500,
    // то создается копия и процессы уже меняют свои куски памяти
    if (fork() == 0) {
        printf("Child: %d\n", x);
        x = 100;
    } else {
        printf("Parent: %d\n", x);
        x = 500;
    }
    return 0;
}
