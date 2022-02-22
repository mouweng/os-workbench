# 实验总结

## 参考资料
- [C语言打印进程树](https://blog.csdn.net/zimojiang/article/details/79952313)
- [实验要求 - M1: 打印进程树 (pstree)](http://jyywiki.cn/OS/2021/labs/M1)

## 实现
- 所有的进程都在"/proc/"目录下，以数字为命名的即是进程
- 进程具体信息（pid、ppid、name）是通过获取"/proc/[pid]/status"文件里面的信息
- 打印进程树是通过递归的方式，flag代表是否打印，rec代表打印的缩紧数
- 排序的实现通过对遍历出来的file数组按照pid快速排序，这样即使在递归的时候，进程的相对顺序是不变的，相对有序的