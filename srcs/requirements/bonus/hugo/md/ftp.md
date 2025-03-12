+++
title = "FTP"
date = 2025-01-01T00:00:00Z
draft = true
+++

### FTP (File Transfer Protocol) Docker Container

> An FTP server allows file transfers between clients and a server using the File Transfer Protocol (FTP). One of the most popular FTP servers is **VSFTPD** (Very Secure FTP Daemon), known for its security features.

> - **Port 21**: Used for command (control) communication between client and server.
> - **Port 20**: Used for data transfer in **Active Mode** (server connects to client).
> - **Passive Ports**: A range of ports above 1024 used for data transfer in **Passive Mode** (client connects to server).



#### Access:
```sh
ftp $FTP_USER@$DOMAIN_NAME 21
```



#### Common FTP Commands:
```sh
ls                  # List files in the current directory
pwd                 # Print working directory
cd <dirname>        # Change directory
lcd </path/>        # Change local directory

get <filename>      # Download file
put <filename>      # Upload file

mkdir <dirname>     # Create new directory
rmdir <dirname>     # Remove directory
delete <filename>   # Delete file

bye                 # Close the FTP connection
```



#### Configuration:
* [VSFTPD Configuration Manual](https://manpages.ubuntu.com/manpages/noble/en/man5/vsftpd.conf.5.html)
* VSFTPD config: `/etc/vsftpd/vsftpd.conf`
