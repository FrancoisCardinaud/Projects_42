#!/bin/sh

SETUP='/init.sql'

# Check if database `mysql` has already been created
if [ ! -d "/var/lib/mysql/mysql" ]; then

    # Initialize the MySQL database tables
    echo "Installing MariaDB for the first time"
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

    # Set the root password during the first-time setup
    echo "Setting root password"
    mysqld --skip-networking --user=mysql --datadir="/var/lib/mysql" &
    sleep 5
    mysql -u root <<-EOF
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    FLUSH PRIVILEGES;
EOF
    killall mysqld
fi

# Hydrate configuration template with environment variables
echo "Setup initial file with env variables"
cat tmpl.sql | envsubst > ${SETUP}

# Debugging: Output the generated SQL script
#echo "Generated SQL script:"
#cat ${SETUP}

# Start the MySQL daemon with the initialization SQL file
echo "Start mysql daemon to receive arguments"
exec mysqld --user=mysql --datadir="/var/lib/mysql" --port=3306 --init-file ${SETUP} $@
