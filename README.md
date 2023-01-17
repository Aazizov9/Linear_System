

Данная программа решает систему линейных уравнений с помощью метода вращений.

Описание алгоритма:
    Работа программы состоит из двух этапов.
    В первом программа принимает на вход матрицу и приводит матрицу к треугольному виду.
    Во втором этапе программа применяет обратный ход метода Гаусса.

    Подробное описание алгоритма можно найти:
      Алгоритм метода вращений - [1] 12.2, страница 46


Компоненты программы:
    1. main_lss_01_11.c
    2. lss_01_11.c

Файле main_lss_01_11.c содержит:
    1. Обработку аргументов командной строки.
    2. Открытие файла для входных и выходных данных.
    3. Создание двух массивов А(размером (n*n+n)* sizeof(double)), Х(размером n* sizeof(double)) и запись данных из входного файла в массив А.
        массив А - содержит всю матрицу(правую часть включительно).
        массив Х - содержит значения х_i.
    4. Вызов решателя lss_01_11().
    5. Запись ответа в выходной файл данных.


Функции, реализованные в файле lss_01_11.c:
    void swap(double *a, double *b);
        Описание:
            Функция предназначена для внутренней работы решателя.
            Предназначенная для свапа значений.
    size_t lss_memsize_01_11(int n);
        Описание:
            Функция которая возвращает n * sizeof(double)

    void display_matrix(int n, double *A);
        Описание:
            Функция предназначена для отображения всей матрицы.
    void display_X(int n, double *X);
        Описание:
            Функция предназначена для отображения ответов Х.


    int lss_01_11(int n, double *A, double *B, double *X, double *tmp)
        Описание:
            Основная функция модуля, решающая СЛАУ методом вращений.

        Возвращаемые значения:
            1 - Программа успешно решила задачу, но решения системы не существует
            0 - решение построено
            -1 - метод не применим к данной матрице

Использование программы:
Usage: lss [input_file_name] [output_file_name] [options]\n"
        "Where options include:\n"
        "  -d        print debug messages [default OFF]\n"
        "  -e        print errors [default OFF]\n"
        "  -p        print matrix [default OFF]\n"
        "  -t        print execution time [default OFF]\n"
        "  -h, -?    print this and exit\n"
        "Default input_file_name value is lss_00_00_in.txt, default output_file_name value is lss_00_00_out.txt.");


        n
        a_1_1 a_1_2 ... a_1_n
        a_2_1 a_2_2 ... a_2_n
        .....................
        a_n_1 a_n_2 ... a_n_n
        b_1
        b_2
        ...
        b_n

    Здесь n - число уравнений в системе (число неизвестных всегда считаем равным числу уравнений),
    a_ij - элементы матрицы системы, b_i - элементы вектора правой части.
    Формат чисел: n - "%d", a_ij и b_i - "%lf".

Формат выходных данных, если решение существует

        n
        x_1
        x_2
        ...
        x_n

    Если решения не существует, содержить одну единственную цифру 0.
    Формат чисел: n - "%d", x_i - "%1.9lf".

Коды возвращаемых ошибок:

    0 - Программа успешно решила задачу. Решение построено.
    1 - Программа успешно решила задачу, но решения системы не существует, программа вывела в файл '0'
    -1 - Метод вращений не применим.
    -3 - Ошибка чтения файла.
    -4 - Ошибка валидации параметров. Введённого вами параметра не существует.
    -5 - Введённый Вами файл для входных данных пуст.



Использованная литература:
    [1] К. Ю. Богачёв Практикум на ЭВМ. Методы решения линейных систем и нахождения собственных значений.
    Москва 1998 год.
