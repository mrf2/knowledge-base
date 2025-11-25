# Promises and Async Flow

 * A **Promise**=`future value`
   * (pending $\rightarrow$ fulfilled/rejected)
 * Use `async/await` for cleaner flow
 * **`Promises.all`** $\rightarrow$ run tasks in parallel
 * **`Promises.allSettled`** $\rightarrow$ continute even if some fail
 * Always handle errors (**`try/catch`**)

### Example code
```javascript
async function loadData() {
    try {
        const [users, posts] = await
        Promise.all ([
            fetch ('/users').then (r => r.json()),
            fetch('/posts').then (r => r.json())
        ]);
    } catch (e) {   /* handle error */ }
}
```

