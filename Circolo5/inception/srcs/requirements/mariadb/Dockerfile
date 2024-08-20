# Dockerfile for MariaDB

FROM alpine:3.18

# Environment variables for database configuration
#ARG DB_NAME=${MYSQL_DATABASE}
#ARG DB_USER=${MYSQL_USER}
#ARG DB_PASSWORD=${MYSQL_PASSWORD}
#ARG DB_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}

# Install MariaDB and bash
RUN apk update && apk add mariadb mariadb-client nano bash gettext
#    apk add mariadb mariadb-client

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/log/mysql /var/lib/mysql /etc/mysql && \
    chown -R mysql:mysql /run/mysqld /var/log/mysql /var/lib/mysql /etc/mysql

# Remove the default configuration file and copy custom configuration
COPY ./conf/my.cnf /my.cnf.tmpl
RUN chmod 744 /my.cnf.tmpl
RUN mv /my.cnf.tmpl /etc/mysql/my.cnf
COPY ./conf/tmpl.sql /tmpl.sql
COPY ./tools/start.sh /start.sh

# Copy custom script for user creation and database setup
#COPY tools/user_creation.sh /etc/mysql/user_creation.sh
RUN chmod +x /start.sh

# Initialize the MariaDB data directory
#RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

#COPY tools/user_creation.sh /
#RUN bash ./user_creation.sh

#RUN rm -rf user_creation.sh
# Run the script to initialize the database and create users
#RUN /etc/mysql/user_creation.sh

#RUN rm -rf /etc/mysql/user_creation.sh

VOLUME [ "/sys/fs/cgroup" ]

# Expose port 3306
EXPOSE 3306

ENTRYPOINT [ "bash", "/start.sh" ]
# Start MariaDB
#CMD ["mysqld_safe", "--user=mysql", "--console"]

