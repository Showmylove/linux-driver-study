#include <linux/init.h>
#include <linux/module.h>
#include <linux/platform_device.h>

/// @brief 
MODULE_LICENSE("GPL");
/// @brief 
MODULE_AUTHOR("showlove");

#define DRIVER_NAME "register_dev"

/*驱动初始化函数*/
static int register_dev_probe(struct platform_device *pdv)
{
    printk(KERN_EMERG "register_dev_probe\r\n"); //打印信息
    return 0;
}
/*移除驱动函数*/
static int register_dev_remove(struct platform_device *pdv)
{
    printk(KERN_EMERG "register_dev_remove\r\n"); //打印信息
    return 0;
}
/*断电后驱动执行的函数*/
static void register_dev_shutdown(struct platform_device *pdv)
{
    printk(KERN_EMERG "register_dev_shutdown\r\n"); //打印信息
}
/*驱动休眠函数*/
static int register_dev_suspend(struct platform_device *pdv, pm_message_t pm)
{
    printk(KERN_EMERG "register_dev_suspend\r\n");  //打印信息
    return 0;
}
/*驱动恢复函数*/
static int register_dev_resume(struct platform_device *pdv)
{
    printk(KERN_EMERG "register_dev_resume\r\n");   //打印信息
    return 0;
}

struct platform_driver register_dev_driver = {
    /*一些函数的注册，通过函数指针的形式传入*/
    .probe = register_dev_probe,
    .remove = register_dev_remove,
    .shutdown = register_dev_shutdown,
    .suspend = register_dev_suspend,
    .resume = register_dev_resume,
    /*device_driver结构体*/
    .driver = {
        .name = DRIVER_NAME,  //驱动名，注意要与设备名相同
        .owner = THIS_MODULE, // THIS_MODULE
    }
};

static int register_dev_init(void)
{
    printk(KERN_EMERG "hello world enter!\n");
    if(platform_driver_register(&register_dev_driver)) {
        printk(KERN_EMERG "platform_driver_register error\r\n");
    }

    return 0;
}

static void register_dev_exit(void) {
    platform_driver_unregister(&register_dev_driver);
    printk(KERN_EMERG "hello world exit!\r\n");
}

module_init(register_dev_init);
module_exit(register_dev_exit);
