# Docker's Lifecycle Model
Every containers goes through **these following phases:**
 * **[IMAGE]** $\rightarrow$ **(docker run)** $\rightarrow$ **[CONTAINER CREATED + STARTED]**
 * $\rightarrow$ **can be [STOPPED]**
 * $\rightarrow$ **can be [STARTED again]**
 * $\rightarrow$ **can be [REMOVED]**

So **`docker run`** creates a ***new container from an image and starts it.***
**`docker start`** simply re-starts an ***already created one.***

# ⚙️  Core Commands
|Command|Purpose|Creates Container?|Runs Immediately?|Typical Use|
|---|---|---|---|---|
|`docker run`|**Create+start** a new container|✅ Yes|✅ Yes|First-time execution|
|`docker start`|**Restart** a stopped container|❌ No|✅ Yes|Resume previous container|
|`docker exec`|**Run a command** inside a running container|❌ No|✅ Yes|Extra commands inside an existing running container|
|`docker stop`|**Stop** a running container|❌ No|❌ No|Graceful shutdown|
|`docker rm`|**Remove** a container permanently|❌ No|❌ No|Cleanup|

## What `docker run` Really Does (Internally)
`docker run` has an **embedded default configuration** determined by the **image's metadata**, specifically the Dockerfile instructions `CMD` and `ENTRYPOINT`.

### Where these Defaults Come From
Every image has a built-in "what to run when started" defined in its **Dockerfile**.

Example:
```bash
FROM debian
CMD ["bash"]
```
That means:
 * If we run `docker run debian`, Docker executes `bash`.
 * If we run `docker run debian echo hi`, it *replaces* `bash` with `echo hi`.

That's why `echo hi` container exits immediately - we replaced the main command with something short-lived.

### How to Reconfigure `docker run` Behavior

#### Per-Container Configuration (Runtime)
We need to just add flags or a different command at runtime:

|We want|Command|Why it works|
|---|---|---|
|Keep container alive and interactive|`docker run -it debian`|Overrides default CMD (`bash`) to stay open|
|Keep container alive in background|`docker run -d debian tail -f /dev/null`|Keeps an infinite process as PID 1|
|Run with custom default shell|`docker run -it debian sh`|Explicitly use of `sh`|
|Automatically attach every time|`docker start -ai <container_name>`|Resumes interactively|

### Inspecting Defaults Behavior

#### A container's default behavior (command) is set at creation time
When we run:
```bash
docker run -dit --name mycontainer debian echo "hello world"
```
**Docker** does **two things:**
 1. Creates a new container from the image **`debian`**
 2. Sets its *default command* (called **ENTRYPOINT** and/or **CMD**) to run **`echo hello world`**

**That default command becomes part of that container's** ***immutable configuration***.

 * We can see it along with what defaults are set inside an image:
```bash
docker inspect mycontainer | grep -A3 Cmd
```
 * We'll get something like:
```json
"Cmd": [
    "echo",
    "hello world"
],
```
 * When this container stops, **Docker** keeps it with that same command.
 * So, if we later run:
```bash
docker start -ai mycontainer
```
 * it will just **re-run `echo hello world`** and exit again - because that's its configured command.

#### Why can't we simply **change** that command?
Docker **does not allow modifying the command (`Cmd`) of an existing container** directly.
 * That's because the container's **filesystem layer** and **metadata are** ***frozen*** once created.
 * Here are some **practical workarounds:**
   * **Create a new container from the same image:**
     * `docker run -it --name mycontainer-interactive debian sh`
   * **Use docker commit --change` to change the default command:**
     * This one is more advanced and powerful. We can create a new image **while changing its default command:**
     * `docker commit --change='CMD ["sh"]' mycontainer mycontainer-interactive`
     * Now when we run: `docker run -it mycontainer-interactive`
       * it will drop us into a shell prompt.
       * **✅ Pros:** reuses container's filesystem and sets new default command
       * **❌ Cons:** doesn't change the old container, but makes a new image version
