#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

//probe function ==> It would not be called if other driver has token the device
// You have to unload other driver
static int pen_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	printk(KERN_INFO "[*] SolidusCode Pen drive (%04X:%04X) plugged in\n", id->idVendor, id->idProduct);
	return 0; //return 0 indicates we will manage this device
}

// disconnect : clean up the memory
static void pen_disconnect(struct usb_interface *interface){
	printk(KERN_INFO "[*] SolidusCode Pen drive removed \n");
}

//usb_device_id
static struct usb_device_id pen_table[]={
	// device_id
	// use "lsusb" command to check up
	// use "lsusb -v" for detail
	// idVendor , idProduct
	{ USB_DEVICE(0x2008, 0x2009)},
	{}	/* Terminating entry*/
};
MODULE_DEVICE_TABLE (usb, pen_table);

// usb_driver
static struct usb_driver pen_driver = 
{
	.name = "SolidusCode-USB Stick-Driver",
	.id_table = pen_table,	// usb_device_id
	.probe = pen_probe,
	.disconnect = pen_disconnect
};

static int __init pen_init(void){
	int ret = -1;
	//register 
	printk(KERN_INFO "[*]SolidusCode Constructor of driver");
	printk(KERN_INFO "\tRegister Driver with Kernel");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "\tRegistration is complete");
	return ret;
}

static void __exit pen_exit(void){
	//deregister
	printk(KERN_INFO "[*] SolidusCode Destructor of driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tunregisteation complete!");
}

module_init(pen_init);
module_exit(pen_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Soliduscode");
MODULE_DESCRIPTION("USB Pen Registtation Driver");
