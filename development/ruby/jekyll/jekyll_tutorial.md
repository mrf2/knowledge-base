# Jekyll Step by Step Tutorial
---
## 1. Setup

### Installation
Jekyll is a Ruby gem. ***At first, we have to install Ruby on our machine***
 * Install Ruby and other prerequisite:
```vim
sudo apt install ruby-full build-essential zlib1g-dev
```
Aoid installing RubyGems package (called gems) as the root user. Instead, set up a gem installation directory for the user account. The following commands will add environment variables to our `~/.bashrc` file to configure the gem installation path:
```vim
echo `# Install Ruby Gems to ~/gems' >> ~/.bashrc
echo 'export GEM_HOME="$HOME/gems"' >> ~/.bashrc
echo 'export PATH="$HOME/gems/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```
 * Install **Jekyll** from the termival
```vim
gem install jekyll bundler
```
 * Create a new **Gemfile** to list project's dependencies:
```vim
bundle init
```
 * Edit the **Gemfile** in a text editor and add jekyll as a dependency:
```vim
gem "jekyll"
```
 * Run **bundle** to install jekyll for the project
---
### Create a site
Let's add first file. Create **index.html** in `root` with the following content:
```html
<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title>Home</title>
    </head>
    <body>
        <h1>Hello World!</h1>
    <body>
</html>
```

---
### Build
***Since Jekyll is a static site generator, it has to build the site before we can view it. The following commands to build you site:***
 * `jekyll build` - Builds the site and outputs a static site to a directory called `_site`.
 * `jekyll server` - Does `jekyll build` and runs it on a local web server at `http://localhost:4000`, rebuilding the site any time you make a change.

> When developing a site, it need to used `jekyll serve`. To force the browser to refresh with every change, use `jekyll serve --livereload`. If there's a conflict or we'd like Jekyll to serve our development site at a different URL, we need to use `--host` and `--port` arguments, as described in the [server command options.](https://jekyllrb.com/docs/configuration/options/#serve-command-options)

> The version of the site that `jekyll server` builds in `_site` is not suited for deployment. Links and asset URLs in sites created with `jekyll server` will use `https://localhost:4000` or the value set with command-line configuration, instead of the values set in our site's [configuration file](https://jekyllrb.com/docs/configuration/).

 * Run `jekyll server` and to to `http://localhost:4000` in the browser. There will be "Hello World!"
