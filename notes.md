
Subnet Mask		CIDR	Binary
255.255.255.0	/24		1111 1111 . 1111 1111 . 1111 1111 . 0000 0000		8 bits for hosts		2^8 = 256er networks
255.255.255.128	/25		1111 1111 . 1111 1111 . 1111 1111 . 1000 0000		7 bits for hosts		2^7 = 128er	networks
255.255.255.192	/26		1111 1111 . 1111 1111 . 1111 1111 . 1100 0000		6 bits for hosts		2^6 = 64er	networks
255.255.255.224	/27		1111 1111 . 1111 1111 . 1111 1111 . 1110 0000		5 bits for hosts		2^5 = 32er	networks
255.255.255.240	/28		1111 1111 . 1111 1111 . 1111 1111 . 1111 0000		4 bits for hosts		2^4 = 16er	networks
255.255.255.248	/29		1111 1111 . 1111 1111 . 1111 1111 . 1111 1000		3 bits for hosts		2^3 = 8er	networks
255.255.255.252	/30		1111 1111 . 1111 1111 . 1111 1111 . 1111 1100		2 bits for hosts		2^2 = 4er	networks
255.255.255.254	/31		1111 1111 . 1111 1111 . 1111 1111 . 1111 1110		1 bits for hosts		2^1 = 2er	networks
255.255.255.255	/32		1111 1111 . 1111 1111 . 1111 1111 . 1111 1111		0 bits for hosts		2^0 = 1er	networks

Hosts bits all to 0	=	Network address
Hosts bits all to 1	=	Broadcast address

IP			Internet Protocol
TCP			Transmission Control Protocol
TCP/IP		Transmission Control Protocol/Internet Protocol
CIDR		?

IPv4		32-bits		2^32	=	4.294.967.296
			4 x 8-bits from 0 to 255
IPv6		128-bits	2^128	=	340.282.366.920.938.463.463.374.607.431.768.211.456
			32 x 4-bits from 0 to f

Reserved IP ranges:
10.0.0.0	-	10.255.255.255		?
127.16.0.0	-	127.31.255.255		?
192.168.0.0	-	192.168.255.255		?
