# Makefile for managing the Docker Compose project

# Variables
COMPOSE_FILE = docker-compose.yml

# Default target
.PHONY: all
all: up

# Build the Docker images
.PHONY: build
build:
	docker-compose -f $(COMPOSE_FILE) build

# Bring up the services
.PHONY: up
up:
	docker-compose -f $(COMPOSE_FILE) up -d

# Stop the services
.PHONY: down
down:
	docker-compose -f $(COMPOSE_FILE) down

# Stop and remove containers, networks, images, and volumes
.PHONY: clean
clean:
	docker-compose -f $(COMPOSE_FILE) down -v

# Rebuild and start fresh
.PHONY: rebuild
rebuild: clean build up

# View logs
.PHONY: logs
logs:
	docker-compose -f $(COMPOSE_FILE) logs -f

# Restart services
.PHONY: restart
restart:
	docker-compose -f $(COMPOSE_FILE) restart

# Execute a shell in the WordPress container
.PHONY: shell
shell:
	docker-compose -f $(COMPOSE_FILE) exec wordpress /bin/sh

