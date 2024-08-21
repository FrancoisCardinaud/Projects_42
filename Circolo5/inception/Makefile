# Makefile for Docker operations

# Define variables from the .env file
include srcs/.env

# Define the path to the docker-compose file
DOCKER_COMPOSE = docker-compose -f srcs/docker-compose.yml --env-file srcs/.env

# Help target to display usage information
help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  setup    - Prepare directories and permissions for data storage"
	@echo "  up       - Build and start Docker containers"
	@echo "  down     - Stop Docker containers"
	@echo "  clean    - Stop containers and remove all data"
	@echo "  restart  - Restart Docker containers"
	@echo ""
	@echo "Before launching, change the value of USER_LOGIN in srcs/.env"
	@echo "Also, add the line 127.0.0.1 fcardina.42.it to host machine /etc/hosts"
	@echo ""

# Setup target to create necessary directories and set permissions
setup:
#	@sudo hostsed add 127.0.0.1 fcardina.42.fr && echo "fcardina.42.fr added to /etc/hosts"
	@echo "Setting up directories..."
	@sudo mkdir -p /home/$(USER_LOGIN)/data/wordpress || true
	@sudo mkdir -p /home/$(USER_LOGIN)/data/mariadb || true
	@sudo chown -R $(USER_LOGIN):$(USER_LOGIN) /home/$(USER_LOGIN)/data/mariadb || true
	@sudo chown -R $(USER_LOGIN):$(USER_LOGIN) /home/$(USER_LOGIN)/data/wordpress || true
	@sudo chmod -R 755 /home/$(USER_LOGIN)/data/mariadb || true
	@sudo chmod -R 755 /home/$(USER_LOGIN)/data/wordpress || true
	@echo "Setup complete."

# Default target: Build and start the containers
up: setup
	@echo "Starting Docker containers..."
	@$(DOCKER_COMPOSE) up -d --build
	@echo "Containers are up and running."

# Remove the containers and network
down:
	@echo "Stopping Docker containers, removing volumes..."
	@$(DOCKER_COMPOSE) down --rmi all -v
	@echo "Containers stopped."

# Remove the containers, network, and volumes
clean: down
	@echo "Cleaning up data..."
	@sudo rm -rf /home/$(USER_LOGIN)/data/wordpress/*
	@sudo rm -rf /home/$(USER_LOGIN)/data/mariadb/*
	@echo "Cleanup complete."

# More thorough cleanup 
fclean: clean
#	@sudo hostsed rm 127.0.0.1 fcardina.42.fr && echo "fcardina.42.fr removed from /etc/hosts"
	@if [ -d "/home/$(USER_LOGIN)/data/wordpress" ]; then \
	sudo rm -rf /home/$(USER_LOGIN)/data/wordpress/* && \
	echo "Removed all local contents from /home/USER_LOGIN/data/wordpress/"; \
	fi;

	@if [ -d "/home/fcardina/data/mariadb" ]; then \
	sudo rm -rf /home/fcardina/data/mariadb/* && \
	echo "Removed all local contents from /home/USER_LOGIN/data/mariadb/"; \
	fi;

# Restart containers
restart: fclean up

# View the logs of all services
logs:
	@$(DOCKER_COMPOSE) logs -f

# Execute a shell in the nginx container
shell-nginx:
	@$(DOCKER_COMPOSE) exec nginx sh

# Execute a shell in the wordpress container
shell-wordpress:
	@$(DOCKER_COMPOSE) exec wordpress sh

# Execute a shell in the mariadb container
shell-mariadb:
	@$(DOCKER_COMPOSE) exec mariadb sh

.PHONY: help up down clean logs shell-nginx shell-wordpress shell-mariadb restart

