# Makefile for Docker operations


# Define the path to the docker-compose file
DOCKER_COMPOSE = docker-compose -f srcs/docker-compose.yml --env-file srcs/.env

# Default target: Build and start the containers
up: build
	@$(DOCKER_COMPOSE) up -d

# Build the Docker images
build:
	@$(DOCKER_COMPOSE) build

# Stop the containers
stop:
	@$(DOCKER_COMPOSE) stop

# Remove the containers and network
down:
	@$(DOCKER_COMPOSE) down

# Remove the containers, network, and volumes
clean:
	@$(DOCKER_COMPOSE) down -v

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

# Restart the services
restart: stop up

.PHONY: up build stop down clean logs shell-nginx shell-wordpress shell-mariadb restart

