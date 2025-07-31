# `sed` - stream editor

`sed` stands for ***stream editor***, a powerful Unix utility used to *parse and transform text*, especially in pipeline. It reads input line-by-line, applies operations (like substitution, deletion, insertion, etc.), and writes the result to standard output.

### Basic Syntax
```bash
sed [options] 'script' [file...]

# If no file is given, "sed" reads from standard input.
```

## Most Common Commands
|Command|Description|
|---|---|
|`s/pattern/replacement/`|Substitute pattern with replacement *(first match in each line)*|
|`d`|Delete line|
|`p`|Print line (*useful with `-n` option)*|
|`a\ text`|Append text after the current line|
|`i\ text`|Insert text before the current line|
|`c\ text`|Change *(replace)* the line with the given text|
|`q`|Quit (stop processing)|
|`=`|Print the current line number|
|`{}`|Group commands|


## Examples
|Case|Command|
|---|---|
|Printing specific line numbers|`sed -n '22, 49p' filename.txt`|

## Single-shot in `sed`
We can break out of the stream **after the first match ends**, like this
```bash
sed -n '/struct hostent/,/};/p; /};/q' /user/include/netdb.h
```
This tells `sed`:
 * Start printing from `struct hostent` to `};`
 * When we hit `};` **print that line and then immediately quit**
*This simulates a single-shot range, even though `sed` internally would continue otherwise*.

