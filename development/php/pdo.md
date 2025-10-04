# PDO - PHP Data Objects

**PDO (PHP Data Objects)**, is a database access layer that provides a uniform method for accessing mutiple databases in **PHP**. It offers a consistent interface for interacting with various databases systems, such as MySQL, PostgreSQL, Oracle, and others, as long as ia corresponding PDO driver is available. 

## Key features and benefits of using PDO include:
 * **Database Abstraction Layer: `PDO`** offers a data-access abstraction layer, meaning the same fudnctions can be used to issue queries and fetch data regardless of the underlying database system. This simplifies switching between different databases.

 * **Object-Oriented Syntax: `PDO`** utilizes an object-oriented approach, making database interactions more structured and manageable.

 * **Prepared Statements: `PDO`** supports prepared statements, which are crucial for preventing ***SQL injection vulneribilites***. Prepared statements separate the SQL query structure from the data, allowing for ***secure execution and efficient handling of repeated queries***.

 * **Error Handling: `PDO`** provieds robust error handling mechanisms, allowing developers to catch and manage database-related errors effectively, often by throwing **`PDOException` object**.

 * **Transaction Management: `PDO`** facilitates transaction management, enabling the execution of mutiple database operations as a single atomic unit, ensuring data integrity.

 * **Support for Various Databases: `PDO`** works with any database for which a **`PDO`** driver exists (e.g. **`PDO_MYSQL`, `PDO_PGSQL`, `PDO_SQLSRV`**).

To use **`PDO`**, database-specific driver must be installed and enabled in the PHP configuration. For example, to connect to a MySQL database, the `pdo_mysql` extension needs to be active.

### Baisc example of using PDO:
```php
<?php
try {
    $dsn = 'mysql:host=localhost;dbname=mydatabase`;    # DSN stands for Data Source Name
    $username = 'myuser';
    $password = 'mypassword';

    $pdo = new PDO($dsn, $username, $password);
    $pdo->setAttribute(PDO:ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

    // Prepare and execute a query
    $stmt = $pdo->prepare("SELECT name, email FROM users where id = "id");
    $stmt->bindParam(':id', $userId);
    $userId = 1;                                        # Example user ID
    $stmt->execute();

    // Fetch results
    $user = $stmt->fetch(PDO::FETCH_ASSOC);
    print_r($user);
} catch (PDOException $e) {
    echo "Database error: ".$e->getMessage();
}
?>
