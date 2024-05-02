"""
Write a function to interact with the network to abstract multiple scapy functions
"""

from scapy.all import *
from ipaddress import ip_address
from socket import socket

# TODO : Receive function
# TODO : Transmit function
# TODO : Tunnel function (more research required)

def get_ip_address() -> str :
    try:
        # Create a socket
        s = socket(socket.AF_INET, socket.SOCK_DGRAM)
        # Connect to a remote server (doesn't matter which one)
        s.connect(("8.8.8.8", 80))
        # Get the local IP address from socket
        ip = s.getsockname()[0]
        return ip
    except Exception as e:
        print("(!) Error occurred while retrieving IP address:", e)
        return str()

# Craft layer 3 packet with your buffer as payload
def transmit (ip:str, data:bin) -> None:
    ip_address(ip) # raise ValueError
    packet = IP(dst=ip) / Raw(load=data)
    send(packet)

def receive (ip:str, count:int=1) -> list:
    TOWARDS_DESTINATION = f"src host {ip}"
    FOR_ME = f"dst host {get_ip_address()}"
    value = TOWARDS_DESTINATION + " and " + FOR_ME
    return sniff(filter=value, count=count)

