#!/bin/bash
for a in /etc/init.d /etc/runlevels/* ; do
	for b in acpid crond klogd syslog ; do
		rm $a/$b
	done
done
