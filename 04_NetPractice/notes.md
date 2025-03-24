
Subnet Mask and CIDR Notation

	Subnet Mask			CIDR	Binary Representation								Host Bits		Number of Hosts per Network
	255.255.255.0		/24		1111 1111 . 1111 1111 . 1111 1111 . 0000 0000		8				2^8 = 256
	255.255.255.128		/25		1111 1111 . 1111 1111 . 1111 1111 . 1000 0000		7				2^7 = 128
	255.255.255.192		/26		1111 1111 . 1111 1111 . 1111 1111 . 1100 0000		6				2^6 = 64
	255.255.255.224		/27		1111 1111 . 1111 1111 . 1111 1111 . 1110 0000		5				2^5 = 32
	255.255.255.240		/28		1111 1111 . 1111 1111 . 1111 1111 . 1111 0000		4				2^4 = 16
	255.255.255.248		/29		1111 1111 . 1111 1111 . 1111 1111 . 1111 1000		3				2^3 = 8
	255.255.255.252		/30		1111 1111 . 1111 1111 . 1111 1111 . 1111 1100		2				2^2 = 4
	255.255.255.254		/31		1111 1111 . 1111 1111 . 1111 1111 . 1111 1110		1				2^1 = 2
	255.255.255.255		/32		1111 1111 . 1111 1111 . 1111 1111 . 1111 1111		0				2^0 = 1

Hosts and Network/Broadcast Addresses

	Network Address:	All host bits are set to 0.
	Broadcast Address:	All host bits are set to 1.

Key Protocols

	IP (Internet Protocol): Responsible for addressing and routing packets.
	TCP (Transmission Control Protocol): Provides reliable, ordered, and error-checked delivery of data.
	TCP/IP: A suite of communication protocols used to interconnect network devices on the internet.

CIDR (Classless Inter-Domain Routing)

	CIDR: A method for allocating IP addresses and IP routing that replaces the older system based on classes A, B, and C.
	CIDR notation specifies an IP address and its associated network mask (e.g., 192.168.1.0/24).

IP Versions

	IPv4:	32-bit address space, allowing for 2^32 (4,294,967,296) unique addresses.
			Structure: Four octets (8 bits each) ranging from 0 to 255.
	IPv6:	128-bit address space, allowing for 2^128 (340,282,366,920,938,463,463,374,607,431,768,211,456) unique addresses.
			Structure: Eight hextets (16 bits each) of four hexadecimal digits ranging from 0 to f.

Reserved IP Ranges

	These IP ranges are reserved for specific purposes and are not used on the public internet:
	Private IP Ranges:
		10.0.0.0	-	10.255.255.255:		Private network
		172.16.0.0	- 	172.31.255.255:		Private network
		192.168.0.0	-	192.168.255.255:	Private network
	Loopback Range:
		127.0.0.0	-	127.255.255.255: 	Used for loopback addresses to the local host (most commonly 127.0.0.1)
