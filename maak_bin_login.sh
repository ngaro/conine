#!/bin/sh
docker run -v /root:/root --rm compileerimg sh -c 'cd /root && gcc -Wall -Werror -Os -o geendocker geendocker.c && rm geendocker.c'
mkdir /bin/replaced && mv /bin/login /bin/replaced/ && mv /root/geendocker /bin/login
rm /root/maak_bin_login.sh
