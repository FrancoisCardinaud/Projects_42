# Dockerfile for MariaDB

FROM alpine:3.18

# Install MariaDB
RUN apk update && apk add mariadb mariadb-client

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/log/mysql /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld /var/log/mysql /var/lib/mysql

# Initialize the MariaDB data directory
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Copy custom configuration
COPY ./conf/my.cnf /etc/my.cnf

# Expose port 3306
EXPOSE 3306

# Initialize the database
RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

# Start MariaDB
CMD ["mysqld", "--user=mysql", "--console"]

