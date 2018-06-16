#!/bin/sh

java -XX:+TieredCompilation -XX:+UseNUMA -Xms1G -Xmx1G -Djava.net.preferIPv4Stack=true -jar JCLServer.jar
