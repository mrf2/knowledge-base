# descriptor
 * **Listeneing Descriptor:** The Listening descriptor serves as an end point 
for client connection request. It is typically created once and exists for the
lifetime of the server.
 * **Connected Descriptor:** The connected descriptor is the end point of the 
connection that is established between the client and the server. It is 
created each time the server accepts a connection request and exists only as
long as it takes server to service a client.
