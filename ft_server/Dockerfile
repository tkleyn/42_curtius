# Choosing image:version
FROM debian:buster

RUN apt-get update

# Installing nginx
RUN apt-get install -y nginx

# Installing Mariadb (fork of mysql)
RUN apt-get install -y mariadb-server

# Copying wordpress from srcs/
COPY srcs/wordpress /var/www/wordpress

# Copying phpmyadmin from srcs/
COPY srcs/phpmyadmin /var/www/phpmyadmin

# Installing PHP tools
RUN apt-get install -y php7.3-fpm php-mysql

# Installing openssl
RUN apt-get install -y openssl

# Copying nginx configuration file
COPY srcs/nginx_conf /etc/nginx/sites-available/

# Linking nginx configuration file
RUN ln -s /etc/nginx/sites-available/nginx_conf /etc/nginx/sites-enabled/

# Unlinking nginx default configuration file
RUN unlink /etc/nginx/sites-enabled/default

# Copying DB creation file
COPY srcs/maria_conf .

# Launching and creating DB with maria_conf as root
RUN service mysql start && cat maria_conf | mariadb -u root

# Genarating Certificat
RUN echo "BE\nBrussels\nBrussels\n42 Network\nStudent\ntkleynts\ntkleynts@student.s19.be\n" | openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt

# Settings for openssl
RUN openssl dhparam -out /etc/nginx/dhparam.pem 2048

# Starting mysql php nginx
CMD service mysql start && service php7.3-fpm start && nginx -g "daemon off;"
