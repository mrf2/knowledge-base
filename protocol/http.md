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
|**Headers**|Headers are made up of key-value pairs that provide extra information about HTTP message. They give instructions to both the client and the server handling the request or response. These headers cover all sort of things, like security, content types, and more, making sure everything goes smoothly in the communication.|
|**Empty Line**|The empty line is a little divider that separates the header from the body. It is essential because it shows where the headers stop and where the actual content of the message begins. Without the empty line, the message might get messed up, and the client or server could misinterpret it, causing errors.|
|**Body**|The body is where the actual data is stored. In a request, the body might include data the user wants to send to the server (like form data). In a response, it is where the server puts the content that the user requested (like a webpage or API data).|

## "Request Line" or "Start Line"
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

## Headers (Message Headers)
### Request Headers
Request Headers allow extra information to be conveyed to the web server about the request. 
**Some Common Request Headers**
|Name|Meaning|Examples|
|---|---|---|
|Host|Some we servers host muliple websites, so by providing the host headers select the appropriate one|`Host:localhost`|
|User-Agent|Software and version number, telling the web server browser's software version, it helps format the website properly for browser and also some elements of HTML, JavaScript, and CSS.|`User-Agent: Mozilla/5.0`|
|Referer|Indicates the URL from which the request came from.|`Referer: https://www.example.com/`|
|Content-Length|When sending data to a web server such as in a form, the content length tells the web server how much data to expect in the request.||
|Accept-Encoding|Tells the web server what types of compression methods the browser supports so the data can be made smaller for transmitting over the internet.||
|Cookie|Data sent to the server to help remember information.||
|Content-Type|Describes what type or format of data is in the request.|`Content-Type: application/json`|

### Common Response Headers
|Name|Meaning|
|---|---|
|Set-Cookie|Information to store which gets sent back to the web server on each request|
|Cache-Control|How long to store the content of the response in the browser's cache before it request again.|
|Content-Encoding|What method has been used to compress the data to make it smaller when sending it over the internet.|

## Body (Message Body)
### Request Body
In HTTP request such as POST and PUT, where data is sent to the web server as opposed to requested from the web server, that data is located inside the **HTTP Request Body**. The formatting of the data can take many forms, but some common ones are `URL Encoded`, `Form Data`, `JSON`, or `XML`.
 * **URL Encoded (application/x-www-form-urlencoded)**: A format where data is structured in pairs of key and value where (`key=value`). Multiple pairs are seperated by an (`&`) symbol, such as `key1=value1&key2=value2`. Special characters are percent-encoded.

```bash
Example
------------------------------
POST /profile HTTP/1.1
Host: example.com
User-Agent: Mozilla/5.0
Content-Type: application/x-www-form-urlencoded
Content-Length: 33

name=username&age=42&country=CN
```

 * **Form Data (multipart/form-data)**: Allows multiple data blocks to be sent where each block is separated by a boundary string. The boundary string is the defined header of the request itself. This type of formatting can be used to send binary data, such as when uploading files or images to a web server.

```bash
Example
------------------------------
POST /upload HTTP/1.1
Host: example.com
User-Agent: Mozilla/5.0
Content-Type: multipart/form-data; boundary=---WebkitFormBoundary<string>

---WebkitFormBoundary<string>
Content-Disposition: form-data, name="username"

username
---WebkitFormBoundary<string>
Content-Disposition: form-data; name="profile_pic", filename="username.jpg"
Content-Type: image/jpeg

[Binary Data Here representing the image]
---WebkitFormBoundary<string>--
```
 * **JSON (application/json)**: In this format, the data can be sent using JSON (JavaScript Object Notation) structure. Data is formatted in pairs of `name:value`. Mutiple pairs are separated by commas, all contained within curly braces {}.

```bash
Example
------------------------------
POST /api/user HTTP/1.1
Host: example.com
User-Agent: Mozilla/5.0
Content-Type: application/json
Content-Length: 62

{
    "name": "username",
    "age": 42,
    "country": "CN"
}
```

 * **XML (application/xml)**: In XML formatting, data is structured inside labels called tags, which have an opening and closing. These labels can be nested within each other. In the example below the opening and closing of the tags to send details about a user called username.

