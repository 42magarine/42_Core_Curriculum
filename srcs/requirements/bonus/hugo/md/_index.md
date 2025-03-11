+++
title = '42 Inception'
date = 2025-01-01T00:00:00Z
draft = true
+++





1. How Docker and docker compose work
...

2. The difference between a Docker image used with docker compose and without docker
compose
...

3. The benefit of Docker compared to VMs
...

4. docker netzwerk, was ist briged? welche anderen arten von docker netzwerken gibt es noch?
Simple explanation of docker-network. warum binden wir alle container auf 0.0.0.0 im docker netzwerk?


Quellen:
1. Install Docker Engine on Ubuntu
    1.1. Install using the apt repository
        https://docs.docker.com/engine/install/ubuntu/#install-using-the-repository

    1.2. Manage Docker as a non-root user
        https://docs.docker.com/engine/install/linux-postinstall/#manage-docker-as-a-non-root-user

2. How to use secrets in Docker Compose
    https://docs.docker.com/compose/how-tos/use-secrets/




# Usage: docker [OPTIONS] COMMAND
# Commands:
    # build     Build an image from a Dockerfile
    # run       Create and run a new container from an image
    # start     Start one or more stopped containers
    # stop      Stop one or more running containers
    # exec      Execute a command in a running container
    # images    List images
    # ps        List containers
    # rm        Remove one or more containers
    # rmi       Remove one or more images

# Usage: docker buildx build [OPTIONS] PATH | URL | -
# Options:
    # -f, --file string        Name of the Dockerfile (default: "PATH/Dockerfile")
    # -t, --tag stringArray    Name and optionally a tag (format: "name:tag")

# Usage: docker run [OPTIONS] IMAGE [COMMAND] [ARG...]
# Options:
    # -d, --detach          Run container in background and print container ID
    # -i, --interactive     Keep STDIN open even if not attached
    # --name string         Assign a name to the container
    # -p, --publish list    Publish a container's port(s) to the host
    # --rm                  Automatically remove the container and its associated anonymous volumes when it exits
    # -t, --tty             Allocate a pseudo-TTY
    # -v, --volume list     Bind mount a volume



Begründung für die Reihenfolge
    services
    volumes
    networks
    secrets

Begründung der Reihenfolge
    Grundlegende Definitionen
        container_name: Falls ein fester Name gewünscht ist
        image: Entweder direkt ein Image oder build-Anweisung
        build: Falls das Image selbst gebaut wird
    Startverhalten
        entrypoint: Falls der Standard-Entrypoint überschrieben wird
        command: Falls das Standardkommando überschrieben wird
        restart: Falls das Container-Neustartverhalten definiert wird
    Abhängigkeiten
        depends_on: Falls andere Container zuerst gestartet werden müssen
    Umgebungsvariablen und Konfiguration
        environment: Direkt definierte Variablen
        env_file: Falls eine .env-Datei geladen wird
    Netzwerk und Volumes
        ports: Falls Ports gemappt werden
        volumes: Falls Daten persistiert oder Dateien eingebunden werden
        networks: Falls der Container Teil eines Netzwerks ist
    Zusätzliche Einstellungen
        extra_hosts: Falls eine benutzerdefinierte /etc/hosts-Einträge nötig sind
        dns: Falls spezielle DNS-Server genutzt werden sollen
        labels: Falls Labels für Orchestrierung oder Logging definiert werden
    Monitoring & Sicherheit
        healthcheck: Falls ein Gesundheitscheck definiert wird
        secrets: Falls geheime Daten genutzt werden
        configs: Falls zusätzliche Konfigurationsdateien eingebunden werden
    Logging
        logging: Falls das Logging-Verhalten konfiguriert werden soll
