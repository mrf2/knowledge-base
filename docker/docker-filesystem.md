# Docker filesystem
Dokcer uses a **Union File System (UFS)** for containers, which allows multiple filesystems to be mounted in a hierarchy and to appear as a single filesystem.
 * The filesystem from the image has been mounted as a **read-only** layer, and any changes to the running container are made to a **read-write** layer mounted on top of this. 
 * Because of this, Docker only has to look at the topmost **read-write** layer to find the changes made to the running system.