```bash
Example
------------------------------
POST /api/user HTTP/1.1
Host: example.com
User-Agent: Mozilla/5.0
Content-Type: application/xml
Content-Length: 80

<user>
    <name>username</name>
    <age>42</age>
    <country>CN</country>
</user>
```

## 2. HTTP Responses
When we interact with a web application, the server sends back an **HTTP response** to let us know whether our request was successful or somethng went wrong. These responses include a ***status code*** and a short explanation (called the **Reason Phrase**) that gives insigh into how the server handled our request.
### Status Line
The first line every HTTP response is called the **Status Line**. It gives us three pieces of info:
 1. **HTTP version:** This tells us which version of HTTP is being used.
 2. **Status Code:**  A three-digit number showing the outcome of our request.
 3. **Reason Phrase:** A short message explaining the status code in human-readable terms.

## 2. HTTP Status Codes and Reason Phrases
The **Status Code** is the number that tells us if the request succedded or failed, while the **Reason Phrase** explains what happened. These codes fall into five main categories:
 1. **Information Responses (100-199):** These codes mean the server has received part of the request and is waiting for the rest. It is a "keep going" signal.
 2. **Successfull Responses (200-299):** These codes mean everything worked as expected. The server processed the request and sent back the requested data.
 3. **Redirection Messages (300-399):** These codes tell us that the resource we requested has moved to different location, usually providing the new URL.
 4. **Client Error Responses (400-499):** These codes indicate a problem with that request. Maybe the URL is wrong, or we are missing some required info, like authentication.
 5. **Server Error Responses (500-599):** These codes mean the server encountered an error while trying to fulfil the request. These are usually server-side issues and not the client's fault.

|Code number|Meaning|Description|
|---|---|---|
|100-199|Information Response|These are sent to tell the client the first part of their request has been accepted and they should continue sending the rest of their request. These codes are no longer very common.|
|200-299|Success|This range of status codes is used to tell the client their request was successful.|
|200|OK|The request was completed successfully.|
|201|Created|A resource has been created (for example a new user or new blog post).|
|300-399|Redirection|These are used to redirect the client's request to another resource. This can be either to a different webpage or a different website altogether.|
|301|Moved Permanently|This redirects the client's browser to a new webpage or tells search engines that the page has moved somewhere else and to look there instead.|
|302|Found|Similar to **301** permanent redirect, but as the name suggests, this is only a temporary change and it may change again in the near future.|
|304|Not Modified|The **304 (Not Modified)** status code indicates that a conditional *GET* or *HEAD* request has been received and would have resulted in a *200 (OK)* response if it were not for the fact that the condition evaluated to false.|
|400-499|Client Errors|Used to inform the client that there was an error with their request.|
|400|Bad Request|This tells the browser that something was either wrong or missing in their request. This could sometimes be used if the web server resource that is being requested expected a certain parameter that the client didn't send.|
|401|Not Authorised|Currently not allowed to view this resource until authorized with web application, most commonly with a username and password.|
|403|Forbidden|Do not have permission to view this resource whether logged in or not.|
|404|Page not found|The page/resource requested does not exist.|
|405|Method Not Allowed|The resource does not allow this method request, for example, seding a GET request to resource/create-account when it was expecting a POST request instead.|
|500-599|Server Errors|This is received for errors happening on the server-side and usually indicate quite a major problem with the server handling the request.|
|500|Internal Service Error|The server has encountered some kind of error with the request that it doesn't know how to handle properly.|
|503|Service Unavailable|This server cannot handle the request as it's either overloaded or down for maintenance.|

### Response Headers
When a web server responds to an HTTP request, it includes **HTTP response headers,** which are basically key-value pairs. These headers provide important info about the reponse and tell the client (usually the browser) how to handle it.

