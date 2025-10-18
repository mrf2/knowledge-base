# Docker Basic Commands

 * **`docker ps`**: This tell us a few details about the currently running containers. 
 * **`docker inspect <container_name> or <container_id>`**:
   * Example: **`docker inspect BrightMoon`**
 * **`docker diff <container_name> or <container_id>`**:
   * Example: `docker diff BrightMoon`


|Command|What It Does|Creates New Containers?|
|---|---|---|
|`docker run ...`|**Creates and starts a new container** from an image|Yes|
|`docker start ...`|Starts an **existing stopped container**|NO|
|`dockers restart ...`|Stops and restarts an existing container (in one step)|NO|
|`docker exec ...`|Runs a command ***inside a running*** container|NO|


## We can Think of It like below
 * **Images** are *blueprints* (like ISO files)
 * **Containers** are *instances* of those images (like a running or suspended VM)
 * **`docker run`** = "Create a new instance"
 * **`docker start`** = "Turn on an existing instance again"

## To rerun the same container, just start it again:
```bash
docker start -ai BrightMoon
```
Explanation:
 * `-a` = attach to **STDOUT/STDERR** (so we can see output)
 * `-i` = keep STDIN open (interactive mode)
 * This **reuses** the existing container - nothing new is created

## To run commands inside the already running container
```docker exec -it BrightMoon bash
```
$\rightarrow$ Opens a new shell session inside that running container

## To completely remove it
```bash
docker rm BrightMoon
```
$\rightarrow$ Then it disappears from **`docker ps -a`**

