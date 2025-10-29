# Dockerfile

A **`Dockerfile`** is simply a text file that contains a set of steps that can be used to create a **Docker** image. 

## Example of Dockefile
```bash
FROM debian:bookworm

RUN apt-get update && apt-get install -y vim
```
 * The **`FROM`** instruction specifies the **base image to use**.
   ** Here **`debian`** with the version tag **`bookworm`**.
 * All **Dockerfiles** must have a **`FROM`** instruction as the first noncomment instruction. **`RUN`** instructions sepcify a shell command to execute inside the image. In this case, we are just installing vim program.

## **`docker build`** command
Now we will build the image by running `docker build` command inside the same directory:
```bash
docker build -t testrepo/mydockerimage .
```

