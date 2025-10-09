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
