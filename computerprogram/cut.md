# cut - remove sections from each line of files

## SYNOPSIS
```bash
cut OPTION... [FILE]...
```

## DESCRIPTION
 * Print selected parts of lines from each FILE to standard output.
 * With no FILE, or when FILE is -, read standard input.
 * Mandatory arguments to long options are mandatory for short options too.

## Why `cut` is used practically
 * **Purpose-built** for field extraction by delimeter (for example demited by `:`)
 * **Very readable:** anyone familar with Unix pipelines can quickly understand `cut -d: -f1`
 * Fast and lighweight
 * No shell quoting/escaping issues
```bash

       -b, --bytes=LIST
              select only these bytes

       -c, --characters=LIST
              select only these characters

       -d, --delimiter=DELIM
              use DELIM instead of TAB for field delimiter

       -f, --fields=LIST
              select only these fields;  also print any line that contains no delimiter character, unless the -s option is specified

       -n     (ignored)

       --complement
              complement the set of selected bytes, characters or fields

       -s, --only-delimited
              do not print lines not containing delimiters

       --output-delimiter=STRING
              use STRING as the output delimiter the default is to use the input delimiter

       -z, --zero-terminated
              line delimiter is NUL, not newline

       --help display this help and exit

       --version
              output version information and exit

       Use  one,  and  only  one of -b, -c or -f.  Each LIST is made up of one range, or many ranges separated by commas.  Selected input is
       written in the same order that it is read, and is written exactly once.  Each range is one of:

       N      N'th byte, character or field, counted from 1

       N-     from N'th byte, character or field, to end of line

       N-M    from N'th to M'th (included) byte, character or field

       -M     from first to M'th (included) byte, character or field

AUTHOR
       Written by David M. Ihnat, David MacKenzie, and Jim Meyering.

REPORTING BUGS
       GNU coreutils online help: <https://www.gnu.org/software/coreutils/>
       Report any translation bugs to <https://translationproject.org/team/>

COPYRIGHT
       Copyright © 2023 Free Software Foundation, Inc.  License GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.
       This is free software: you are free to change and redistribute it.  There is NO WARRANTY, to the extent permitted by law.

SEE ALSO
       Full documentation <https://www.gnu.org/software/coreutils/cut>
       or available locally via: info '(coreutils) cut invocation'
```
