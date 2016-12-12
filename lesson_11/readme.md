# Невыровненное чтение
$ dd bs=1 count=2097151 if=/dev/zero of=test
```
2097151+0 records in
2097151+0 records out
2097151 bytes (2,1 MB, 2,0 MiB) copied, 54,5681 s, 38,4 kB/s
```
# Чтение, выровненное по размеру блока
$ dd bs=1024 count=2048 if=/dev/zero of=test
```
2048+0 records in
2048+0 records out
2097152 bytes (2,1 MB, 2,0 MiB) copied, 0,06133 s, 34,2 MB/s
```
