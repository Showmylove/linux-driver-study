#include <linux/init.h>
#include <linux/module.h>

/// @brief 
MODULE_LICENSE("GPL");
/// @brief 
MODULE_AUTHOR("showlove");

static int hello_init(void) {
    printk(KERN_EMERG "hello world enter!\n");
    return 0;
}

static void hello_exit(void) {
    printk(KERN_EMERG "hello world exit!\n");
}

module_init(hello_init);
module_exit(hello_exit);
