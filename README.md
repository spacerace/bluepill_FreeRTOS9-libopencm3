# BluePill / STM32F103C8T6 libopencm3 FreeRTOS 9.0.0 example
This folder contains a simple example for FreeRTOS on those Blue-Pill boards using [libopencm3](https://github.com/libopencm3/libopencm3). It's controller is a `STM32F103C8T6`.  
  
A simple LED-blinker task will be created that blinks the onboard LED on PC13. If it blinks, it works!  
  
This example uses USART1 to communicate with 115200,8n1 baud.  
  
FreeRTOS is configured to use heap_4, which allows dynamic allocation/freeing of memory. This is what people are used to on a regular PC.  
16kB of heap are allocated for FreeRTOS.  This can be changed in `src/freertos/include/FreeRTOSConfig.h`.

# Requirements
You will need a suitable arm-gcc for building and texane's st-link utility for flashing.  
If you're using ARM's official gcc distribution everything will be fine.
  
libopencm3 is included in this archive.  

# Compiling
```
$ make
```
This will build libopencm3 and the demo-code. It will generate an ELF, a BIN and a HEX binary,
as well as listing and map files.

# libopencm3
There is a "static" copy of libopencm3 in `src/` unlike other examples and tutorials on the internet,
which use a git submodule to allow automatic updating of libopencm3.  
I prefer *not* to update a project's library once it is working, as it could break things.  
Once you're done and your device is running the working firmware you really should keep a exact copy
of your sourcecode.  
Updating is a good thing, but only if you know what you're doing and in this case, only if needed.  
  
I have removed a lot of stuff from libopencm3's source directory which targets other MCUs.

# Licensing
libopencm3 is GNU LGPL v3.  
Makefile and usart-/demo-code written by me is 'public domain'.  

