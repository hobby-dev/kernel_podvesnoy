# Заметки к занятию

Hello World компиляция и запуск:
```
gcc hello.c -o hello_world
./hello_world
```

Исследовать промежуточные файлы:
```
gcc hello.c -o hello_world -save-temps
ls
```

Сборка и линковка нескольких файлов:
```
gcc foo.c bar.c -o foo
ИЛИ
gcc bar.c -c
gcc foo.c bar.o -o foo
```
