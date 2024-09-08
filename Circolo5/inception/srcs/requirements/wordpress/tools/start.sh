#!/bin/sh

set -x

# Wait for MariaDB to be ready before proceeding
while ! mysql -h"$WP_HOST" -u"$WP_USER" -p"$WP_USER_PASSWORD" -e "SELECT 1" > /dev/null 2>&1;
do
  echo "Waiting for MariaDB to be ready..."
  sleep 7
done

# Check if the WordPress database exists, if not create it
if ! mysql -h mariadb -u root -p${MYSQL_ROOT_PASSWORD} -e "USE ${WP_DATABASE};" 2>/dev/null; then
  echo "Creating WordPress database and user..."
  mysql -h mariadb -u root -p${MYSQL_ROOT_PASSWORD} <<EOF
CREATE DATABASE IF NOT EXISTS ${WP_DATABASE};

-- Create the 'fcardina' user (admin for WordPress)
CREATE USER IF NOT EXISTS 'fcardina'@'%' IDENTIFIED BY '${FCARDINA_PASSWORD}';
GRANT ALL PRIVILEGES ON ${WP_DATABASE}.* TO 'fcardina'@'%';

-- Create the 'user' (regular WordPress user)
CREATE USER IF NOT EXISTS 'user'@'%' IDENTIFIED BY '${WP_USER_PASSWORD}';
REVOKE ALL PRIVILEGES ON ${WP_DATABASE}.* FROM 'user'@'%';
GRANT SELECT, INSERT, UPDATE, DELETE ON ${WP_DATABASE}.* TO 'user'@'%';

-- Configure 'root' user
GRANT ALL PRIVILEGES ON ${WP_DATABASE}.* TO 'root'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
EOF
fi

# Wait until WordPress files are ready
while [ ! -e /var/www/html/wordpress/ ]; do
  sleep 1;
done

sleep 5;

cd /var/www/html/wordpress

# Check if WordPress is already installed, if not, install it
if ! wp core is-installed --allow-root; then
  echo "Installing WordPress..."
  wp core install --allow-root \
    --url=${WP_URL} \
    --title=${WP_TITLE} \
    --admin_user=${WP_ADMIN_USER} \
    --admin_password=${WP_ADMIN_PASSWORD} \
    --admin_email=${WP_ADMIN_EMAIL}
  
  echo "Creating additional WordPress user..."
  wp user create --allow-root \
    ${WP_USER} \
    ${WP_USER_EMAIL} \
    --role=author \
    --user_pass=${WP_USER_PASSWORD}
fi

# Configure PHP settings
sed -i "s/memory_limit = .*/memory_limit = 256M/" /etc/php82/fpm/php.ini
sed -i "s/upload_max_filesize = .*/upload_max_filesize = 128M/" /etc/php82/fpm/php.ini
sed -i "s/zlib.output_compression = .*/zlib.output_compression = on/" /etc/php82/fpm/php.ini
sed -i "s/max_execution_time = .*/max_execution_time = 18000/" /etc/php82/fpm/php.ini

if pgrep php-fpm82 > /dev/null; then
    echo "PHP-FPM is already running."
    exit 0
fi

# Start PHP-FPM
php-fpm82 --fpm-config /etc/php82/fpm/php-fpm.conf -F -R

