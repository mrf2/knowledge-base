# update-java-alternatives

The command **`update-java-alternatives`** is a Debian/Ubuntu utility that manages multiple installed Java versions (JDKs/JREs). It works on top of the `update-alternatives` system and helps us **switch between different Java installations easily**.

# Purpose
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
