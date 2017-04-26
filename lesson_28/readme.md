# Последнее слово про списки:
```
struct list_head {
    struct list_head * next;
    struct list head * prev;
]

struct task_struct {
    ...
    struct list_head children;
    ...
}

```

Как только мы добавляем list_head в свою струтуру, для получения доступа к элементам списка мы можем использовать:
```
struct task_struct * list_entry(struct list_head * p, struct task_struct, children));
см. также:
containerof
list_for_each()
list_for_each_entry()

```

