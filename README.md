# 42_Inception

# Standard configuration files #
docker cp nginx:/etc/nginx/nginx.conf ./srcs/requirements/nginx/conf/.
docker cp nginx:/etc/nginx/http.d/default.conf ./srcs/requirements/nginx/conf/.
docker cp wordpress:/etc/php83/php-fpm.d/www.conf ./srcs/requirements/wordpress/conf/.
docker cp ftp:/etc/vsftpd/vsftpd.conf ./srcs/requirements/bonus/ftp/conf/.
docker cp redis:/etc/redis.conf ./srcs/requirements/bonus/redis/conf/.


sudo nano /etc/hosts
127.0.0.1 mott.42.fr
127.0.0.1 www.mott.42.fr

# mysql -u root -p"${DB_ROOT_PASSWORD}"
# mysql -u "${DB_USER}" -p"${DB_USER_PASSWORD}"
# SHOW DATABASES;
# USE Inception;

# DROP DATABASE IF EXISTS test;
# DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';

# SELECT Host, User, Password FROM mysql.user;

# FTP Server #
/etc/vsftpd/vsftpd.conf
https://manpages.ubuntu.com/manpages/noble/en/man5/vsftpd.conf.5.html



Der Name Redis entstand als Abkürzung für englisch remote dictionary server

sh % redis-cli -h localhost -p 6379

docker exec -it redis redis-cli
MONITOR -
INFO
KEYS *

Adminer Login-Daten (im Browser eintragen)

Wenn du im Browser auf http://localhost/adminer.php gehst, musst du diese Daten eingeben:

    Server: mariadb (Name des MariaDB-Containers im Docker-Netzwerk!)
    Benutzer: wpuser
    Passwort: wppassword
    Datenbank: wordpress




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


# Usage: docker start [OPTIONS] CONTAINER [CONTAINER...]
# Options:
    # -i, --interactive    Attach container's STDIN


# Usage: docker stop [OPTIONS] CONTAINER [CONTAINER...]


# Usage: docker exec [OPTIONS] CONTAINER COMMAND [ARG...]
# Options:


# Usage: docker images [OPTIONS] [REPOSITORY[:TAG]]
# Options:
    # -a, --all    Show all images (default hides intermediate images)


# Usage: docker ps [OPTIONS]
# Options:
    # -a, --all    Show all containers (default shows just running)


# Usage: docker rm [OPTIONS] CONTAINER [CONTAINER...]
# Options:
    # -f, --force    Force the removal of a running container (uses SIGKILL)


# Usage: docker rmi [OPTIONS] IMAGE [IMAGE...]
# Options:
    # -f, --force    Force removal of the image


Begründung für die Reihenfolge

    version (falls vorhanden) kommt als erstes.
    services ist der wichtigste Teil, da hier die Container definiert werden.
        container_name, image, build → Diese kommen zuerst, weil sie grundlegend sind.
        restart, depends_on → Logische Steuerung des Containers.
        environment, ports, volumes, networks → Konfiguration des Containers.
        healthcheck, logging → Monitoring und Logging.
    volumes → Nach den Services, damit klar ist, welche Volumes global definiert sind.
    networks → Am Ende, um Netzwerktopologie zu strukturieren.
    secrets / configs → Falls benötigt, dann nach networks.


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
