# Dockerfile for NGINX with TLS

FROM alpine:latest

# Install NGINX and OpenSSL
RUN apk update && apk add nginx openssl

# Copy NGINX configuration
COPY ./conf /etc/nginx

# Expose port 443
EXPOSE 443

# Start NGINX
CMD ["nginx", "-g", "daemon off;"]
