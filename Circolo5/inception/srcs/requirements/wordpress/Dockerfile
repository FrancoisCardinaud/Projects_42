# Dockerfile for WordPress with PHP-FPM

FROM alpine:latest

# Install PHP and PHP-FPM
RUN apk update && apk add php7 php7-fpm php7-mysqli

# Copy PHP-FPM configuration
COPY ./conf /etc/php7

# Expose port 9000
EXPOSE 9000

# Start PHP-FPM
CMD ["php-fpm7", "-F"]
