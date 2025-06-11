# HTTP (Hyper Text Transfer Protocol)
Hypertext Transfer Protocol (HTTP) is the protocol that specifies how a web browser and a web server communicate. Web browser requests content from the server using the HTTP protocol. HTTP is the set of rules used for communicating with web servers for the transmitting of webpage data, whether that is HTML, Images, Videos, etc.

## HTTPS
HTTPS is the secure version of HTTP. HTTPS data is encrypted so it not only stops people from seeing the data you are receiving and sending, but it also gives us assurances that we're talking to the correct web server and not something impersonating it.

## URL - Uniform Resource Locator
Example: http://user:password@tryhackme.com:80/view-room?id=1#task3

Explanation:
|Parts|Example|Details|
|---|---|---|
|Scheme|http://|This instructs on what protocol to use for accessing the resource such as *HTTP, HTTPS, FTP*|
|User|user:password|Some services require authentication to log in, we can put a username and password into the URL to log in.|
|Host|tryhackme.com|The domain name or IP address of the server we wish to access|
|Port|:80|The Port that we are going to connect to, usually 80 for HTTP and 443 for HTTPS, but this can be hosted on any port between 1-65535.|
|Path|view-room|The file name or location of the resource we are trying to access|
|Query String|?id=1|Extra bits of information that can be sent to the requested path. For example, /blog?id=1 would tell the blog path that we wish to receive the blog article with the id of 1.|
|Fragment|#task3|This is a reference to a location on the actual page requested. This is commonly used for pages with long content and can have a certain part of the page directly linked to it, so it viewable to the user as soon as they access the page.|

## HTTP Methods
|Method Name|Description|
|---|---|
|GET Request|This is used for getting information from a web server.|
|POST Request|This is used for submitting data to the web server and potentially creating new records|
|PUT Request|This is used for submitting data to a web server to update information|
|Delete Request|This is used for deleting information/records from a web server.|

