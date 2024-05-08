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
	{ 0x6223d9c5, "led_classdev_unregister" },
	{ 0xa00bc7c2, "kmalloc_caches" },
	{ 0x37a0cba, "kfree" },
	{ 0x576031c7, "gpiod_direction_output" },
	{ 0xfe990052, "gpio_free" },
	{ 0x345ad97b, "led_classdev_register_ext" },
	{ 0x9ac1f1f, "gpio_to_desc" },
	{ 0xc5850110, "printk" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x941ae6bd, "kmem_cache_alloc_trace" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xc4c49dc2, "gpiod_set_value" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "FA2D3A735987BDA7AF644D0");
