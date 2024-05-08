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
	{ 0xe68b5694, "platform_driver_unregister" },
	{ 0x94231875, "__platform_driver_register" },
	{ 0xc4c49dc2, "gpiod_set_value" },
	{ 0x81c8b7f1, "_dev_err" },
	{ 0x576031c7, "gpiod_direction_output" },
	{ 0x4dcf94b5, "devm_led_classdev_register_ext" },
	{ 0x95cfea62, "of_get_property" },
	{ 0x9ac1f1f, "gpio_to_desc" },
	{ 0xf0300ac1, "devm_gpio_request" },
	{ 0x9c824afa, "of_get_named_gpio_flags" },
	{ 0x502d044a, "devm_kmalloc" },
	{ 0x3ce434a9, "of_get_next_child" },
	{ 0xefd6cf06, "__aeabi_unwind_cpp_pr0" },
	{ 0xf82f08f4, "_dev_info" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1887AA06DE798F08D5DBC1E");
