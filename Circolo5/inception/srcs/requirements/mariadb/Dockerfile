# Dockerfile for MariaDB

FROM alpine:3.18

# Install MariaDB
RUN apk update && apk add mariadb mariadb-client

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/log/mysql && \
    chown -R mysql:mysql /run/mysqld /var/log/mysql

# Copy custom configuration
COPY ./conf/my.cnf /etc/my.cnf

# Expose port 3306
EXPOSE 3306

# Start MariaDB
CMD ["mysqld", "--user=mysql", "--console"]

