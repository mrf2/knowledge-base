# Burp Suite
**Burp Suite** is an integrated platform for performing security testing of web applications. It includes various tools for scanning, fuzzing, intercepting, and analysing web traffic. It is used by security professionals worldwide to find and exploit vulnerabilities in web applications.

## Burp Suite Proxy

## Burp Suite Repeater
**Burp Suite** Repeater enables us to modify and resend intercepted requests to a target of our choosing. It allows us to take requests captured in the Burp Proxy and maintain them, sending them repeatedly as needed. Alternatively, we can manually create requests from scratch, similiar to using a command-line tool like cURL. The ability to edit and resend requests multiple times make Repeater invaluable for manual exploitation and testing endpoints.

The major sections of Burp Suite Repeater's GUI interface:
 1. **Request List**: Located at the top left of the tab, it displays the list of Repeater requests. Multiple requests can be managed simultaneously, and each new request sent to Repeater will appear here.
 2. **Request Controls**: Positioned directly beaneath the request list, these control allow us to send a request, cancel a hanging request, and navigate through the request history.
 3. **Request and Response View**: This section displays the **Request** and **Response** views. We can edit the request in the Request view and then forward it, while the corresponding response will be shown in the Response view.
 4. **Inspector**: The Inspector allows us to analyze and modify requests in a more intuitive manner than using the raw editor.
 5. **Target**: The **Target** field specifies the *IP address* or *domain* to which requests are sent. When requests are sent to Repeater from other Burp Suite components, this field is automatically populated.


> Source: https://tryhackme.com/room/burpsuiterepeater
