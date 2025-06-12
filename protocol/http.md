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

## HTTP Status Codes
|Code number|Meaning|Description|
|---|---|---|
|100-199|Information Response|These are sent to tell the client the first part of their request has been accepted and they should continue sending the rest of their request. These codes are no longer very common.|
|200-299|Success|This range of status codes is used to tell the client their request was successful.|
|200|OK|The request was completed successfully.|
|201|Created|A resource has been created (for example a new user or new blog post).|
|300-399|Redirection|These are used to redirect the client's request to another resource. This can be either to a different webpage or a different website altogether.|
|301|Moved Permanently|This redirects the client's browser to a new webpage or tells search engines that the page has moved somewhere else and to look there instead.|
|302|Found|Similar to **301** permanent redirect, but as the name suggests, this is only a temporary change and it may change again in the near future.|
|400-499|Client Errors|Used to inform the client that there was an error with their request.|
|400|Bad Request|This tells the browser that something was either wrong or missing in their request. This could sometimes be used if the web server resource that is being requested expected a certain parameter that the client didn't send.|
|401|Not Authorised|Currently not allowed to view this resource until authorized with web application, most commonly with a username and password.|
|403|Forbidden|Do not have permission to view this resource whether logged in or not.|
|404|Page not found|The page/resource requested does not exist.|
|405|Method Not Allowed|The resource does not allow this method request, for example, seding a GET request to resource/create-account when it was expecting a POST request instead.|
|500-599|Server Errors|This is received for errors happening on the server-side and usually indicate quite a major problem with the server handling the request.|
|500|Internal Service Error|The server has encountered some kind of error with the request that it doesn't know how to handle properly.|
|503|Service Unavailable|This server cannot handle the request as it's either overloaded or down for maintenance.|

## Headers
### Common Request Headers
|Name|Meaning|
|---|---|
|Host|Some we servers hsot muliple websites, so by providing the host headers select the appropriate one|
|User-Agent|Software and version number, telling the web server browser's software version, it helps format the website properly for browser and also some elements of HTML, JavaScript, and CSS.|
|Content-Length|When sending data to a web server such as in a form, the content length tells the web server how much data to expect in the request.|
|Accept-Encoding|Tells the web server what types of compression methods the browser supports so the data can be made smaller for transmitting over the internet.|
|Cookie|Data sent to the server to help remember information.|

### Common Response Headers
|Name|Meaning|
|---|---|
|Set-Cookie|Information to store which gets sent back to the web server on each request|
|Cache-Control|How long to store the content of the response in the browser's cache before it request again.|
|Content-Encoding|What method has been used to compress the data to make it smaller when sending it over the internet.|

