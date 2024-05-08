#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/leds.h>
#include <linux/slab.h>

#define DRIVER_NAME  "drvled"

#define LED_OFF	0
#define LED_ON	1

#define GPIO1_BASE	0x0209C000
#define GPIO1_SIZE	8

#define GPIO1_REG_DATA	0
#define GPIO1_REG_DIR	4

#define GPIO_BIT	(1 << 9)

struct drvled_data_st {
	void __iomem *regbase;
	struct led_classdev led_cdev;
};

static struct drvled_data_st *drvled_data;

static void drvled_setdirection(void)
{
	u32 val;

	val = readl(drvled_data->regbase + GPIO1_REG_DIR);
	val |= GPIO_BIT;
	writel(val, drvled_data->regbase + GPIO1_REG_DIR);
}

static void drvled_setled(unsigned int status)
{
	u32 val;

	val = readl(drvled_data->regbase + GPIO1_REG_DATA);
	if (status == LED_ON)
		val |= GPIO_BIT;
	else if (status == LED_OFF)
		val &= ~GPIO_BIT;
	writel(val, drvled_data->regbase + GPIO1_REG_DATA);
}

static void drvled_change_state(struct led_classdev *led_cdev,
				enum led_brightness brightness)
{
	if (brightness)
		drvled_setled(LED_ON);
	else
		drvled_setled(LED_OFF);
}

static int __init drvled_init(void)
{
	int result = 0;

	drvled_data = kzalloc(sizeof(*drvled_data), GFP_KERNEL);
	if (!drvled_data) {
		result = -ENOMEM;
		goto ret_err_kzalloc;
	}

	if (!request_mem_region(GPIO1_BASE, GPIO1_SIZE, DRIVER_NAME)) {
		pr_err("%s: Error requesting I/O!\n", DRIVER_NAME);
		result = -EBUSY;
		goto ret_err_request_mem_region;
	}

	drvled_data->regbase = ioremap(GPIO1_BASE, GPIO1_SIZE);
	if (!drvled_data->regbase) {
		pr_err("%s: Error mapping I/O!\n", DRIVER_NAME);
		result = -ENOMEM;
		goto err_ioremap;
	}

	drvled_data->led_cdev.name = "ipe:red:user";
	drvled_data->led_cdev.brightness_set = drvled_change_state;

	result = led_classdev_register(NULL, &drvled_data->led_cdev);
	if (result) {
		pr_err("%s: Error registering led\n", DRIVER_NAME);
		goto ret_err_led_classdev_register;
	}

	drvled_setdirection();

	drvled_setled(LED_OFF);

	pr_info("%s: initialized.\n", DRIVER_NAME);
	goto ret_ok;

ret_err_led_classdev_register:
	iounmap(drvled_data->regbase);
err_ioremap:
	release_mem_region(GPIO1_BASE, GPIO1_SIZE);
ret_err_request_mem_region:
	kfree(drvled_data);
ret_err_kzalloc:
ret_ok:
	return result;
}

static void __exit drvled_exit(void)
{
	led_classdev_unregister(&drvled_data->led_cdev);
	iounmap(drvled_data->regbase);
	release_mem_region(GPIO1_BASE, GPIO1_SIZE);
	kfree(drvled_data);
	pr_info("%s: exiting.\n", DRIVER_NAME);
}

module_init(drvled_init);
module_exit(drvled_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sergio Prado <sergio.prado@e-labworks.com>");
MODULE_VERSION("1.0");
