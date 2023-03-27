# To copy repository
svn co https://github.com/arun_iot/fwc-1/Bluetooth_controlled_UGV/trunk/codes

cd codes

# To build ESP32 firmware

cd ESP_code
pio run
# To flash ESP32 firmware, connect usb-uart adapter
pio run -t nobuild -t upload
# If using termux, use scp to send .pio/build/esp32doit-devkit-v1/firmware.bin to PC

# To build m4 firmware
cd ARM_code/GCC_Project
# modify line 140 of config.mk to setup path to pygmy-sdk or qorc-sdk
# default path is /data/data/com.termux/files/home/pygmy-dev/pygmy-sdk 
make
# If using termux, Use scp to send output/m4_pwmctrl.bin to PC

# To build fpga source
cd FPGA_code/rtl
ql_symbiflow -compile -d ql-eos-s3 -P pu64 -v *.v -t AL4S3B_FPGA_Top -p quickfeather.pcf -dump jlink binary
# If using termux, use scp to send AL4S3B_FPGA_Top.bin to PC

# To flash eos s3 soc, connect usb cable to vaman board
sudo python3 <Type path to tiny fpga programmer application> --port /dev/ttyACM0  --appfpga AL4S3B_FPGA_Top.bin --m4app m4_pwmctrl.bin --mode m4-fpga --reset
