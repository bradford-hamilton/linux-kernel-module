#include <linux/module.h>   // included for all kernel modules
#include <linux/kernel.h>   // included for KERN_DEBUG
#include <linux/init.h>     // included for __init and __exit macros

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Bradford");
MODULE_DESCRIPTION("Basic hello world linux kernel module");

static int __init hello(void)
{
    printk(KERN_DEBUG ">>> Hellllo world! <<<\n");
    return 0;   // non-zero return means that the module couldn't be loaded
}

static void __exit goodbye(void)
{
    printk(KERN_DEBUG ">>> Goodbye world <<<\n");
}

// always clean up anything from init in exit
module_init(hello);
module_exit(goodbye)
