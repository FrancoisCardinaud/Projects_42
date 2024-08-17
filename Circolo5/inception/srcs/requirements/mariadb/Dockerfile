# Dockerfile for MariaDB

FROM debian:buster

# Environment variables for database configuration
ARG DB_NAME=${DB_NAME}
ARG DB_USER=${DB_USER}
ARG DB_PASSWORD=${DB_PASSWORD}
ARG DB_ROOT_PASSWORD=${DB_ROOT_PASSWORD}

# Install MariaDB and bash
RUN apt-get update && apt-get install mariadb-server -y && apt-get install bash
#    apk add mariadb mariadb-client

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/log/mysql /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld /var/log/mysql /var/lib/mysql

# Remove the default configuration file and copy custom configuration
COPY conf/my.cnf /etc/mysql/my.cnf

# Copy custom script for user creation and database setup
COPY tools/user_creation.sh /usr/local/bin/user_creation.sh

# Make sure the script is executable
RUN chmod +x /usr/local/bin/user_creation.sh

# Initialize the MariaDB data directory
#RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql

#COPY tools/user_creation.sh /
#RUN bash ./user_creation.sh

#RUN rm -rf user_creation.sh
# Run the script to initialize the database and create users
RUN /usr/local/bin/user_creation.sh

RUN rm -rf /usr/local/bin/user_creation.sh

# Expose port 3306
EXPOSE 3306

# Start MariaDB
CMD ["mysqld_safe", "--user=mysql", "--console"]

