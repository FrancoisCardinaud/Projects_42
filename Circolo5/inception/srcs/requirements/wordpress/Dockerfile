# Dockerfile for WordPress with PHP-FPM

FROM alpine:3.18

# Install PHP 8.2 and necessary extensions
RUN apk update && apk add --no-cache \
    php82 php82-fpm php82-mysqli php82-opcache php82-gd php82-zlib php82-curl php82-mbstring php82-json php82-session

# Create symlinks for PHP CLI
RUN ln -s /usr/bin/php82 /usr/bin/php && ln -s /usr/sbin/php-fpm82 /usr/sbin/php-fpm

# Ensure www-data user and group exist
RUN if ! getent group www-data >/dev/null; then addgroup -g 82 www-data; fi && \
    if ! getent passwd www-data >/dev/null; then adduser -D -u 82 -G www-data -h /var/www -s /sbin/nologin www-data; fi

# Create necessary directories and set permissions for logging
RUN mkdir -p /var/log/php82 && \
    touch /var/log/php82/error.log && \
    touch /var/log/php82/access.log && \
    mkdir -p /run/php-fpm && \
    chown -R www-data:www-data /var/log/php82 /run/php-fpm

# Copy PHP-FPM and PHP configuration files
COPY ./conf/php-fpm.conf /etc/php82/php-fpm.conf
COPY ./conf/www.conf /etc/php82/php-fpm.d/www.conf
COPY ./conf/php.ini /etc/php82/php.ini

# Expose port 9000 for PHP-FPM
EXPOSE 9000

# Start PHP-FPM
CMD ["php-fpm82", "-F"]

