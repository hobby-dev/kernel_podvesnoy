# Задача
Для решения проблемы бесконечного откладывания процесса с низким приоритетом используется механизм старения процессов.
Чем дольше процесс ждёт, тем выше его приоритет.
Написать алгоритм планровщика с учётом старения.
1. Измерить производительность алгоритма.
2. Измерить время ожидания.

# Подход
На вход подаётся тестовый список процессов.
Общее время их выполнения задано заранее, T-Общее, оно будет одинаковым.
Меняться будут только накладные расходы и количество процессов, завершённых за единицу времени.
Квант времени 100 мс.

# Мои результаты:

schedule_rr:
    priority: 3, TC: 110, total_time_waited: 400
    priority: 6, TC: 100, total_time_waited: 399
    priority: 2, TC: 40, total_time_waited: 340
    priority: 4, TC: 30, total_time_waited: 320
    priority: 1, TC: 30, total_time_waited: 318
    priority: 1, TC: 30, total_time_waited: 316
    priority: 1, TC: 30, total_time_waited: 315
    priority: 9, TC: 30, total_time_waited: 314
    priority: 7, TC: 30, total_time_waited: 313
    priority: 0, TC: 30, total_time_waited: 312
    priority: 3, TC: 30, total_time_waited: 310
    priority: 0, TC: 10, total_time_waited: 117
    priority: 1, TC: 10, total_time_waited: 109

schedule_age:
    priority: 0, TC: 30, total_time_waited: 480
    priority: 1, TC: 30, total_time_waited: 465
    priority: 1, TC: 30, total_time_waited: 464
    priority: 1, TC: 30, total_time_waited: 463
    priority: 2, TC: 40, total_time_waited: 407
    priority: 0, TC: 10, total_time_waited: 415
    priority: 3, TC: 110, total_time_waited: 305
    priority: 1, TC: 10, total_time_waited: 335
    priority: 3, TC: 30, total_time_waited: 268
    priority: 4, TC: 30, total_time_waited: 206
    priority: 6, TC: 100, total_time_waited: 99
    priority: 7, TC: 30, total_time_waited: 45
    priority: 9, TC: 30, total_time_waited: 2

