- Copy .env from Desktop to inception/srcs/
- Copy ssl/ from Desktop to inception/srcs/requirements/nginx/conf/
- (Add IP address of VM to /etc/hosts on host machine if needed)

Explanations:

Explanation of Docker and docker-compose:
You should be able to explain how Docker isolates applications by running them in containers and how docker-compose simplifies the process of managing multiple containers through a single YAML configuration file.

Docker image with/without docker-compose: The difference lies in how Docker handles dependencies between containers. docker-compose allows you to orchestrate multiple containers, define networking, volumes, etc., in one file, which is harder when using Docker alone.

Benefits of Docker vs. VMs: Docker containers are more lightweight compared to VMs as they share the same OS kernel and don’t require a full guest OS for each instance, leading to faster start times and reduced resource usage.
