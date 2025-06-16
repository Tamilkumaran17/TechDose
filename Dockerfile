FROM ubuntu:latest

RUN apt update
RUN apt -y install tzdata apache2 net-tools curl

COPY node.html /var/www/html/index.html

EXPOSE 80

CMD ["/usr/sbin/apachectl", "-D", "FOREGROUND"]