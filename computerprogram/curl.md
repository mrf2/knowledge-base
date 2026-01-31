# curl

## Curl options
|flag or switch|Meaning|
|---|---|
|`-H, --header <header>`| Extra header to use when getting a web page.|
|`-X, --request <command>`|Specifies a custom dequest method to use when communicating with the HTTP server. Example `GET`, `POST`, `PUT`, `DELETE`, etc.|
|`-A, --user-agent <agent string>`|Specify the User-Agent strign to send to the HTTP server. The `-H` also do the same thing. `-H "User-Agent:Agent-Name"`|

Testing which HTTP version is negotiated when connecting to server:
```bash
curl -I -v http://localhost
```

```bash
curl -v http://localhost
```
