# npm - node package manager

**`npm`** stands for **Node Package Manager** - it's the **default package manager for Node.js**.

## What it Does
**`npm`** helps us **install, manage, and share code packages (libraries or tools)** written for Node.js and JavaScript projects.

We can think of it as the **App Store** or **Play Store**, but for the **JavaScript code**.

## Main Uses

### 1. Install packages
Example:
```bash
npm install express
```
$\rightarrow$ installs the Express.js framework locally into our project.

### 2. Run project scripts
Example:
```bash
npm run build
```
$\rightarrow$ runs a custom command defined in our project's **`package.json`**.


#### 3. Manage dependencies
 * Keeps track of which libraries (and versions) our project uses in **`package.json`**.
 * Allows consistent setup across different computers with:
```bash
npm install
```
***(install everything listed in `package.json`)***.

### 4. Publish our own packages
We can share our own code with others on the ***npm registry***

## Installed Components
When we install something using **`npm`**, it goes into:
```bash
node_modules/
```
and references appear in:
```bash
package.json
package-lock.json
```

## Summary
|Purpose|Command Example|Description|
|---|---|---|
|Install a package|`npm install lodash`|Adds lodash to our project|
|Run a script|`npm run dev`|Runs the "dev" command defined in `package.json`|

