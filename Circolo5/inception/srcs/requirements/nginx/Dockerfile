FROM alpine:3.19

# Install NGINX and OpenSSL
RUN apk add nginx openssl nano curl bash

# Remove default configuration to avoid conflicts
RUN rm -rf /etc/nginx/*

# Copy your custom NGINX configuration
COPY /tools/ /tmp/
RUN mkdir -p /etc/nginx
RUN chmod -R 755 /etc/nginx
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/fastcgi_params /etc/nginx/fastcgi_params
RUN chmod 644 /etc/nginx/nginx.conf

# Create the SSL directory and copy the SSL certificates
RUN mkdir -p /etc/nginx/ssl
COPY ./conf/mime.types /etc/nginx/mime.types
COPY ./conf/ssl/certificate.crt /etc/nginx/ssl/certificate.crt
COPY ./conf/ssl/private.key /etc/nginx/ssl/private.key

# Expose ports for HTTP and HTTPS traffic
EXPOSE 80 443

# Start NGINX
ENTRYPOINT ["bash","/tmp/start.sh"]
