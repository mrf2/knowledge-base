# JMeter

## Test Plan
**A Test Plan = a container** that holds everything required to simulate user behavior.

JMeter loads our entire configuration from the single file (`.jmx`).

It could be think of as our **project file**.

## Thread Group
**What it is:** 
A Thread Groud defines **HOW MANY USERS** JMeter  will simulate and **how fast they start**.

**What goes inside:**

**Industry-standard settings:**
 * **Number of Threads (User):** 500
 * **Ramp-up Period:** 100 seconds
 * **Loop Count:** 1 (or repeat)

**How to add:**
Right-click **Test Plan** $\rightarrow$ Add $\rightarrow$ Threads $\rightarrow$ *Thread Group*

## HTTP REQUEST DEFAULTS
**What it is:**
A place to define **common settings** for all HTTP requests so we do not to repeat them.

**We typically put:**
 * Server Name (example: api.example.com)
 * Port Number (80 or 443)
 * Protocol (http/https)

**Why it is needed:**
Without this, every request must repeat the domain manually.

**How to add:**
Thread Group $\rightarrow$ Add $\rightarrow$ Config Element $\rightarrow$ **HTTP Request Defaults**


## HTTP HEADER MANAGER
**What it is:**
A list of HTTP headers authomatically attached to every request.

**Typical headers we set:**
 * `Content-Type: application/json`
 * `Accept: application/json`
 * `Authorizatoin: Bearer ${token}` (after login)

**Why it is needed:**
To simulate real API usage $\rightarrow$ APIs often require specific headers.

**How to add:**
Thread Group $\rightarrow$ Add $\rightarrow$ Config Element $\rightarrow$ **HTTP Header Manager**


## CSV DATA SET CONFIG
**What it is:**
Allows JMeter to read **test data** from a CSV file

**Example CSV (users.csv):**
```bash
username1,password1
username2,password2
username3,password3
```

**Why it is needed:**
For login, each virtual user should ideally use a unique username to avoid:
 * account lockouts
 * sessions getting overwritten
 * server rejecting repeated login attemmpts

**How to add:**
Thread Group $\rightarrow$ Add $\rightarrow$ Config Element $\rightarrow$ **CSV Data Set Config**


## SAMPLER LOGIN
**What it is:**
A sampler sends an actual HTTP request

**Example login request:**
 * Method: POST
 * URL: /api/login
 * Body:
```
{
    "username" : "${username}",
    "password" : "${password}"
}
```
The ${username} and ${password} values come from the CSV file.

**Why this step exists:**
Most application require authentication to access further pages.

**How to add:**
Thread Group $\rightarrow$ Add $\rightarrow$ Sampler $\rightarrow$ **HTTP Request**


## POST-PROCESSOR - JSON Extractor
**What it is:**
Extract dynamic data from the response (usally JSON)

**Typical extraction:**
We login $\rightarrow$ server returns a token:
```json
{
    "token": "abcdef123456789"
}
```
We must extract `"abcdef123456789"` and store it into a variable.

**How JSON Extractor works:**
 * We tell it: "Find 'token' in response JSON"
 * It stores it in a variable like `${token}`

**Why we need this:**
Most authenticated APIs use a token or session ID
--without extracing it, we cannot call the next authenticated endpoints.

**How to add:**
Right-click the Lgon Sampler $\rightarrow$ Add $\rightarrow$ Post Processor $\rightarrow$ **JSON Extractor**

## SAMPLER - Dashboard, Search, Create, Logout
Each of these is simply another **HTTP Request Sampler.**

We configure:
 * HTTP method (GET/POST/PUT/DELETE)
 * Endpoint URL (e.g. `/api/dashboard`)
 * Headers (most inherited from Header Manager)
 * Body (if POST/PUT)A
 * Params (if GET query parameters)
Each sampler represents **one user action**.

## ASSERTIONS
**What it is:**
Assertions verify the response is correct.

**Typical checks:**
 * Response Code = 200
 * Response Body contains expected text
 * JSON path contains specific value
 * Response time < X milliseconds

Assertion prevent false positives when server returns:
 * 500 internal server error
 * 403 unauthorized
 * Empty response
 * HTML error page instead of JSON

**How to add:**
Right click any sampler $\rightarrow$ Add $\rightarrow$ Assertions $\rightarrow$ **Response Assertion**


## LISTENERS
**What it is:**
Listeners display results of tests.

Examples:
 * View Results Tree
 * Summary Report
 * Aggregate Report
 * Graph Results

**Important rule:**
Listeners are for **debugging only,** for for real execution with 500 users.

During debugging, we eanable:
 * View Results Tree
 * Summpary Report

During real load test, we disable all heavy listeners.

The real test should be run with:
```bash
jmeter -n -t testplan.jmx -l result.jtl
```

## VISUAL SUMMARY
```bash
Thread Group = how many users
┃
┣--CSV Data Set Config = usernames/passwords
┃
┣--HTTP Header Manager = common headers
┃
┣--HTTP Request Defaults = base URL
┃
┣--Login Request (Sampler)
┃     |
┃     ---> JSON Extractor = extract token
┃
┣--Dashboard Request
┃
┣--Search Request
┃
┣--Create/Update Request
┃
┣--Logout Request
┃
┣--Assertions = Verify correctness
┃
└--Listeners = see test output
```
