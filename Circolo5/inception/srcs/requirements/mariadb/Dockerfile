# Dockerfile for MariaDB

FROM alpine:latest

# Install MariaDB
RUN apk update && apk add mariadb mariadb-client

# Copy MariaDB configuration
COPY ./conf /etc/mysql

# Expose port 3306
EXPOSE 3306

# Start MariaDB
CMD ["mysqld"]
