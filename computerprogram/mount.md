# mount - mount a filesystem
All files accessible in a Unix system are arranged in one big tree, the file hierarchy, rooted at /. These files can be spread out over several devices. The **mount** command servers to attach the filesystem found on some device to the big file tree. Conversy, the **unmount** will detach it again. The filesystem is used to control how data is stored on the device or provided in a virtual way by network or other services.

The standard form of the **mount** command is:
```bash
mount -t type device dir
```
### Explanation of: sudo mount -t nfs IP:<share_name> /tmp/mount -nolock
|command/switch/options|Meaning|
|---|---|
|sudo|Run as root|
|mount|Execute mount command|
|-t nfs|Type of device to mount, then specifying that it's NFS|
|IP:\<share_name\>|The IP Address of the NFS server, and the name of the share we wish to mount|
|-nolock|Specfies not to use Network Lock Manager (NLM) Protocol locking|
