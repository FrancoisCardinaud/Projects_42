
#!/bin/bash

#service mysql start

# Wait for MariaDB to start
#sleep 5

mysql -u root <<EOF
CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;
CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}' WITH GRANT OPTION;
UPDATE mysql.user SET password=password('$MARIADB_ROOT_PASS') WHERE user='root';
FLUSH PRIVILEGES;
EOF


