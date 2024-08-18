# IF wordpress DB is not created, then create it ...
## WAIT FOR MARIADB TO BE READY
## CREATE THE USERS FOR THE DATABASE
## CREATE THE ADMIN USER FOR THE DATABASE

set -x

#ADMIN_USER=pancho
#ADMIN_PASSWORD=villa
#ADMIN_EMAIL=pvilla@gmail.com
#WP_TITLE=pulga_site
#WP_URL=https://$DOMAIN_NAME
#WP_USER_LOGIN=arosado-
#WP_USER_EMAIL=arosado@student.pt
#WP_USER_PASS=pass123

while [ ! -e /var/www/html/wordpress/ ]
do
	sleep 1;
done

sleep 5;

cd /var/www/html/wordpress

if ! wp core is-installed --allow-root; then
	# create admin
	wp core install --allow-root \
	--url=https://${WP_URL} \
	--title=${WP_TITLE} \
	--admin_user=${WP_ADMIN_USER} \
	--admin_password=${WP_ADMIN_PASSWORD} \
	--admin_email=${WP_ADMIN_EMAIL} \
	#create user
	wp user create --allow-root \
		${WP_USER} \
		${WP_USER_EMAIL} \
		--role=author \
		--user_pass=${WP_USER_PASSWORD}
fi

# Config php.ini
sed -i "s/memory_limit = .*/memory_limit = 256M/" /etc/php/8.2/fpm/php.ini
sed -i "s/upload_max_filesize = .*/upload_max_filesize = 128M/" /etc/php/8.2/fpm/php.ini
sed -i "s/zlib.output_compression = .*/zlib.output_compression = on/" /etc/php/8.2/fpm/php.ini
sed -i "s/max_execution_time = .*/max_execution_time = 18000/" /etc/php/8.2/fpm/php.ini

#service php8.2-fpm start
#service php8.2-fpm stop
php-fpm8.2 -F -R
