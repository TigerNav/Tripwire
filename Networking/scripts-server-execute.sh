#!/bin/bash

cd /home/pi/Tripwire/Networking/PI\ Server

wget -q --spider http://google.com

sleep 15

while [ 1 ] ; do
if [ $? -eq 0 ]; then
    echo "Online"
    bin/main
    break

else
    echo "Offline"
    continue
fi
done


