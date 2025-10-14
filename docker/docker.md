# Docker
**Docker** is a command-line program, a background daemon, and a set of remote services that take a logistical approach to solving common software problems and simplifying our experience ***installing, running, publishing, and removing software***. It accomplishes this using a UNIX technology called containers.

The **Docker** platform has two distinct components:
 * **Docker Engine:** The **Docker Engine**, which is responsible for **Creating and Running containers**.
 * **Docker Hub:** The **Docker Hub**, a cloud service for distributing **Containers**.

## **`docker run`** command
 * The **`docker run`** command is responsible for launching containers.
 * Example: `docker run debian echo "Hello World"`
   * The argument **`debian`** is the name of the image we want to use - in this case, a stripped-down version of the Debian Linux Distribution.
   * Then Docker turns the image into a running container and executes the command we specified, `echo "Hello World", inside it.

### Syntax with example
 * `docker run -dit --name my-apache -p 8080:80 httpd:alpine`
 * The command explanation as below:
|Part|Purpose|
|---|---|
|`docker`|The **Docker** CLI command itset|
|`run`|Tells **Docker to create and start** a new container from an image|
|`-d`|**Detach mode** - runs the container in the background (does not attach terminal)|
|`-i`|**Interactive mode** - keeps **STDIN open** (usefull if we later `attach` or `exec` into the container)|
|`-t`|Allocates a **pseudo-TTY** (so commands feel like a terminal). Often combined with `-i` as `-it`|
|`--name my-apache`|Assigns a **custom name** to the container. Without this, **Docker** generates a random name (like `elegant_galileo`)|
|`-p 8080:80`|**Port mapping** - binds port 8080 of host OS \rightarrow$ to `80` port inside the **container**. So, we access it via `http://localhost:8080`|
|`httpd:alpine`|The **image name and tag**: use the `httpd` (Apache web server) image, with the `alpine` variant (a minimal Linux distro).|

### What Happens Internally
When we run that container the **first time:**
 1. Docker checks if the image  `httpd:alpine` exists locally
    * If not, it **downloads** it from Docker Hub.
 2. It **creates a new container** ( a writeable layer + metadata) named `my-apache`.
 3. It **starts** the container in the background.

### Servining host OS's local files
```
docker run -dit --name my-apache -p 8080:80 -v "$(pwd)":/usr/local/apache2/htdocs/ httpd:alpine
```
 * `"$(pwd)":/usr/local/apache2/htdocs/` $rightarrow$ `"$(pwd)" is the current working director of the Host OS, and /usr/local/apache2/htdocs/` $rightarrow$ /usr/local/apache2/htdocs/ httpd:alpine
