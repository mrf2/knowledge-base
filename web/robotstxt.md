# Robots.txt
This file must be served at the root directory - specified by the wevbserver itself. Looking at this file extension of **.txt**, its fairly safe to assume that it is a text file.

## Keyowrds
|Keywords|Meaning|
|---|---|
|User-agent|Specify the type of "Crawler" that can index the site (the asterisk being a wildcard, allowing **all "User-agents"**|
|Allow|Specify the directories for file(s) that the "Crawler" **can** index.|
|Disallow|Specify the directories or file(s) that the "Crawler" **cannot** index.|
|Sitemap|Provides a reference to where the sitemap is located (improves SEO)|

### Example:
```bash
Robots.txt
User-agent: *
Allow: /

Sitemap: http://mywebsite.example/sitemap.xml
```
**Meaning:**
 1. Any "Crawler" can index the site
 2. The "Crawler" is allowed to index the entire contents of the site
 3. The "Sitemap" is located at http://mywebsite.example/sitemap.xml
```

### Making certain "Crawlers" allow and others "Disallow"
```bash
Robots.txt
User-agent: Googlebot
Allow: /

User-agent: msnbot
Disallow: /
```
**Meaning:**
 1. The "Crawler" *Googlebot* is allowed to index the entire site ("Allow:/")
 2. The "Crawler" *msnbot* not allowed to index the site (Disallow: /")

### Preventing Files From Being Indexed
```bash
Robots.txt
User-agent: *
Disallow: /*.ini$

Sitemap: http://mywebsite.com/sitemap
```
**Meaning:**
 1. Any "Crawler" can index the site
 2. The "Crawler" cannot index **any** file that has the extention of **.ini** within any directory/sub-directory using ("$") of the site.
 3. The "Sitemap" is located at http://mywebsite.com/sitemap.xml



> Source: https://tryhackme.com/room/googledorking
