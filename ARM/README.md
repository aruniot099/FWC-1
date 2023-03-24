1. Install all the requirments provided in:
"https://github.com/gadepall/vaman/blob/master/installation/termuxubuntu/termuxubuntu_arm.txt"
2. Transfer .bin file to RPI using the command
scp <Path to the .bin file> <username of Laptop>@<ip address>:<path to file to be stored on laptop>
Example:scp /data/data/com.termux/files/home/ARM_GCC/GCC_Project/output/bin/ARM_GCC.bin arun_iot@192.168.11.148:/home/arun_iot
3. on Laptop linux terminal :

--> open the flash.m4 then change the path to TinyFPGA-Programmer-Application

-->bash flash.m4 AVR_GCC.bin
(by this command the .bin file will be uploaded to the VAMAN board.
