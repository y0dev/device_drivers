PATH   := /home/devdoesit/rootfs/buildroot/output/host/bin:${PATH}
KDIR   := /home/devdoesit/kernel/linux
ROOTFS := /mnt/nfs/colibri-imx6/

obj-m += drvled.o

all: module install

module:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules

install:
	@$(MAKE) -C $(KDIR) M=$(PWD) INSTALL_MOD_PATH=$(ROOTFS) modules_install

clean:
	@$(MAKE) -C $(KDIR) M=$(PWD) clean
