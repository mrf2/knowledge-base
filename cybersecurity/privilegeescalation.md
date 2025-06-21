# Privilege Escalation

## Through Exploiting NFS
 * If we have a low **privilege** shell on any machine and we found that a machine has an NFS share we might be able to use that to escalate privileges, depending on how it is configured.

**root_suash:** `root_squash` is a security feature in **NFS (Network File System)** that prevents *remote root users* from having **root (UID 0)** privileges on the **NFS server**. It does this by **"squashing" (mapping/downgrading)** the root user's identify to a **non-privileged user,** typically `nobody` or `nfsnobody`. However, if `root_squash` is turned off, it can allow the creatio of SUID bit files, allowing a remote user root access to the connected system.

**SUID** means that the file or files can be run with the permissions of the file(s) owner/group. *In this case, as the super-user. It can leverage this to get a shell with these privileges.*

### How It Works?
 * On NFS client: User is `root` (UID 0).
 * On NFS server: With `root_squash`, any request from UID 0 is *treated as if it came from UID 65534* (`nobody`).
 * The client still access the share - but *only with very limited permissions*.
 * Example: `/etc/exports`:
```bash
/var/nfsshare 192.168.1.0/24(rw,sync,root_squash)

1. It exports "/var/nfsshare" to the subnet
2. Applies "root_squash" to remote root users
```
Related Export Options
|Option|Description|
|---|---|
|root_squash|**Default**. Squashes remote root to `nobody`.|
|no_root_squash|Dangerous. Remote root retains root access.|
|all_squash|Squashes **all users** to `nobody`, not just root|
|anonuid=\<UID\>|Set a custom UID for squashed users (instead of `nobody`).|
|anongid=\<GID\>|Set a custom GID fro squashed users.|

## Process
1. Gain Low Privilege Shell (`ssh` into localuser)
2. Upload Bash Executable to the NFS share (`cp ~/Downloads/bash /tmp/mount/nfs_share`)
3. Set SUID Permissions Through NFS Due to Misconfigured Root Suash (`sudo chown root bash`)
4. Login through SSH (`ssh` into localuser) 
5. Execute SUID Bit Bash Executable (`sudo chmod +[permission]bash`)
6. The **ROOT ACCESS** (`./bash -p`)

> Source: https://tryhackme.com/room/networkservices2
