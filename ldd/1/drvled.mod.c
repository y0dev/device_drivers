#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x91ad717e, "module_layout" },
	{ 0x78bb51f1, "cdev_del" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x4ca167a2, "cdev_add" },
	{ 0xeabc6401, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xc5850110, "printk" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xae353d77, "arm_copy_from_user" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0xb70789e, "__might_fault" },
	{ 0x97255bdf, "strlen" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "10F3AE78E791EA2B710948B");
