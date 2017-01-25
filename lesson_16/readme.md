# Sockets and Named Pipes
Literature: Advanced Linux programming

Для родственных процессов мы можем наладить одностороннее взаимодействие через Pipe (за счёт наследования FD между родственными процессамми).
man 3 popen

Теперь рассмотрим решения для произвольных процессов (не обязательно родственным).
# Named pipe (FIFO)
    filesystem: /tmp/fifo
    не просто файл - специальный fifo-файл линукса
    вызовы open() на чтение и запись будут блокироваться пока не создастя связь
```
$ mkfifo /tmp/my_fifo
$ ls /tmp
$ cat /tmp/my_fifo
$ echo "Hello" > /tmp/my_fifo
```
```
$ man 3 mkfifo
```
```
$ man 7 fifo
```

# Sockets
Позволяют обмениваться данным между процессами и между машинами в сети.
Connection: local or internet

* Способ взаимодействия
    (соединение [tcp/ip] или datagram[udp] широковещательные)
* Пространство имён (домен, namespace): local(одна машина), internet(сеть)

Системные вызовы:
socket();
bind(); - привязать к адресу (файл, ip:port), идентификация в системе
connect(); - установить соединение
accept(); - принять соединение

server:
1.  socket();
2.  bind();
3.  listen();
4.  accept(); (блокирует и ожидает соединения)
(после accept() создаётся новый сокет для обмена)
(часто делает в отдельный поток, не процесс)
5.  read()/write()
6.  close()




client:
1.  socket();
2.  connect();  // блокируется пока сервер не сделает accept()
3.  close();


man 7 unix 
man 7 ip 



