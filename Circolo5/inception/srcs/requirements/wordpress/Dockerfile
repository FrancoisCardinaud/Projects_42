FROM debian:buster

# Install PHP and necessary extensions
RUN apt-get update && apt-get install \
    php82 php82-fpm php82-mysqli php82-opcache php82-gd \
    php82-zlib php82-curl php82-mbstring php82-json php82-session curl
 
# Create symlinks for PHP CLI
RUN ln -s /usr/bin/php82 /usr/bin/php && ln -s /usr/sbin/php-fpm82 /usr/sbin/php-fpm

# Ensure www-data user and group exist
RUN if ! getent group www-data >/dev/null; then addgroup -g 82 www-data; fi && \
    if ! getent passwd www-data >/dev/null; then adduser -D -u 82 -G www-data -h /var/www -s /sbin/nologin www-data; fi

# Create necessary directories and set permissions for logg>
RUN mkdir -p /var/www/html && \
    mkdir -p /var/log/php82 && \
    touch /var/log/php82/error.log && \
    touch /var/log/php82/access.log && \
    mkdir -p /run/php-fpm && \
    chown -R www-data:www-data /var/www/html /var/log/php82>
    chmod -R 755 /var/www/html

# Copy PHP-FPM configuration files
COPY ./conf/php-fpm.conf /etc/php82/php-fpm.conf
COPY ./conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY ./conf/php.ini /etc/php82/php.ini

# Expose port 9000 for PHP-FPM
EXPOSE 9000

ADD https://wordpress.org/latest.tar.gz /var/www/latest.tar.gz

RUN cd /var/www && tar -xvf latest.tar.gz && rm -rf latest.tar.gz

RUN curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent

RUN chmod +x ./usr/bin/wp

RUN mkdir /run/php

COPY ./conf/config.sh /var/www/html/config.sh

RUN chmod +x /var/www/html/config.sh

# Start PHP-FPM
CMD ["bash", "/var/www/html/config.sh"]
