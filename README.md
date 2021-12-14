# Push-Swap-42

Push_Swap - это проект École 42 (Школа 21), который заключается в создании алгоритма сортировки двух стэков "a" и "b";
Для сортировки используется алгоритм Radix (radix sort) => Поразрядная сортировка.
Стэки представляют собой linked-lists.

Сортировка производится следующими операциями:
```
- sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
- sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.
```

## Установка

Чтобы собрать программу:
```
make
```
Эта команда скомпилируют программу => исполняемый файл «./push_swap».

### Инструкции
Программа принимает один аргумент => последовательность уникальных целых чисел от -2147483648 до 2147483647.
Чтобы запустить программу:
```
$ ./push_swap "100 0 21 42 9 100000 -21 -42"
```

Для проверки программы используете следующую команду:
```
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
Более побробно о проекте можете прочитать в en.subject_push.pdf

