# Template Engine

## What is a Template Engine?
A **template engine** is a system that takes:
 1. A **template string** (with placeholders), and
 2. Some **data**,
then merges them to prodduce **text output**. We can think the process like below:
```text
Template + Data = Final Text
```
For Example:
```go
Template: "Hello, {{.Name}}!}"
Data: { Name: "BrightMoon" }

Output: "Hello, BrightMoon!"
```

### How Docker Uses Go Templates Internally
**Docker** is wirtten in Go, and it uses Go's templating engine to let users cutomize output in commands like **`docker inspect`, docker ps --format`**, etc..

When we run:
```bash
docker inspect --format "{{.NetworkSettings.IPAddress}}" container_name
```
Here's what happens internally:
 1. Docker collects inspection data about the container as a **Go styruct** (in memory).
For example:
```go
type Container struct {
	ID string
	Name string
	NetworkSettings struct {
		IPAddress string
	}
}
```
 2. Docker then parses our template string **`{{.NetworkSettings.IPAddress}}``** using Go's **`text/template`** parser.
 3. It executes the template against that **Go struct**.
 4. It prints the result (the actual IP address string).

## What **`{{.NetworkSettings.IPAddress}}`** Means
Inside the **`{{ ... }}`** braces:
 * **`.`** means "the current data object"
