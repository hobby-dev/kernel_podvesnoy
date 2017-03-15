# Внутренности ядра Linux
# Процессы

Процесс - это программа, которая находится в стадии выполнения.
Представление в памяти:
1. text (Бинарный код) - read-only access, execution allowed
2. data - read-write access, no execution
3. stack (локальные переменные) - read-write access, no execution

Жизненный цикл процесса:
1. выполнение
2. готов к выполнению
3. заблокирован (ввод-вывод)

Готов -> Запуск -> Выполнение -> Ввод-вывод -> Заблокирован -> Пробуждение -> Готов

Выполнение -> Проходит квант времени -> Готов

Все "Готовые" процессы стоят в очереди готовности в соответсвии с приоритетом.

Что делает операционная система с процессами:
1. Создаёт процессы (выделение памяти)
2. Блокировка при операциях ввода-вывода
3. Диспетчеризация 
4. Запуск
5. Inter-process communication

# Управление процессами
PID - process id
Блок управления процессом PCB (дескриптор процесса) - полностью описывает процесс:
1. PID
2. состояние
3. приоритет
4. ресурсы
5. полномочия  
6. программный счётчик - это где процесс остановился (PC, programm counter) - адрес в той программе, которую мы выполняем
9. контекст выполнения - состояние всех регистров
7. указатели на данные и код
8. PID родительского процесса и дочерних
10. и другое 

Таблица процессов - все дескрипторы всех процессов:
PID -> PCB

Можем приостановить готовый процесс, можем остановтиь заблокированный процесс.
Можем возобновить приостановленный процесс.

# Что и как в Linux? 
Смотрим linux includes sched.h и ищем там struct tast_struct
```
volatile long state
...
#define TASK_RUNNING
#define TASK_INTERRUPTIBLE
#define TASK_UNINTERRUPTIBLE

```

```
fork() -> TASK_RUNNING (Готов) -> schedule() -> context_switch() -> TASK_RUNNING (Выполняется) -> TASK_(UN)INTERRUPTIBLE (ожидание события)
```

Процессы Zombie: do_exit()