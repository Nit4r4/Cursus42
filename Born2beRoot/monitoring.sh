#!/bin/bash

archi=$(uname -a)
pcpu=$(nproc)
vcpu=$(cat /proc/cpuinfo | grep "cpu cores" | wc -l)
memusage=$(free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}')

disk_used=$(df -h --output=used --total | awk 'END {print $1}')
disk_total=$(df -h --output=size --total | awk 'END {print $1}')
disk_percent=$(df --total | grep 'total' | rev | cut -d ' ' -f 2 | rev)

CPUload=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lastboot=$(who -b | awk '{print $(NF-1) " " $(NF-0)}')

lvmt=$(lsblk | grep "lvm" | wc -l)
lvm=$(if [ $lvmt -eq 0 ]; then echo no; else echo yes; fi)

TCPconnexions=$(netstat -a | grep 'ESTABLISHED' | wc -l)
userlog=$(who | wc -l)

ip=$(hostname -I)
mac=$(ip link show | awk '$1 == "link/ether" {print $2}')

sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall -n "
#Architecture   : $archi
#CPU Physical   : $pcpu
#vCPU           : $vcpu
#Memory Usage   : $memusage
#Disk Usage     : $disk_used/$disk_total ($disk_percent)
#CPU load       : $CPUload
#Last boot      : $lastboot
#LVM use        : $lvm
#Connexions TCP : $TCPconnexions
#User log       : $userlog
#Network        : $ip ($mac)
#Sudo           : $sudo cmd
"
