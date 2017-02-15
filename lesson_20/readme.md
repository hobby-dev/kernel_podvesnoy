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
