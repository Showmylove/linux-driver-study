#使用bash语言
#!/bin/bash
#通知编译器我们要编译模块的那些源码
obj-m += hello_drv.o
#源码目录变量
KDIR := /home/ubuntu/code/linux-6.0.8
#当前目录变量
PWD ?= $(shell pwd)
#make命名默认寻找第一个目标
#make -C指调用执行的路径
#$(KDIR)Linux源码目录，即/home/topeet/work/iTop4412_Kernel_3.0
#M表示模块
#$(PWD)当前目录变量
#modules 要执行的操作

build: kernel_modules

kernel_modules:
	make -C $(KDIR) M=$(PWD) modules
#清除中间文件（以.o为后缀的文件，也可以清除其它的，只需要.ko为后缀的文件即可）
clean:
	rm -rf .* *.o *.mod *.order *.symvers *.mod.c *.ko
