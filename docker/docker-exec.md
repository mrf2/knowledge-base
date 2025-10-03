# `docker exec`

## How to enter inside the container?
### Using **`docker exec`** (*most common*)
 * List of all containers: **`docker container ls`** 
 * Then, **`docker exec -it <container_name_or_id> /bin/bash`** or **`docker exec -it <container_name_or_id> /bin/sh`**
   * **`-i`** $\rightarrow$ interactive
   * **`-t`** $\rightarrow$ allocate a pseudo-TTY
   * **`-/bin/bash`** $\rightarrow$ the shell inside the container
 * *This drops us into the containter just like SSH would*.
### Using **`docker exec`** repeatedly
Instead of "entering" permanently, we can run a single command inside:
```bash
docker exec <container_name_or_id> ls -l /
docker exec <container_name_or_id> cat /etc/os-release
```

## If we want SSH inside (*not recommended*)
 * Install OpenSSh server in your container (`apt install openssh-server` or osimilar).
 * Expose port **22** in **`Dockerfile`** or **`docker run - 2222:22 ...`**
 * Then SSH from host:
```bash
ssh -p 2222 user@locahost
```
