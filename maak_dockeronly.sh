#!/bin/sh
docker run -v /root:/root --rm compileerimg sh -c 'cd /root && gcc -Wall -Werror -Os -o dockeronlylogin dockeronlylogin.c && rm dockeronlylogin.c'
echo "dockeronly:x:65533:65533:dockeronly:/:/bin/dockeronlylogin" >> /etc/passwd
mv /root/dockeronly /bin/
rm /root/maak_dockeronly.sh
