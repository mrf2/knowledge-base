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
