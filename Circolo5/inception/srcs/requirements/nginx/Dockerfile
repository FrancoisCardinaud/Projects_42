FROM alpine:3.18

# Install NGINX and OpenSSL
RUN apk update && apk add --no-cache nginx openssl && apk add curl

# Remove default configuration to avoid conflicts
RUN rm -rf /etc/nginx/conf.d/*

# Copy your custom NGINX configuration
COPY ./conf/nginx.conf /etc/nginx/nginx.conf
COPY ./conf/fastcgi_params /etc/nginx/fastcgi_params

# Create the SSL directory and copy the SSL certificates
RUN mkdir -p /etc/nginx/ssl
COPY ./conf/mime.types /etc/nginx/mime.types
COPY ./conf/ssl/certificate.crt /etc/nginx/ssl/certificate.crt
COPY ./conf/ssl/private.key /etc/nginx/ssl/private.key

# Expose ports for HTTP and HTTPS traffic
EXPOSE 80 443

# Start NGINX
CMD ["nginx", "-g", "daemon off;"]

