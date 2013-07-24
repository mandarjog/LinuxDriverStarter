#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/errno.h> /* error codes */
#include <linux/types.h> /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h> /* O_ACCMODE */
#include <asm/uaccess.h> 

MODULE_LICENSE ("Dual BSD/GPL");

ssize_t
hello_read (struct file *filp, char *buf, size_t count, loff_t * f_pos)
{

  printk ("<1> %s Hello world!\n", __FUNCTION__);
  /* Transfering data to user space */
  copy_to_user (buf, "Hello", 6);
  return 6;

  // This file never ends, its like /dev/zero

}

int
hello_open (struct inode *inode, struct file *filp)
{
  /* Success */
  return 0;
}
static int hello_major = 89;
struct file_operations fops = {

open:hello_open,
read:hello_read
/*
   write: hello_write,
   lease: hello_release
*/
};


static int
hello_init (void)
{
  int result;
  printk ("<1> Hello world!\n");

  /* Registering device */
  result = register_chrdev (hello_major, "hello", &fops);
  if (result < 0)
    {
      printk ("<1>hello: cannot obtain major number %d\n", hello_major);
      return result;
    }
  return result;
}

static void
hello_exit (void)
{
  unregister_chrdev(hello_major, "hello");
  printk ("<1> Bye, cruel world\n");
}

module_init (hello_init);
module_exit (hello_exit);
