# `npm` vs `yarn` vs `pnpm`

|Feature|npm|yarn|pnpm|
|---|---|---|---|
|Developed By|Node.js team|Facebook (Meta)|Community (Zoltan Kochan)|
|Speed|Slower (improved in v7+)|Faster than older npm|Fastest overall|
|Storage system|Duplicates dependencies in each project|Similar to npm|Uses a **content-addressable store** (saves disk space)|
|Lockfile|**`package-lock.json`**|**`yarn.lock`**|**`pnpm-lock.yaml`**|
|Workspace (monorepo)|Yes (v7+)|Yes|Yes(most efficient)|
|Registry|npmjs.com|npmjs.com (same registry)|npmjs.com (same registry)|
|Command examples|**`npm install`**|**`yarn add`**|**`pnpm add`**|
|Disk usage|Larger|Moderate|Smallest (deduped)|

## Short Summary
 * **npm** = standard, simple, built-in with Node.js
 * **yarn** = faster & slightly more developer-friendly
 * **pnpm** = fastest, saves disk space, great for large projects
