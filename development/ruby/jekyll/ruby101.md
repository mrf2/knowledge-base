# Ruby 101

## Gems
Gems are code we can include in Ruby projects. Gems package specific functionality. We can share gems across mutiple projects or with other people. Gems cna perform action like:
 * Converting a **Ruby** object to **JSON**
 * Pagination
 * Interacting with APIs such as GitHub
### **Jekyll** is a gem. Many Jekyll plugins are also gems, including `jekyll-feed, `jekyll-seotag`, and `jekyll-archives`.

## Gemfile
A **Gemfile** is a list of gems used by our site. Every *Jekyll* site has a Gemfile in the main folder.

For a simple jekyll site it might look something like this:
```vim
source "https://rubygems.org"

gem "jekyll"

group :jekyll_plugins do
    gem "jekyll-feed"
    gem "jekyll-seo-tag"
end

## Bundler
**Bundler** is a gem that installs all gems in our **Gemfile**.

While we don't have to use **Gemfile** and **bundler**, it is highly recommended as it ensures we are running the same versions of Jekyll and its plugin across different environments.

Install Bundler using **gem install bundler**. We only need to install it once, not every time we create a new Jekyll project.

To install gems in our Gemfile using Bundler, we have to run the following command in the directory that has the Gemfile:
```vim
bundle install
bundle exec jekyll serve
```
---
To bypass **Bundler** if we are'nt using a **Gemfile**, we have to run the following `jekyll server`

> Source: https://jekyllrb.com/docs/ruby-101/#gems
