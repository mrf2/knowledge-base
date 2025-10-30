# Filesystem

 * **(AUFUS - AnotherUnionFS): AUFS** is a union filesystem that allows multiple directories to be mounted on top of each other, presenting a single merged view. It was a popular storage driver for Docker in earlier versions, enabling the layering of container images.

 * **Overlay/Overlay2: OverlayFS** is a modern union filesystem included in the Linux kernel. If functions similarly to AUFS by merging multiple filesystem layers into one. Overlay2 is an enhanced version offering better performance and inode utilization. It is the recommended and default storage driver for Docker on most modern Linux distribution.

 * **Devicemapper: Devicemapper** is a Linux kernel framework for mapping physical block devices onto higher-level virtual block devices. It forms the foundation for various storage technologies, including ***Logical Volume Manager (LVM)*** and software ***RAID***. As a Docker storage driver, it utilizes block-level storage, which can offer performance advantages for write-heavy workloads compared to file-level union filesystems.

 * **BTRFS (B-tree File System): BTRFS** is a ***copy-on-write (CoW)*** filesystem for Linux that aims to address limitations of traditinal filesystems and offer advanced features like snapshots, checksumming, and integrated volume management. It can be used as a Docker storage dirver, leveraging its CoW capabilites for efficient image and container management.

 * **ZFS (Zettabyte File System): ZFS** is an advanced filesystem and logical volume manager known for its data integrity features, snapshots, cloning, and scalability. Originally developed by Sun Microsystems, it has been ported to Linuxand can also be used as a Docker storage drive, particulary suitable for high-density and enterprise-grade storage requirements.
