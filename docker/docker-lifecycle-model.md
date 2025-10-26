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
We can see what defaults are set inside an image:
```bash
docker inspect debian | grep -A3 Cmd
```

We'll get something like:
```json
"Cmd": [
    "bash"
],
```
Here we can see what commands runs when we don't specify one.

