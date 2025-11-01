# update-java-alternatives

The command **`update-java-alternatives`** is a Debian/Ubuntu utility that manages multiple installed Java versions (JDKs/JREs). It works on top of the `update-alternatives` system and helps us **switch between different Java installations easily**.

## Purpose
When we have multiple Java versions installed (e.g., OpenJDK 8, 11, 17), we can use:
```bash
update-java-alternatives
```
to list, configure, or switch between them system-wide.

It updates **all Java-related symbolic links** together:
 * `java`
 * `javac`
 * `jar`
 * `javadoc`
 * `jconsole`
 * etc.
So we don't have to manually run `sudo update-alternatives --config java` for each command.

### Location and Integration
The script lives in:
```bash
/usr/sbin/update-java-alternatives
```
and it's part of the `java-common` package.

It reads from:
```bash
/usr/lib/jvm/.java-*-jinfo
```
Each installed JDK/JRE package creates a `.jinfo` file that lists all the binaries (and man pages) associated with that **Java** version.

## Common Usage

 * List available Java alternatives:
```bash
sudo update-java-alternatives --list
```
 * Switch to a specific version:
```bash
sudo update-java-alternatives --set java-<version>
```
   * This updates **all Java-related symlinks** in **`/etc/alternatives/`**.
 * Restore all links to a given version (repair mode)
```bash
# If something got messed up (e.g. manual symlink edits):

sudo update-java-alternatives --auto

# It resets all Java-related alternatives automatically to the highest priority available.
```
