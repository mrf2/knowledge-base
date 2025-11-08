# GraphQL
**GraphQL** is a **query language** and **runtime** for **APIs** - originally developed by Facebook in 2012 and open-sourced in 2015. It provides a flexible and efficient alternative to REST for retrieving and manipulating data from servers.

## 1. What GraphQL is
**GraphQL = Query Language + Server Runtime**
 * **Query Language:** A syntax for clients to describe *exactly* what data they need.
 * **Runtime:** The server-side component that executes those queries on our data sources (database, microservice, etc.).

Unlike **REST** (where we have multiple endpoints like `/users`, `/posts`, `/comments`), in **GraphQL** there's usually **only one endpoint**, and clients specify *what they want in the request body*.

## 2. Core Components
|Concept|Description|Example|
|---|---|---|
|Schema|Defines the types of data available and what queries/mutations are supported.|`type user { id: ID, name: String }`|
|Query|A read operation (like HTTP GET).|`{user(id:1) { name }}|
|Mutation|A write operation (like POST/PUT/DELETE).|`{mutation { addUser (name:"Tom") { id } }`|
|Resolver|Functions that tell GraphQL how to fetch or compute a field's data.|Resolver for `user(id)` gets data from database|
|Subscription|Real-time updates via WebSockets.|`subscription { newMessage { text } }`|

## 3. How It Works (Conceptually)
Here's the lifecycle of a GrphQL request:
```bash
client → GraphQL Server → Database or APIs
  ↓
Query →  Parse  → Validate → Execute → Respond
```
