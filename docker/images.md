# Images

 * Images can be consider as ***templates*** for containers.
 * List of images: `docker images`

## Where Docker stores pulled images on host
 * Default path: **`/var/lib/docker`**
   * This is the the Docker's entire internal data root
 * Typical structure:
```bash
/var/lib/docker/
├── containers/          → running/stopped "containers" (logs, configs)
├── image/               → metadata about images
├── overlay2/            → actual filesystem "layers" (merged at runtime)
├── volumes/             → named volumes
├── network/             → network "settings" (bridge info)
├── tmp/                 → build cache, etc.
```
