FROM alpine:3.18

# Install NGINX and OpenSSL
RUN apk update && apk add --no-cache nginx openssl

# Remove default configuration to avoid conflicts
RUN rm -rf /etc/nginx/conf.d/*

# Copy your custom NGINX configuration
COPY ./conf/nginx.conf /root/etc/nginx/nginx.conf

# Create the SSL directory and copy the SSL certificates
COPY ./conf/ssl /root/etc/nginx/ssl

# Expose ports for HTTP and HTTPS traffic
EXPOSE 80 443

# Start NGINX
CMD ["nginx", "-g", "daemon off;"]

