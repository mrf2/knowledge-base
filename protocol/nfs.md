# NFS - Network File System

**NFS (Network File System)** is a distributed file system protocol that allows a computer to access files over a network as if they were on its local storage.

## Summary
|Title|Meaning|
|---|---|
|Protocol|NFS (Network File System) Developed by Sun Microsystems.| 
|Platform Origin|UNIX/Linux|
|Primary Use|File Sharing between UNIX/Linux systems.|
|RFC-Define|RFC 1094, RFC 1813, RFC 3530, RFC 5661|
|Default Port|2049 (TCP/UDP)
|Security|Later versions (like NFSv4) support Kerberos authentication and ACLs.|

## How Does NFS Work?
 1. The Client will request to mount a directory from a remote host on a local directory just the same way it can mount physical device. The mount service will then act to connect to the relevant mount daemon using Remote Procedure Call (RPC).
 2. The server checks if the user has permission to mount whatever directoryhas been requested. It will then return a file handle which uniquely identifies each file and directory that is on the server.
 3. If someone wants to access a file using NFS, an RPC call is placed to NFSD (the *NFS daemon*) on the server. This call takes parameters such as:
    1. The file handle
    2. The name of the file to be accessed
    3. The user's, user ID
    4. The user's, group ID. 

*These are used in determining access rights to the specified file. This is want control user permissions, i.e. **read** and **write** on files.*


### Tools
|Name|Purpose|
|---|---|
|`nfs-common`|It is important to have this package installed on any machine that uses NFS, either as client or server. It includes programs such as: **lockd, statd, showmount, nfsstat, gssd, idmapd**, and **mount.nfs**.|


> Source: https://tryhackme.com/room/networkservices2
> Resource: https://docs.oracle.com/cd/E19683-01/816-4882/6mb2ipq7l/index.html
