# Open Graph (OG)

**`Open Graph`** (OG) is a **metadata protocol** originally created by **Facebook.**

It lets any webpage describe its content in a structured way so that **social platforms, messaging apps, and crawlers** know **how to display a rich preview** when soemone shares the URL

## Purpose
Without Open Graph $\rightarrow$ a shared link shows random text or no image
With Open Graph $\rightarrow$ the prview has a consistent **title, description, thumbnail image,** etc.

## How it works
Our place `<meta>` tags in the `<head>` of our HTML page.

Example:
```html
<head>
    <meta property="og:title" content="My Content" />
    <meta property="og:description" content="A good content for developer" />
    <meta property="og:image" content="https://example.com/my-content.jpg" />
    <meta property="og:url" content="https://example.com/my-content" />
    <meta property="og:type" content="website" />
</head>

## Common OG properties
|Property|Meaning|
|`og:title`|Title shown in preview|
|`og:description`|Summary shown in preview|
|`og:image`|Thumbnail displayed when shared|
|`og:url`|Cononical URL|
|`og:type`|Type of content (`website`, `artifact`, `product`, etc.)|
|`og:locale`|Page locale (`en_US`, etc.)|

## Where it's used
 * Facebook
 * LinkedIn
 * Twitter now X (partly; Twitter Cards extend it)
 * Discord
 * WhatsApp
 * Telegram
 * Slack
 * Many SEO crawlers

## Main Ide
Open Graph = **"tell platforms exactly what to show when our link is shared."**
