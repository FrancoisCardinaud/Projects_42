# Dockerfile for MariaDB
FROM alpine:3.18

# Install MariaDB and bash
RUN apk update && apk add mariadb mariadb-client nano bash gettext

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/log/mysql /var/lib/mysql /etc/mysql && \
    chown -R mysql:mysql /run/mysqld /var/log/mysql /var/lib/mysql /etc/mysql

# Remove the default configuration file and copy custom configuration
COPY /tools/ /tmp/
COPY ./conf/my.cnf /my.cnf.tmpl
RUN chmod 744 /my.cnf.tmpl
RUN mv /my.cnf.tmpl /etc/mysql/my.cnf
COPY ./conf/tmpl.sql /tmpl.sql
COPY ./tools/start.sh /start.sh

# Make sure the start script is executable
RUN chmod +x /start.sh

# Expose port 3306
EXPOSE 3306

# Start MariaDB
ENTRYPOINT ["bash", "/tmp/start.sh"]

