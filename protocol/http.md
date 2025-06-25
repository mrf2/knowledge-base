# HTTP (Hyper Text Transfer Protocol)
Hypertext Transfer Protocol (HTTP) is the protocol that specifies how a web browser and a web server communicate. Web browser requests content from the server using the HTTP protocol. HTTP is the set of rules used for communicating with web servers for the transmitting of webpage data, whether that is HTML, Images, Videos, etc.

**HTTPS** is the secure version of HTTP. HTTPS data is encrypted so it not only stops people from seeing the data you are receiving and sending, but it also gives us assurances that we're talking to the correct web server and not something impersonating it.

## HTTP Messages
There are two types of HTTP messages:
 1. **HTTP Requests**: Sent by the ***user*** to trigger actions on the web application.
 2. **HTTP Responses**: Sent by the ***server*** in response to the user's request.

## 1. HTTP Requests
Format: `GET /user/login.html HTTP/1.1`
|Part/Portion|Meaning|
|---|---|
|`GET`|HTTP Method|
|`/user/login.html`|Path|
|`HTTP/1.1`|HTTP Version|

Each message follows a specific format that helps both the user and the server communicate smoothly.
|Type|Meaning|
|---|---|
|**Request Line** or **Start Line**|The start line is like the introduction of the message. It tells us what kind of message is being sent - whether it is a request from the user or response from the server. This lines also gives important details about how the message should be handled.|
|Headers|Headers are made up of key-value pairs that provide extra information about HTTP message. They give instructions to both the client and the server handling the request or response. These headers cover all sort of things, like security, content types, and more, making sure everything goes smoothly in the communication.|
|Empty Line|The empty line is a little divider that separates the header from the body. It is essential because it shows where the headers stop and where the actual content of the message begins. Without the empty line, the message might get messed up, and the client or server could misinterpret it, causing errors.|
|Body|The body is where the actual data is stored. In a request, the body might include data the user wants to send to the server (like form data). In a response, it is where the server puts the content that the user requested (like a webpage or API data).|

### Request Line
The **request line (or start line)** is the first part of an HTTP request and tells the server what kind of request it is dealing with. It has tree main parts
 1. HTTP method
 2. URL path, and
 3. HTTP version

### 1. HTTP Methods
The **HTTP method** tells the server what action the user wants to perform on the resource identified by the URL path.
|Method Name|Description|
|---|---|
|GET Request|This is used for ***getting*** or ***fetching*** information from a web server without making any changes. It it intended to exposint user data so we will not putting sensitive info like tokens or passwords in GET requests.|
|POST Request|This is used for submitting data to the web server and potentially creating new records|
|PUT Request|This is used for submitting data to a web server to update information|
|Delete Request|This is used for deleting information/records from a web server.|
|PATCH| Updates part of a resource. It is useful for making small changes without replacing the whole thing, but always validate the data to avoid inconsistencies.|
|HEAD|Works like GET but only retrieves headers, not the full content. It is handy for checking metadata without downloading the full response.|
|OPTIONS|Tells us what methods are available for a specific resource, helping clients understand what they can do with the server.|
|TRACE|Similar to OPTIONS, it shows which methods are allowed, often for debugging. Many servers disable it for security reasons.|
|CONNECT|Used to create a secure connection, like for HTTPS, It is not as common but is critical for encrypted communication.|

***Each of these methods has its own set of security rules. For example, PATCH requests should be validated to avoid inconsistencies, and OPTIONS and TRACE should be turned off it not needed to avoid possible security risks***.


### 2. URL - Uniform Resource Locator
Example: http://user:password@tryhackme.com:80/view-room?id=1#task3

Explanation:
|Parts|Example|Details|
|---|---|---|
|Scheme|http://|This instructs on what protocol to use for accessing the resource such as *HTTP, HTTPS, FTP*|
|User|user:password|Some services require authentication to log in, we can put a username and password into the URL to log in.|
|Host|tryhackme.com|The domain name or IP address of the server we wish to access|
|Port|:80|The Port that we are going to connect to, usually 80 for HTTP and 443 for HTTPS, but this can be hosted on any port between 1-65535.|
|Path|view-room|The file name or location of the resource we are trying to access|
|Query String|?id=1|The ***query string*** is the part of URL that starts with a question mark (?). Extra bits of information that can be sent to the requested path. For example, /blog?id=1 would tell the blog path that we wish to receive the blog article with the id of 1. Since users can modify these query strings, it's important to handle them securely to prevents attacks like ***injections***, where malicious code could be added.|
|Fragment|#task3|This is a reference to a location on the actual page requested. This is commonly used for pages with long content and can have a certain part of the page directly linked to it, so it viewable to the user as soon as they access the page. The ***fragment*** starts with a ***hash (#)*** symbol. Users can modify this too, so like with query strings, it's important to ***check and clean up any data here to avoid issues like injection attacks***.

### 3. HTTP Version
The **HTTP version** shows the protocol version used to communicate between the client and server. Common versions are:
|Version|Introduced Year|Description|
|---|---|---|
|HTTP/0.9|1991|The first version, only supported GET requests.|
|HTTP/1.0|1996|Added headers and better support for different types of content, improving caching.|
|HTTP/1.1|1997|Brought persistence connections, chunked transfer encoding, and better caching. It is still widely used today.|
|HTTP/2|2015|Introduced features like multiplexing, header compression, and prioritisation for faster performance.|
|HTTP/3|2022|Built on HTTP/2, but uses a new protocol (QUIC - Quick UDP Internet Connections) for quicker and more secure connections.|

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

## Interacting with HTTP
### Connecting through Telnet
```bash
Syntax
telnet <ip_address> <port_number>
```
**Getting 200-OK reponse from localhost**
1. **Open Telnet:**
```bash
telnet localhost 80
```
2. **Then type (and press Enter after each line):**
```bash
GET / HTTP/1.1
Host: localhost
```

```bash
Use of OPTIONS

OPTIONS / HTTP/1.1
Host: hostname

The server will response like below
...
Allow: HEAD,GET,POST,OPTIONS
Content-Length: 0
Content-Type: text/html
```


> Source: https://tryhackme.com/room/webapplicationbasics
