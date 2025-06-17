# Enum4Linux

Enum4linux is a tool used to enumerate **SMB** shares on both Windows and Linux systems. It is basically a wrapper around the tools in the Samba package and makes it easy to quickly extract information from the target pertaining to SMB.

 * Enum4linux is a tool for enumerating information from Windows and Samba systems.
 * It is written in Perl and is basically a wrapper around the Samba tools *smbclient, rpclient, net and nmblookup*.

## Usage
```bash
./enum4linux.pl [options] ip
```

## Options
|Switch|Meaning|
|---|---|
|-U|get userlist|
|-M|get machine list\*|
|-S|get sharelist|
|-P|get password policy information|
|-G|get group and member list|
|-d|be detailed, applies to -U and -S|
|-u user|specify usrname to use (default "")|
|-p pass|specify password to use (default "")|
|-a|Do all simple enumeration (-U -S -G -P -r -o -n -i).|

> Source Code: https://github.com/CiscoCXSecurity/enum4linux?tab=readme-ov-file
