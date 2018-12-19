#!/bin/sh
docker run -v /root:/root --rm compileerimg sh -c 'cd /root && gcc -Wall -Werror -Os -o geendocker geendocker.c && rm geendocker.c'
mv /root/geendocker /bin/login
