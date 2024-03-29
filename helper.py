import socket
import ssl

def get_cmd(name,number):
    return f"raw.githubusercontent.com/coderuster/os/main/{number}/{name}"
def https_get(url):
    hostname, _, path = url.partition('/')
    if not path:
        path = '/'

    with socket.create_connection((hostname, 443)) as sock:
        context = ssl.create_default_context()
        with context.wrap_socket(sock, server_hostname=hostname) as ssock:
            request = f"GET {path} HTTP/1.1\r\nHost: {hostname}\r\nConnection: close\r\n\r\n"
            ssock.sendall(request.encode())

            response = b""
            while True:
                data = ssock.recv(4096)
                if not data:
                    break
                response += data
    body_start = response.find(b"\r\n\r\n") + len(b"\r\n\r\n")
    return response[body_start:].decode()

def run_command(cmd):
  try:
      data=https_get(cmd)
      return data
  except Exception as e:
    print(f"Error: {e}")
    return "ERROR"

def main():
    number=input("Enter the experiment number: ").strip()
    files=['a.c','b.sh','c.txt']
    for f in files:
        cmd=get_cmd(f,number)
        content=run_command(cmd)
        with open(f,"w") as file:
            file.write(content)
if __name__=="__main__":
    main()
