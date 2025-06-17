# Installing Kali Linux
 * Pull the image: `docker pull kalilinux/kali-rolling`
 * The run: `docker run --tty --interactive kalilinux/kali-rolling`
 * Upate Package: `apt update`
 * Install Packages: `apt -y install kali-linux-headless`

## Running Docker
### Basic Run Command:
```bash
docker run --tty --interactive kalilinux/kali-rolling
```

### Run Kali Docker container with port forwarding
```bash
docker run -it -p 3389:3389 --name kali-gui --privileged kalilinux/kali-rolling /bin/bash
```
or
```bash
docker run --interactive --tty -p 3389:3389 --name kali-gui --privileged kalilinux/kali-rolling /bin/bash
```
**Command Breakdown***
|Part|Meaning|
|---|---|
|`docker run`|Start a new container from an image|
|`-it` or `--interactive --tty`|`-it` combines two options: -i for **Interactive** mode which keeps STDIN open. And -t for Allocates a **pseudo-TTY** (like a terminal), so we can interact with the container's shell.|
|`-p 3389:3389`|**Port Mapping**: `-p HOST_PORT:CONTAINER_PORT` format. Maps port 3389 on the **host** to port 3389 inside the **container**|
|`--name kali-gui`|Gives our container a custome name: `kali-gui`. Helps us reference it easily later (e.g. `docker start kali-gui`)|
|`--privileged`|Grants the container **extra permissions**, including access to kernel features (like starting system services or GUI apps).|
|`kalilinux/kali-rolling`|The **Docker image** to use. This is the official **Kali Linux rolling release** base image from Docker hub.|
|`/bin/bash`|The **command** to run inside the container (in this case, Bash shell). After starting, we are dropped into an interactive Bash terminal.|

## Inside the container: Install Desktop Environment and XRDP
```bash
apt update && apt upgrade -y

# Install XFCE and XRDP
apt install -y xfce4 xfce4-goodies xrdp dbus-x11

# Set XFCE as default
echo "startxfce4" > ~/.xsession

# Start xrdp service
service xrdp start
```


