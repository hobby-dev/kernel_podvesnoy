# Готовые проекты
* gnu core utils
* Grep

скачиваем исходники grep с ftp GNU

```
tar -xvf grep-3.0.tar.xz
```

```
mkdir bin
```


```
grep-3.0/configure --prefix ~/Documents/projects/kernel_podvesnoy/lesson_20/bin/
```

Видим, что выполняются проверки системы.

```
make
```
Собрали

```
make install
```
Установили
```
ls bin
``` 
видим, что все установилось

Почти любые программы ставятся по этому же циклу - configure -> make -> make install


# autoconf & automake
Помогают в генерации скрипта configure и Makefile для облегчения настройки и сборки

## Цель - получить скрипт configure
Инструменты:
1. autoconf
2. aclocal
3. automake

Нам понадобится написать минимум два файла:
* configure.ac (требования к системе)
* Makefile.am (описание того, что мы будем делать - что собираем? где исходники? с какими флагами компиляции? куда устанавливать?)

Порядок действий:
1. automake
2. autoconf
3. ???????
4. configure

# Пример: helloworld
```
$ aclocal
$ automake --add-missing
$ touch NEWS README AUTHORS ChangeLog
$ automake
$ autoconf
```
Check out auto tools online manual!

