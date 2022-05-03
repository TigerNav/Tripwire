#!/bin/bash

arduino-cli compile --fqbn arduino:avr:uno /home/pi/Tripwire/modules/src
arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno /home/pi/Tripwire/modules/src
