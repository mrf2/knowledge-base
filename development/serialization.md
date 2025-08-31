# Serialization


## Key Challenges in Serialization
 * **Endianness** (*big-endian vs little-endian*)
 * **Alignment and Padding** (*structs may differ on compilers*)
 * **Versioning** (*old data must work with new struct versions*)
 * **Efficiency** (*binary vs human-readable tradeoff*)
 * **Security** (*deserialization attacks if untrusted input*)

## Real-World Usage
 * **Databases:** BLOBS, query results, replication logs
 * **Networking:** DNS packets, TCP/IP headers, gRPC, RPC systems
 * **Storage:** Saving objects to disk, checkpoints, caches
 * **Inter-process communication (IPC)**

