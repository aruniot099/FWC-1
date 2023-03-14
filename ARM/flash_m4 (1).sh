#!/bin/bash
sudo python3 /home/arun_iot/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0  --appfpga top.bin --m4app $1 --mode m4-fpga --reset
