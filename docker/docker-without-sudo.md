# Run Docker without `sudo`

 * Check the status of **`/var/run/docker.sock`** by issuing **`ls -la /var/run/docker.sock`**
 * **`sudo usermod -aG docker $USER`**
   * `-a' $\rightarrow$ **append**
   * `-G` $\rightarrow$ **group**
   * `docker` $\rightarrow$ is the group name, which is **docker**

```
docker: permission denied while trying to connect to the Docker daemon socket at unix:///var/run/docker.sock: Head "http://%2Fvar%2Frun%2Fdocker.sock/_ping": dial unix /var/run/docker.sock: connect: permission denied

Run 'docker run --help' for more information
```

