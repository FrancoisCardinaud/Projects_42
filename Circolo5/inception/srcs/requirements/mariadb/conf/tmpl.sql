-- Create the WordPress user if it doesn't already exist
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';

-- Grant all privileges on the WordPress database to the WordPress user
GRANT ALL PRIVILEGES ON `${WP_DATABASE}`.* TO '${MYSQL_USER}'@'%';

-- Grant all privileges on the WordPress database to the root user
GRANT ALL PRIVILEGES ON `${WP_DATABASE}`.* TO 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}' WITH GRANT OPTION;

-- Allow the root user to create other users
GRANT ALL PRIVILEGES ON *.* TO 'root'@'%' WITH GRANT OPTION;

-- Update the root user's password
ALTER USER 'root'@'%' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

-- Flush privileges to ensure all changes take effect
FLUSH PRIVILEGES;

