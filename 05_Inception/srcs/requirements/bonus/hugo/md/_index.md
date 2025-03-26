+++
title = '42 Inception'
date = 2025-01-01T00:00:00Z
draft = true
+++

### Docker
> Docker is an open platform for developing, shipping, and running applications.
> Docker enables you to separate your applications from your infrastructure so you can deliver software quickly.


#### Docker and Docker Compose
* Docker uses a client-server architecture. The Docker client talks to the Docker daemon, which does the heavy lifting of building, running, and distributing your Docker containers.
* Docker Compose is another Docker client, that lets you work with applications consisting of a set of containers.
* With Docker Compose you use a YAML configuration file to configure your application’s services, and then you create and start all the services from your configuration with the Compose CLI.

    https://docs.docker.com/reference/compose-file/services/#attributes


#### Dockerfile
* It all starts with a Dockerfile.
* A text file containing instructions for building your source code.


#### Docker Image
* Docker builds images by reading the instructions from a Dockerfile.
* A read-only template with instructions for creating a Docker container.


#### Docker Container
* A runnable instance of an image.
* By default, a container is well isolated from other containers and its host machine.
* It is defined by its image as well as any configuration options you provide to it when you create or start it.


#### Docker Networking
* The following network drivers are available:
  * bridge  The default network driver.
  * host    Remove network isolation between the container and the Docker host.
  * none    Completely isolate a container from the host and other containers.

> In terms of Docker, a bridge network uses a software bridge which lets containers connected to the same bridge network communicate, while providing isolation from containers that aren't connected to that bridge network.


#### Difference between Containers and VMs
* Containers: Lightweight, share the host OS kernel, fast startup.
* VMs: Full OS virtualization, higher resource consumption.
* Docker Benefits:
  * Faster deployment.
  * Less resource-intensive.
  * Easier dependency management.


#### Common Docker/Docker Compose Commands:

##### Docker
* <kbd>`build`</kbd> Build an image from a Dockerfile
* <kbd>`cp`</kbd> Copy files/folders between a container and the local filesystem
* <kbd>`exec`</kbd> Run a command in a running container
* <kbd>`images`</kbd> List images
* <kbd>`inspect`</kbd> Return low-level information on Docker objects
* <kbd>`logs`</kbd> Fetch the logs of a container
* <kbd>`ps`</kbd> List containers
* <kbd>`restart`</kbd> Restart one or more containers
* <kbd>`rm`</kbd>  Remove one or more containers
* <kbd>`rmi`</kbd> Remove one or more images
* <kbd>`run`</kbd> Run a command in a new container
* <kbd>`start`</kbd> Start one or more stopped containers
* <kbd>`stop`</kbd> Stop one or more running containers

##### Docker Compose
* <kbd>`build`</kbd> Build or rebuild services
* <kbd>`cp`</kbd> Copy files/folders between a service container and the local filesystem
* <kbd>`down`</kbd> Stop and remove containers, networks
* <kbd>`exec`</kbd> Execute a command in a running container.
* <kbd>`images`</kbd> List images used by the created containers
* <kbd>`logs`</kbd> View output from containers
* <kbd>`ls`</kbd> List running compose projects
* <kbd>`ps`</kbd> List containers
* <kbd>`restart`</kbd> Restart containers
* <kbd>`rm`</kbd> Removes stopped service containers
* <kbd>`run`</kbd> Run a one-off command on a service.
* <kbd>`start`</kbd> Start services
* <kbd>`stop`</kbd> Stop services
* <kbd>`up`</kbd> Create and start containers


#### Useful Links:
* [Docker Docs](https://docs.docker.com/)
* [What is Docker?](https://docs.docker.com/get-started/docker-overview/)
* [Install Docker Engine on Ubuntu using the apt repository](https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository)
* [Manage Docker as a non-root user](https://docs.docker.com/engine/install/linux-postinstall/#manage-docker-as-a-non-root-user)
* [How to use secrets in Docker Compose](https://docs.docker.com/compose/how-tos/use-secrets/)