### Required Response Headers
|Header|Description|Example|
|---|---|---|
|Date|This header shows the exact date and time when the response was generated by the server.|`Date: Thu, 16 Jun 2025 08:38:57 GMT`|
|Content-type|It tells the client what kind of content it's getting, like whether it is HTML, JSON, or something else. It also includes the character set, like UTF-8 to help the browser display it properly.|'Content-Type: text/html`|
|Server|This header shows what kind of server software is handling the request. It is good for debugging, but it can also reveal server information that might be useful for attackers, so many people remove or obscure this one.|`Server: Apache`|

### Other Common Response Headers
Besides the essential headers, there are other common headers that give additional instructions to the client or browser and help control how the response should be handled.
|Header|Description|Example|
|---|---|---|
|Set-Cookie|This one sends cookies from the server to the client, which the client then stores and sends back with future requests. To keep things secure, it need to make sure cookies are set with the `HttpOnly` flag (so they can't be accessed by JavaScript) and the `Secure` flag (so they are only sent over HTTPS).|Set-Cookie: sessionId=\<id_number\>|
|Cache-Control|This header tells the client how long it can cache the response before checking with the server again. It can also prevent sensitive info from being cached if needed|`Cache-Control: max-age=200`|
|Location|This one's used in redirection responses. It tells the client where to go next if the resource has moved. If users can modify this header during requests, it need to be careful to validate and sanitise it - otherwise, it could be end up with open redirect vulnerabilities, where attackers can redirect users to harmful sites.|`Location: /index.html`|

### Response Body
The **HTTP response body** is where the actual data lives - things like HTML, JSON, images, etc., that the server sends back to the client. To prevent **injection attacks** like *Cross-Site Scripting (XSS)*, it always need to sanitise and escape any data, ***especially user-generated content*** before including it in the response.

## Security Headers
HTTP Security Headers help improve the overall security of the web application by providing mitigations against attacks like *Cross-Site Scripting (XSS), Clickjacking*, and others. 

### Content-Security-Policy (CSP)
A **CSP** header is an additional security layer that can help mitigate aginst common attacks like *Cross-Site Scripting (XSS)*. Malicous code could be hosted on a separate website or domain and injected into the vulnerable website. A **CSP** provides a way for administrators to say what domains or sources are considered safe and provides a layer of mitigation to such attacks.

Example of CSP header:
```bash
Content-Security-Policy: default-src 'self'; script-src 'self' https://cdn.tryhackme.com; style-src 'self'
```
 * **default-src** - which specifies the default policy of self, which means only the current website.
 * **script-src** - which specifies the policy for where scripts can be loaded from, which is self along with scripts hosted on `https://cdn.tryhackme.com`
 * **style-src** - which specifies the policy for where **CSS** style sheets can be loaded from the current website (self)

### Strict-Transport-Security (HSTS)
The HSTS header ensures the web browsers will always connect over HTTPS. 

Example:
```bash
Strict-Transport-Security: max-age=12345678; includeSubDomains; preload
```
Here's a breakdown of the example HSTS header by directive:
 * **max-age** - This is the expiry time in seconds for this setting
 * **includeSubDomains** - An optional setting that instructs the browser to also apply this setting to all subdomains.
 * **preload** - This optional setting allows the website to be included in preload lists. Browsers can use preload list to enforce HSTS before even having their first visit to a website.


|Name|Description|
|---|---|
|Content-Security-Policy|Content Security Policy is an effective measure to protect your site from XSS attacks. By whitelisting sources of approved content, you can prevent the browser from loading malicious assets.|
|Referrer-Policy|Referrer Policy is a new header that allows a site to control how much information the browser includes with navigations away from a document and should be set by all sites.|
|Permissions-Policy|Permissions Policy is a new header that allows a site to control which features and APIs can be used in the browser.|
|Server|This Server header seems to advertise the software being run on the server but you can remove or change this value.|
|X-XSS-Protection|X-XSS-Protection sets the configuration for the XSS Auditor built into older browsers. The recommended value was "X-XSS-Protection: 1; mode=block" but you should now look at Content Security Policy instead.|
|X-Content-Type-Options|X-Content-Type-Options stops a browser from trying to MIME-sniff the content type and forces it to stick with the declared content-type. The only valid value for this header is "X-Content-Type-Options: nosniff".|
|X-Frame-Options|X-Frame-Options tells the browser whether you want to allow your site to be framed or not. By preventing a browser from framing your site you can defend against attacks like clickjacking.|
|Strict-Transport-Security|HTTP Strict Transport Security is an excellent feature to support on your site and strengthens your implementation of TLS by getting the User Agent to enforce the use of HTTPS.|



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
> Source for terminology: https://securityheaders.com
