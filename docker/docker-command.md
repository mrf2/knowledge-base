# Docker Basic Commands

 * **`docker ps`**: This tell us a few details about the currently running containers. 
 * **`docker inspect <container_name> or <container_id>`**:
   * Example: **`docker inspect BrightMoon`**
 * **`docker diff <container_name> or <container_id>`**:
   * Example: `docker diff BrightMoon`
 * **`docker logs <container_name> or <container_id>`**:
   * Example: `docker logs BrightMoon`

## `docker ps`

## `docker inspect`
The `docker ps -a` commanmd gives us the list of all containers in the host system. The `docker inspect` let us know more information about a container by running `docker inspect` command with the ***name*** or ***ID*** of the container:
 * `docker inspect BrightMoon`
   * There is a lot of valuable output here, but it's not exactly easy to parse. We can use **`grep`** or the **`--format`** argument to filter for the information we are intersted in. For example:
     * **`docker inspect BrightMoon | grep IPAddress`**
     * **`docker inspect --format {{.NetworkSettings.IPAddress}} BrightMoon`**

### The `docker inspect --format {{.NetworkSettings.IPAddress}} BrightMoon` Command Context:
When we run this **`docker inspect --format {{.NetworkSettings.IPAddress}} BrightMoon`** command, we're telling Docker: Inspect the container named **`BrightMoon`**, and instead of printing ***everything*** as **JSON**, format the output using this **Go-style template**.

So, the **`--format`** flag lets us control what **`docker inspect`** prints, using **Go's built-in text templating system**.

## `docker diff`
The `docker diff` command is used to see the changes have been made in the running container.
 * **`A`** - File or directory added
 * **`C`** - File or directory changed
 * **`D`** - File or directory deleted

### `docker diff` example
`docker diff BrightMoon`



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

