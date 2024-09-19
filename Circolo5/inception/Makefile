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
	@echo "  setup           - Prepare directories and permissions for data storage"
	@echo "  up              - Build and start Docker containers"
	@echo "  down            - Stop Docker containers"
	@echo "  clean           - Stop containers and remove all data"
	@echo "  restart         - Restart Docker containers and volumes"
	@echo "  logs            - View the logs of all services"
	@echo "  shell-nginx     - Execute a shell in the nginx container"
	@echo "  shell-wordpress - Execute a shell in the wordpress container"
	@echo "  shell-mariadb   - Execute a shell in the mariadb container"
	@echo ""
	@echo "Before launching, change the value of USER_LOGIN in srcs/.env"
	@echo ""

# Setup target to create necessary directories and set permissions
setup:
	@echo "Setting up directories..."
	@mkdir -p /home/$(USER_LOGIN)/data/wordpress
	@mkdir -p /home/$(USER_LOGIN)/data/mariadb
	@chown -R $(USER_LOGIN):$(USER_LOGIN) /home/$(USER_LOGIN)/data/mariadb
	@chown -R $(USER_LOGIN):$(USER_LOGIN) /home/$(USER_LOGIN)/data/wordpress
	@chmod -R 755 /home/$(USER_LOGIN)/data/mariadb
	@chmod -R 755 /home/$(USER_LOGIN)/data/wordpress
	@echo "Setup complete."

# Default target: Build and start the containers
up: setup
	@echo "Starting Docker containers..."
	@$(DOCKER_COMPOSE) up -d --build
	@echo "Containers are up and running."

# Remove the containers and network
down:
	@echo "Stopping Docker containers..."
	@$(DOCKER_COMPOSE) down
	@echo "Containers stopped."

# Restart containers
restart: down up

# Remove the containers, network, and volumes
clean:
	@echo "Stopping and removing containers, networks, and volumes..."
	@$(DOCKER_COMPOSE) down -v
	@echo "Cleaning up data..."
	@docker system prune -a --volumes -f
	@sudo rm -rf /home/$(USER_LOGIN)/data/wordpress/*
	@sudo rm -rf /home/$(USER_LOGIN)/data/mariadb/*
	@echo "Cleanup complete."

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

