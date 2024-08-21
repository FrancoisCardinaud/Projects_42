FROM alpine:3.19

# Install PHP and necessary extensions
RUN apk add --no-cache php82 php82-fpm php82-mysqli php82-opcache php82-gd mysql-client \
    php82-zlib php82-curl php82-mbstring php82-json php82-session php82-phar wget curl bash
 
# Create symlinks for PHP CLI
RUN [ ! -e /usr/bin/php ] || rm /usr/bin/php && ln -s /usr/bin/php82 /usr/bin/php && \
    [ ! -e /usr/sbin/php-fpm ] || rm /usr/sbin/php-fpm && ln -s /usr/sbin/php-fpm82 /usr/sbin/php-fpm

# Ensure www-data user and group exist
RUN if ! getent group www-data >/dev/null; then addgroup -g 82 www-data; fi && \
    if ! getent passwd www-data >/dev/null; then adduser -D -u 82 -G www-data -h /var/www -s /sbin/nologin www-data; fi

COPY /tools/ /tmp/

# Create necessary directories and set permissions for log
RUN rm /etc/php82/php-fpm.conf
RUN mkdir -p /var/www/html
WORKDIR /var/www/html
RUN mkdir -p /var/log/php82 && \ 
    touch /var/log/php82/php_errors.log && \
    touch /var/log/php82/access.log && \
    mkdir -p /run/php-fpm && \
    chown -R www-data:www-data /var/www/html /var/log/php82 && \
    chmod -R 755 /var/www/html /var/log/php82 /run/php-fpm && \
    chown www-data:www-data /var/log/php82/php_errors.log && \
    chmod 644 /var/log/php82/php_errors.log

# Copy PHP-FPM configuration files
COPY ./conf/php-fpm.conf /etc/php82/fpm/php-fpm.conf
COPY ./conf/www.conf /etc/php82/fpm/www.conf
COPY ./conf/php.ini /etc/php82/fpm/php.ini

# Expose port 9000 for PHP-FPM
EXPOSE 9000

RUN wget https://wordpress.org/latest.tar.gz

RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz

WORKDIR /var/www/html/wordpress

RUN chown -R www-data:www-data /var/www/html/wordpress && chmod -R 775 /var/www/html

# Wordpress Instalation
WORKDIR /tmp/
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT ["bash", "/tmp/start.sh"]
